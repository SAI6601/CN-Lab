# Computer Networks Lab Practicals

**Name:** Ram | **Reg No:** 25MCS0063  
**VIT Vellore | MCS Semester II | 2025–26**

---

## How to Download Any File in Lab Terminal

```bash
# Download a single file
wget https://raw.githubusercontent.com/YOUR_USERNAME/CN-Lab/main/FOLDER/filename.c

# Example
wget https://raw.githubusercontent.com/YOUR_USERNAME/CN-Lab/main/P01_UDP_Socket/udp_server.c
```

---

## Practicals Index

| # | Practical | Files |
|---|-----------|-------|
| 1 | UDP Socket Programming | `udp_server.c`, `udp_client.c` |
| 2 | TCP Chat Application | `tcp_server_chat.c`, `tcp_client_chat.c` |
| 3 | Client-Server RSA Cryptography | `rsa_server.c`, `rsa_client.c` |
| 4 | Go-Back-N Protocol | `gbn_sender.c`, `gbn_receiver.c` |
| 5 | Selective Repeat Protocol | `sr_sender.c`, `sr_receiver.c` |
| 6 | Binary to Decimal & Vice Versa (IP) | `ip_converter.c` |
| 7 | Subnetting | `subnetting.c` |
| 8 | Network & Broadcast Address | `ip_info.c` |
| 9 | Distance Vector Routing (Bellman-Ford) | `dvr.c` |
| 10 | Link State Routing (Dijkstra's) | `lsr.c` |

---

## Compilation Guide

```bash
# Single file
gcc filename.c -o output
./output

# Client-Server (run in two terminals)
gcc server.c -o server && ./server
gcc client.c -o client && ./client
```
