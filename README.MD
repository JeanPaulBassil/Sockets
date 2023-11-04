### README.md for the 'sockets' Directory

---

#### Overview

The `sockets` directory contains a collection of source files that implement simple client-server applications using socket programming. This includes both C and Java implementations showcasing TCP/IP communication.

---

#### Contents

- `server.c`: A C-based TCP server that accepts connections and converts incoming messages to uppercase before sending them back to the client.
- `client.c`: A C-based TCP client that connects to the TCP server, sends a message, and receives the converted message.
- `DateServer.java`: A Java-based server that sends the current date and time to the client upon connection.
- `DateClient.java`: A Java-based client that connects to the DateServer and prints out the date and time received from the server.

---

#### Compilation and Execution Instructions

##### C Programs
To compile the C programs, use the following commands:

```bash
gcc -o server server.c
gcc -o client client.c
```

To run the server:

```bash
./server
```

To run the client (make sure to replace `<IP_ADDRESS>` with the server's IP):

```bash
./client <IP_ADDRESS>
```

##### Java Programs
To compile the Java programs, use:

```bash
javac DateServer.java
javac DateClient.java
```

To run the Java DateServer:

```bash
java DateServer
```

To run the Java DateClient:

```bash
java DateClient
```

---

#### Dependencies

Ensure you have the following installed:

- GCC for compiling C programs.
- JDK for compiling and running Java programs.

---

#### Networking Information

- The C server listens on port `5554`.
- The Java DateServer listens on port `6013`.
- Ensure these ports are open and not in use by other applications.

---

#### Additional Notes

- The C server can handle multiple clients sequentially but is not threaded for concurrent handling.
- The Java DateServer handles one connection at a time and waits for it to close before listening for another.
- The clients are designed to terminate after sending a message and receiving a response.

---