## Prerequisites

### Install gperf (Required)

```bash
sudo apt-get update
sudo apt-get install gperf
```

Verify installation:
```bash
gperf --version
# Should output: GNU gperf 3.x.x
```

## Build Steps

### 1. Generate JER Transformation Hash Table

**To regenerate** (only when adding/modifying transforms):
```bash
cd vanetza/asn1/rj/transformations
gperf --language=C++ --struct-type --readonly-tables \
    jer_transformations.gperf > jer_transformations.cpp
```

This generates `jer_transformations_hash.cpp` from `jer_transformations.gperf`.