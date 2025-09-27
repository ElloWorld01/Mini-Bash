# Mini Bash

A lightweight command-line interpreter written in C, inspired by the UNIX Bash shell.  
This project was developed during my computer science studies in a project-based learning environment. I acted as the technical lead, mentoring my teammates and taking charge of the project's architecture and implementation. This experience allowed me to reproduce essential shell features while strengthening my skills in system programming, process management, and memory handling.

---

## Features

- Command parsing and execution
- Built-in commands (e.g. `cd`, `echo`, `exit`, `pwd`, ...)
- Environment variable handling (`$PATH`, `$HOME`, ...)
- Input/output redirections (`>`, `<`, `>>`)
- Pipes (`|`) between commands
- Signal handling (e.g. `Ctrl+C`, `Ctrl+D`)
- Error messages for invalid commands

---

## Tech Stack

- **Language:** C (C99 standard)
- **System calls:** `fork`, `execve`, `waitpid`, `pipe`, `dup2`, `signal`
- **Build system:** Makefile (with `make` / `make clean` targets)
- **Tested on:** Linux (Ubuntu / Debian)

---

## Installation & Usage

### 1. Clone the repository

```bash
git clone https://github.com/ElloWorld01/Mini-Bash.git
cd Mini-Bash
```

### 2. Install dependencies and build

Make sure you have a C compiler (e.g. gcc) and make installed on your system. On most Linux distributions, these are available via the package manager (e.g. build-essential on Debian/Ubuntu).
```bash
sudo apt install build-essential
```

#### (Optional) 2.1 Install the `readline` library

We used the GNU Readline library for proper command-line editing. If it's not already installed, you can fetch it via the provided Makefile target:

```bash
make readline
```

#### 2.2 Compile the program

Build the executable using the Makefile:

```bash
make
```

### 3. Run the shell

You can launch the program directly or via the Makefile:

```bash
make launch
```

Or run the executable manually

```bash
./minibash
```

### 4. Example usage
```bash
MiniBash$ echo "Hello, world!"
Hello, world!
```

### 5. Project Structure

```
Mini-Bash/
│── includes/ # header files
│── libft/ # library files
│── srcs/ # source files
│── LICENSE # license file
│── Makefile # build rules
│── README.md # documentation
```

## License

This project is licensed under the [MIT License](LICENSE).
