# Lab 02 Report: Multi-Process Execution in C

Lab 02 demonstrates how to create and manage multiple processes in C using low-level system calls like `fork()`, `exec`, and `waitpid()`. Each child process executes a different shell command, showcasing how UNIX-based systems handle concurrent tasks. The project highlights practical process control, system-level programming, and synchronization between parent and child processes.

---

## Introduction

In operating systems, processes are fundamental units of execution. Learning how to manage processes at a low level is key for systems programming. This lab assignment focuses on creating multiple child processes using `fork()` and executing shell commands within those children using the `exec` family of functions. It also emphasizes process synchronization using `waitpid()`, ensuring the parent properly manages and monitors its children. This exercise bridges theoretical knowledge about processes with hands-on C programming.

---

## Implementation Summary

The program is implemented in a single C file named `lab02.c`. It begins by creating a loop that runs 10 times, each time calling `fork()` to spawn a child process. Inside each child process (where `pid == 0`), a unique command is executed using `execlp()` depending on the value of the loop counter.

### Commands Executed by Child Processes

Each child process runs one of the following Linux shell commands using `execlp()`:

| Child # | Command          | Description                                      |
|---------|------------------|--------------------------------------------------|
| 0       | `echo`           | Prints a simple text message.                   |
| 1       | `ls -l`          | Lists files in the current directory with details. |
| 2       | `date`           | Displays the current system date and time.      |
| 3       | `uname -a`       | Shows detailed system and kernel information.   |
| 4       | `whoami`         | Prints the current logged-in username.          |
| 5       | `pwd`            | Outputs the current working directory.          |
| 6       | `id`             | Displays user ID, group ID, and related info.   |
| 7       | `uptime`         | Shows how long the system has been running.     |
| 8       | `cal`            | Prints the current month's calendar.            |
| 9       | `hostname`       | Displays the system's network hostname.         |


Each command is short, clean, and easy to read when printed to the console.

Meanwhile, the parent process stores all child PIDs in an array and waits for each one to terminate using `waitpid()`. After each child exits, the parent checks whether the child exited normally or was terminated by a signal. It then prints a summary message with the PID and exit status or signal number.

---

### **Process Creation and Management**

The `fork()` system call is used to create each child process. It duplicates the parent process, allowing both the parent and the child to execute independently. Once inside the child block, `execlp()` replaces the child’s code with a new program (like `ls` or `date`). This illustrates how a new program can be loaded into a process space using exec-family functions.

The parent process maintains control and avoids zombie processes by using `waitpid()` to monitor each child. By capturing the PID and exit status, the parent can print meaningful status messages and ensure proper cleanup.

### **Parent and Child Interaction**

The parent doesn’t perform any logic apart from waiting for children to finish and reporting their termination status. The child processes execute their commands and exit, while the parent synchronizes their completion. This clearly demonstrates one-way control where the parent oversees execution but does not interfere once a child starts running its command. This separation reinforces the concept that once a child calls `exec`, it becomes a new process with its own behavior, separate from the original C program.

---

## Conclusion

This lab was a valuable hands-on exercise in understanding process control. It demonstrated the full lifecycle of child processes, from creation with `fork()`, to program replacement with `execlp()`, to termination monitoring with `waitpid()`. 

It also highlighted how to cleanly manage multiple concurrent child processes, ensure proper synchronization, and avoid issues like zombie processes.

---

## How to Compile and Run

A `Makefile` is provided to make compilation easy.

```bash
make         # Compiles lab02.c into lab02
./lab02.out  # Runs the program
make clean   # Cleans up the executable

