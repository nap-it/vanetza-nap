#!/usr/bin/env python3
import binascii
import socket
import time

# Configuration
HOST = "10.0.23.236"
PORT = 50050
MESSAGE = b"Hello World from UDP!"
INTERVAL = 1.0  # seconds

btp = "07d10000"
cam = "0202000000d752610059bba8998cc40a4bdffffffc23b7743e403e8fc9c47e0630ea8007fee1fff82f80"
payload_hex = btp + cam
payload_bytes = binascii.unhexlify(payload_hex)


def main():
    print(f"Sending UDP packets to {HOST}:{PORT}...")

    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    try:
        count = 0
        while True:
            count += 1
            sock.sendto(payload_bytes, (HOST, PORT))
            print(f"[{count}] Sent: {payload_bytes.hex()}")
            time.sleep(INTERVAL)

    except KeyboardInterrupt:
        print("\nStopped by user")
    finally:
        sock.close()


if __name__ == "__main__":
    main()
