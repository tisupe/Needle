# Needle

An Unix-like shell written in C++, built to understand UNIX processes, shell parsing, job control, pipes, and file descriptors by implementing them from scratch.

## Features

### Core Shell
- Interactive REPL
- Custom shell prompt
- Built-in commands
- External Programs

### Parsing
- Single & double quotes
- Escape sequences
- Quoted executables

### I/O
- Stdout/Stderr redirection
- Append redirection

### Process Management
- Pipelines
- Background jobs
- Job control

### History
- Persistent history
- History navigation
- History execution

### Shell Features
- Parameter & variable expansion
- Tab completion
  - Built-ins
  - Executables
  - Files & directories
  - Nested paths
  - Programmable completion

### Misc
- Invalid command handling
- Edge case handling

## Try it

```sh
git clone https://github.com/tisupe/Needle
cd Needle
make
./build/needle
```
