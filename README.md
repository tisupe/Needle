# Needle

**Needle** is an experimental Unix-like shell written in **C++**, built to learn how UNIX processes, job control, pipes, file descriptors, and shell parsing work under the hood.

## Features

### Core Shell
- [x] Interactive REPL with custom shell prompt
- [x] Built-in commands
  - [x] `cd`
  - [x] `pwd`
  - [x] `echo`
  - [x] `exit`
  - [x] `type`
  - [ ] `history`
  - [ ] `jobs`
  - [ ] `declare`
- [x] Execute external programs using `PATH` lookup

### Parsing
- [ ] Single & double quotes
- [ ] Escape sequences
- [ ] Quoted executables

### I/O
- [ ] Stdout/Stderr redirection
- [ ] Append redirection

### Process Management
- [ ] Pipelines
- [ ] Background jobs
- [ ] Job control

### History
- [ ] Persistent history
- [ ] History navigation
- [ ] History execution

### Shell Features
- [ ] Parameter & variable expansion
- [ ] Tab completion
  - [ ] Built-ins
  - [ ] Executables
  - [ ] Files & directories
  - [ ] Nested paths
  - [ ] Programmable completion

### Misc
- [ ] Invalid command handling
- [ ] Edge case handling

### Requirements

- C++ Compiler
- CMake
- Linux

### Build & Run

```sh
git clone https://github.com/tisupe/Needle
cd Needle
cmake -S . -B $(BUILD_DIR)
cmake --build $(BUILD_DIR)
./$(BUILD_DIR)/$(TARGET)
```
