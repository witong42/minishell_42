# minishell

A simplified Unix shell written in C as part of the 42 school curriculum. Minishell replicates core bash functionality including command execution, pipes, redirections, environment variable expansion, and built-in commands.

## Building

### Prerequisites

- GCC or Clang compiler
- GNU Make
- GNU Readline library (`libreadline-dev` on Debian/Ubuntu)

### Compile

```bash
cd minishell
make
```

### Run

```bash
./minishell
```

### Clean

```bash
make clean   # remove object files
make fclean  # remove object files and executable
make re      # full rebuild
```

## Features

### Command Execution
- Searches executables via the `PATH` environment variable
- Supports absolute and relative paths
- Proper exit status tracking (`$?`)

### Pipes
- `cmd1 | cmd2 | cmd3` - chains commands via pipes

### Redirections
- `< file` - redirect input from file
- `> file` - redirect output to file (truncate)
- `>> file` - redirect output to file (append)
- `<< DELIM` - here-document (read input until delimiter)

### Quoting
- Single quotes (`'...'`) - prevent all interpretation
- Double quotes (`"..."`) - prevent interpretation except for `$` expansion

### Environment Variable Expansion
- `$VAR` expands to the value of the environment variable
- `$?` expands to the exit status of the last command

### Signal Handling
- `Ctrl+C` - displays a new prompt on a new line
- `Ctrl+D` - exits the shell
- `Ctrl+\` - ignored in interactive mode

### Built-in Commands

| Command  | Description                          |
|----------|--------------------------------------|
| `echo`   | Print arguments (`-n` flag supported)|
| `cd`     | Change directory (absolute, relative, `~`, `-`) |
| `pwd`    | Print working directory              |
| `export` | Set environment variables            |
| `unset`  | Remove environment variables         |
| `env`    | Display environment variables        |
| `exit`   | Exit the shell with optional status  |

## Architecture

```
Input -> Lexer -> Parser -> Expander -> Executor
```

### Lexer (`src/lexer/`)
Tokenizes raw input into a linked list of typed tokens (WORD, PIPE, REDIRIN, REDIROUT, APPEND, HEREDOC, etc.). Handles quote tracking and space normalization around operators.

### Parser (`src/parser/`)
Builds a command table (linked list of `t_cmd` structs) from the token list. Each command contains its arguments, redirections, and heredoc information.

### Expander (`src/expander/`)
Resolves `$VAR` references to their environment values and `$?` to the last exit status. Expansion respects quoting rules (no expansion inside single quotes).

### Executor (`src/executor/`)
Executes commands by forking child processes, setting up pipes and redirections, and resolving executable paths via `PATH`. Built-in commands run in the parent process (single command) or child process (in a pipeline).

### Memory Management (`src/utils/gc.c`)
A garbage collector tracks all dynamically allocated memory during command processing via a linked list. A single `cleanup_all()` call frees everything between command cycles.

## Project Structure

```
minishell/
  Makefile
  includes/          # Header files
    minishell.h      # Core structures (t_shell, t_cmd, t_exec, t_redir)
    lexer.h          # Lexer types and functions
    parser.h         # Parser functions
    exec.h           # Execution functions
    expand.h         # Expander functions
    builtins.h       # Built-in command functions
    utils.h          # Utilities, GC, signals, errors
  src/
    main.c           # Entry point and main loop
    lexer/           # Tokenization
    parser/          # Syntax analysis
    expander/        # Variable expansion
    executor/        # Command execution, pipes, redirections
    builtins/        # Built-in command implementations
    utils/           # Init, signals, error handling, GC
  libft/             # 42 standard library (string, memory, list utilities)
```

## Authors

- arotondo
- witong
