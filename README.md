# My First C++ Memory Hacking Tool

This is my very first software project written in C++. It interacts directly with the Windows OS kernel to modify the memory of a running process (specifically targeting GTA San Andreas). 

Through this project, I learned the core fundamentals of low-level programming, operating system process isolation, cross-compilation, and memory management.

## 🚀 What I Did & How It Works

1. **Windows Portability:** I migrated the initial Linux-specific `/proc/` code to the native **Windows API (`<windows.h>`)**, utilizing system calls like `OpenProcess` and `WriteProcessMemory`.
2. **Cross-Compilation:** Since I work inside a **WSL (Ubuntu)** environment, I used the `x86_64-w64-mingw32-g++` cross-compiler with `-static-libgcc` and `-static-libstdc++` flags to embed all necessary C++ libraries directly into a standalone **64-bit Windows `.exe`** file.
3. **Execution via CMD:** To bypass Windows OS security boundaries and access the game's memory layout, the compiled binary must be executed through a standard **Windows Command Prompt (CMD) running as Administrator**.
4. **Validation:** The tool prompts for the game's decimal Process ID (PID), hooks into the process, verifies memory allocation, and modifies the target memory address successfully.

## 📸 Proof of Concept (How to attach your results)
