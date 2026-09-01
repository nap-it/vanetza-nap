# Queue Corruption Detection

Vanetza-NAP includes a defensive guard in the GeoNetworking runtime scheduler that detects and recovers from a specific internal queue corruption condition that would otherwise cause a hard crash.

---

## Background

The GeoNetworking stack uses a `ManualRuntime` to manage timed callbacks — beacon intervals, position updates, forwarding timers, and similar periodic tasks. These are stored internally in a `boost::multi_index` priority queue ordered by deadline. The `trigger()` function is called on every clock tick to fire any callbacks whose deadline has passed.

Under sustained high message rates with multiple threads, a rare race condition can corrupt the internal tree structure of this queue. The corruption manifests as a node whose right child points back to itself — an impossible state in a valid binary tree that causes an infinite loop or segfault the next time the queue is traversed.

This was observed in production deployments under load and is difficult to reproduce deterministically, which makes it hard to fix at the root cause without a deeper refactor of the threading model around the runtime.

---

## The Guard

Before processing each element in the `trigger()` loop, the guard checks the internal tree node pointers for the known corruption signature:

```
top.get_node()->right() == top.get_node()->right()->left()
```

If this cycle is detected, the entire queue is cleared and the loop exits. All pending callbacks are lost for that tick, but the process keeps running. On the next tick, applications re-schedule their timers normally and operation resumes.

A debug message is printed to stdout when the guard fires:

```
[DEBUG] - Runtime queue corruption was detected and cleared
```

---

## What It Means in Practice

A corruption event causes a brief disruption — any callbacks that were pending at the moment the queue was cleared (beacon transmissions, forwarding timers) are skipped for that tick. In practice this is invisible at the application level: a single missed CAM or position update is within normal ITS tolerance, and all timers re-arm on the next cycle.

Without the guard, the same event would terminate the process entirely, taking down all active connections and requiring a container restart. The guard trades a momentary skip for continued operation.

This is explicitly a workaround, not a fix. If the debug message appears frequently in logs it is a signal that the threading model around the runtime is under more contention than expected, and the `num_threads` setting or the deployment architecture should be reviewed.
