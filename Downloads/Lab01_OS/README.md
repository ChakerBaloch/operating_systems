# Chaker Baloch  
# Operating System - Lab 01  
# April 23, 2025  


## Script Purpose and Explanation

The Bash script I created is designed to automate the creation of a structured directory and file system, simulating how organized data can be programmatically generated.

### Objective:
The goal is to:
1. Create a main directory named with the current date and time.
2. Inside this directory, create 10 subdirectories.
3. For each subdirectory, create a uniquely named text file.
4. Write the name of a programming language into each file.

### How It Works:

- **Dynamic Naming**: The script uses the current system date and time to name the main folder, ensuring uniqueness every time it runs.

- **Loop and File Generation**: It loops from 101 to 110 to generate ten subdirectories with names like `files101`, `files102`, and so on.

- **File Creation**: In each of these subdirectories, a file is created with a name like `tuser501.txt`, `tuser502.txt`, etc., using a calculated offset (i + 400).

- **Language Assignment**: The script maintains an array of 10 programming languages. Each file is assigned a language based on its position in the loop.

- **Content Writing**: The name of the corresponding language is written into each file using the `echo` command.

### Purpose:
This script demonstrates automation using Bash, including directory management, file creation, data writing, and the use of loops and arrays. It highlights practical uses for commands like `mkdir`, `echo`, and `touch` while encouraging good scripting practices such as dynamic naming and conditional logic.


## Linux Commands Overview

This section provides detailed explanations of commonly used Linux commands in system management and shell scripting.

- **cp**: Stands for "copy". It duplicates files or directories from one location to another. The original file remains unchanged.
  
  Example:  
  ```bash
  cp file1.txt /home/user/documents/
  ```  
  This copies `file1.txt` into the `/home/user/documents/` directory. If the file already exists there, it will be overwritten.

- **ps**: Displays a snapshot of current processes running on the system.
  
  Example:  
  ```bash
  ps aux
  ```  
  This shows detailed information (user, CPU usage, memory usage) about all running processes.

- **ls**: Lists the contents of a directory. It can also show file details depending on the options used.
  
  Example:  
  ```bash
  ls -l
  ```  
  This displays a detailed list including permissions, ownership, file size, and modification date.

- **mv**: Stands for "move". It moves or renames files and directories.
  
  Example:  
  ```bash
  mv oldname.txt newname.txt
  ```  
  This renames the file `oldname.txt` to `newname.txt`.

- **rm**: Deletes files or directories permanently. Use with caution.
  
  Example:  
  ```bash
  rm myfile.txt
  ```  
  This removes `myfile.txt`. The action is irreversible unless used with a confirmation flag like `-i`.

- **mkdir**: Stands for "make directory". It creates new directories in the file system.
  
  Example:  
  ```bash
  mkdir projects
  ```  
  This creates a directory called `projects` in the current location.

- **rmdir**: Removes empty directories.
  
  Example:  
  ```bash
  rmdir tempfolder
  ```  
  This deletes `tempfolder` if it's empty. If not, the command will fail.

- **echo**: Prints a message or variable value to the terminal or writes it into a file.
  
  Example:  
  ```bash
  echo "Hello World" > hello.txt
  ```  
  This creates (or overwrites) `hello.txt` with the text "Hello World".

- **more**: Displays file content one screen at a time for easy reading.
  
  Example:  
  ```bash
  more longtext.txt
  ```  
  This opens `longtext.txt` in a paged format. Use the spacebar to scroll.

- **date**: Shows the current system date and time.
  
  Example:  
  ```bash
  date
  ```  
  This outputs something like "Wed Apr 23 14:30:01 PDT 2025".

- **time**: Measures how long a command takes to run.
  
  Example:  
  ```bash
  time ls
  ```  
  This runs `ls` and prints how long it took in real time, user CPU time, and system CPU time.

- **kill**: Sends signals to processes, most often to terminate them.
  
  Example:  
  ```bash
  kill 1234
  ```  
  This sends the default `SIGTERM` signal to the process with ID 1234.

- **history**: Lists the commands entered in the terminal session.
  
  Example:  
  ```bash
  history
  ```  
  This displays a numbered list of past commands which can be re-run with `!<number>`.

- **chmod**: Changes file or directory permissions.
  
  Example:  
  ```bash
  chmod +x script.sh
  ```  
  This makes `script.sh` executable.

- **chown**: Changes file ownership to a different user or group.
  
  Example:  
  ```bash
  chown username:groupname file.txt
  ```  
  This assigns the file `file.txt` to the specified user and group.

---

