# VOLT

High-performance network stress testing tool. C++ frontend with Rust backend.

![VOLT](https://img.shields.io/badge/VOLT-v1.0-blue)

---

## Features

- **UDP Flood** - Maximum 65507 bytes per packet, pure bandwidth saturation
- **TCP Flood** - Mass connection attempts, resource exhaustion
- **Live Statistics** - Real-time packet counter with bandwidth display
- **Hybrid Engine** - C++ menu & stats + Rust high-performance attack backend
- **Port Scanner Ready** - Works on any TCP/UDP port
- **Clean Interface** - ASCII logo, colored output, intuitive controls

---

## Requirements

| Component | Version |
|-----------|---------|
| Windows   | 10 or 11 |
| Rust      | Latest stable |
| Visual Studio | 2022 or newer (for C++ compiler) |

---

## Installation

### Option A - Pre-built (Easy)
1. Download `VOLT.exe` and `ddos.dll` from the **Releases** page
2. Put BOTH files in the **SAME folder**
3. Run `VOLT.exe`

### Option B - Build yourself

**Both files MUST be in the SAME folder!**

**1. Open terminal in your project folder:**
```bash
cd C:\Users\YourName\Desktop\VOLT 
rustc -O ddos.rs --crate-type cdylib -o ddos.dll 


<img width="1112" height="624" alt="image" src="https://github.com/user-attachments/assets/be3edd96-d9cc-43bf-9ba0-c75617c7bf5f" />


