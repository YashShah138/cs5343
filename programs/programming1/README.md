# Program 2: File I/O Using System Calls

## Description

This program demonstrates low-level file I/O operations using Unix system calls. It reads 10 characters from standard input (stdin) and writes them to a new file called `output.txt` using the `open`, `read`, and `write` system calls.

## Features

- Uses low-level Unix system calls (`open`, `read`, `write`, `close`) instead of standard library functions
- Reads exactly 10 characters from user input
- Creates a new file `output.txt` (or overwrites if it exists)
- Includes comprehensive error handling for all system calls
- Properly closes file descriptors

## System Calls Used

1. **`read()`** - Reads data from a file descriptor (stdin in this case)
2. **`open()`** - Opens or creates a file and returns a file descriptor
3. **`write()`** - Writes data to a file descriptor
4. **`close()`** - Closes a file descriptor

## Compilation

To compile the program, use `gcc`:

```bash
gcc program2.c -o program2
```

## Usage

1. Run the compiled program:
   ```bash
   ./program2
   ```

2. When the program runs, enter 10 characters (you can type them and press Enter). Any characters above the 10 char limit will not be entered (ignored).

3. The program will create (or overwrite) `output.txt` with the characters you entered.

4. Verify the output:
   ```bash
   cat output.txt
   ```

## Example

```bash
$ ./program2
ABCDEFGHIJ
Successfully wrote 10 chars to output.txt

$ cat output.txt
ABCDEFGHIJ
```

## File Permissions

The output file `output.txt` is created with permissions `0644` (rw-r--r--), meaning:
- **Owner**: read and write permissions
- **Group**: read-only permission
- **Others**: read-only permission

## Error Handling

The program includes error handling for:
- Failed read operations
- Failed file open/create operations
- Failed write operations
- Failed file close operations

If any error occurs, an appropriate error message will be displayed using `perror()`.

## Notes

- The program reads from file descriptor `0`, which is standard input (stdin)
- If you enter fewer than 10 characters, only the characters you entered will be written to the file
- If you enter more than 10 characters, only the first 10 will be read and written
- The program uses `ssize_t` for byte counts, which is the proper type for system call return values

## Requirements

- Unix-like operating system (Linux, macOS, etc.)
- GCC compiler
- Standard C libraries: `<stdio.h>`, `<fcntl.h>`, `<unistd.h>`, `<stdlib.h>`
