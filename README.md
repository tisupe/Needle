# Needle

An experimental Unix-like shell written in **C++**, built to learn how UNIX processes, job control, pipes, file descriptors, and shell parsing work under the hood.

## Features

### Core Shell
- Interactive REPL with custom shell prompt
- Built-in commands
  - `cd`
  - `pwd`
  - `echo`
  - `exit`
  - `type`
  - `history`
  - `jobs`
  - `declare`
- Execute external programs using `PATH` lookup

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

### Try it

```sh
git clone https://github.com/tisupe/Needle
cd Needle ; cd build
chmod +x Needle
./Needle
```
