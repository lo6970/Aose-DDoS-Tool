<img width="1105" height="617" alt="Screenshot 2026-07-19 231259" src="https://github.com/user-attachments/assets/675115e1-69ba-40a2-bfa9-90e8a450fc21" />
# VOLT

High-performance network stress testing tool. C++ frontend with Rust backend.

![VOLT](https://img.shields.io/badge/VOLT-v1.0-blue)

---

## Features

- **UDP Flood** - Maximum 65507 bytes per packet, pure bandwidth saturation
- **TCP Flood** - Mass connection attempts, resource exhaustion
- **Live Statistics** - Real-time packet counter with bandwidth display
- **Hybrid Engine** - C++ menu & stats + Rust high-performance attack backend
- **Clean Interface** - ASCII logo, colored output, intuitive controls

---

<img width="1105" height="617" alt="Screenshot 2026-07-19 231259" src="https://github.com/user-attachments/assets/675115e1-69ba-40a2-bfa9-90e8a450fc21" />

---

## Requirements

| Component | Version |
|-----------|---------|
| Windows   | 10 or 11 |
| Rust      | Latest stable |
| Visual Studio | 2022 or newer |

---

## Installation

### Option A - Pre-built
1. Download `VOLT.exe` and `ddos.dll` from **Releases**
2. Put BOTH files in the **SAME folder**
3. Run `VOLT.exe`

### Option B - Build yourself

Both files MUST be in the SAME folder.

**1. Open terminal in your project folder:**
```bash
cd C:\Users\YourName\Desktop\VOLT
rustc -O ddos.rs --crate-type cdylib -o ddos.dll
"C:\Program Files\Microsoft Visual Studio\18\Community\VC\Auxiliary\Build\vcvars64.bat"
cl /O2 main.cpp /Fe:VOLT.exe /std:c++17
