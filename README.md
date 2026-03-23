# pipex

*This project has been created as part of the 42 curriculum by <oaletham>.*

## Description

Pipex is a system programming project that focuses on understanding how UNIX pipes work.

The goal is to reproduce the behavior of the following shell command:

```
< file1 cmd1 | cmd2 > file2
```

The program takes 4 arguments:

```
./pipex file1 cmd1 cmd2 file2
```

- file1: input file  
- cmd1: first command  
- cmd2: second command  
- file2: output file  

The project explores process creation, file descriptors, pipes, and execution of commands using `execve`.

---

## Instructions

### Compilation

```
make
```

### Execution

```
./pipex file1 "cmd1" "cmd2" file2
```

### Example

```
./pipex infile "ls -l" "wc -l" outfile
```

Equivalent to:

```
< infile ls -l | wc -l > outfile
```

---

## Project Structure

```
pipex/
├── Makefile
├── include/
│   └── pipex.h
├── src/
│   ├── pipex.c
│   ├── helper.c
│   └── fd_not_exist.c
└── libft/
```

---

## Key Concepts

- Pipes (`pipe`)
- Process creation (`fork`)
- File descriptor duplication (`dup`, `dup2`)
- Command execution (`execve`)
- Error handling
- Memory management

---

## Resources

- Linux manual pages:
  - `man 2 pipe`
  - `man 2 fork`
  - `man 2 dup2`
  - `man 3 execve`

- Online references:
  - https://man7.org/linux/man-pages/
  - https://stackoverflow.com/

### AI Usage

AI was used to:
- Help structure the project
- Clarify system call behavior
- Assist in debugging concepts

All generated content was reviewed, tested, and fully understood before use.
