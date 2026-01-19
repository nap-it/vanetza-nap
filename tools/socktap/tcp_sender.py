#!/usr/bin/env python3
import socket
import time

# Configuration
HOST = "10.0.22.118"
PORT = 50050
MESSAGE = b"Hello World from TCP!"
INTERVAL = 1.0  # seconds

def main():
    print(f"Connecting to {HOST}:{PORT} via TCP...")

    try:
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.connect((HOST, PORT))
        print("Connected!")

        count = 0
        while True:
            count += 1
            sock.sendall(MESSAGE)
            print(f"[{count}] Sent: {MESSAGE}")
            time.sleep(INTERVAL)

    except ConnectionRefusedError:
        print(f"Connection refused. Is the server running on {HOST}:{PORT}?")
    except KeyboardInterrupt:
        print("\nStopped by user")
    finally:
        sock.close()

if __name__ == "__main__":
    main()
