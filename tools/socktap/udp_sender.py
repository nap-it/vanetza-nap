#!/usr/bin/env python3
import socket
import time

# Configuration
HOST = "10.0.23.236"
PORT = 50050
MESSAGE = b"Hello World from UDP!"
INTERVAL = 1.0  # seconds


def main():
    print(f"Sending UDP packets to {HOST}:{PORT}...")

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    try:
        count = 0
        while True:
            count += 1
            sock.sendto(MESSAGE, (HOST, PORT))
            print(f"[{count}] Sent: {MESSAGE}")
            time.sleep(INTERVAL)

    except KeyboardInterrupt:
        print("\nStopped by user")
    finally:
        sock.close()


if __name__ == "__main__":
    main()
