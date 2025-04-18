# 42-minishell

## 0. Excerpt from subject :

Program name minishell
Turn in files Makefile, *.h, *.c
Makefile NAME, all, clean, fclean, re
Arguments
External functs. readline, rl_clear_history, rl_on_new_line,
rl_replace_line, rl_redisplay, add_history,
printf, malloc, free, write, access, open, read,
close, fork, wait, waitpid, wait3, wait4, signal,
sigaction, sigemptyset, sigaddset, kill, exit,
getcwd, chdir, stat, lstat, fstat, unlink, execve,
dup, dup2, pipe, opendir, readdir, closedir,
strerror, perror, isatty, ttyname, ttyslot, ioctl,
getenv, tcsetattr, tcgetattr, tgetent, tgetflag,
tgetnum, tgetstr, tgoto, tputs
Libft authorized Yes
Description Write a shell

- Display a prompt when waiting for a new command.
- Have a working history.
- Search and launch the right executable (based on the PATH variable or using a relative or an absolute path).
- Avoid using more than one global variable to indicate a received signal. Consider the implications: this approach ensures that your signal handler will not access your main data structures.
Not interpret unclosed quotes or special characters which are not required by the subject such as \ (backslash) or ; (semicolon).
• Handle ’ (single quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence.
• Handle " (double quote) which should prevent the shell from interpreting the metacharacters in the quoted sequence except for $ (dollar sign).
• Implement redirections:
◦ < should redirect input.
◦ > should redirect output.
◦ << should be given a delimiter, then read the input until a line containing the
delimiter is seen. However, it doesn’t have to update the history!
◦ >> should redirect output in append mode.
• Implement pipes (| character). The output of each command in the pipeline is
connected to the input of the next command via a pipe.
• Handle environment variables ($ followed by a sequence of characters) which
should expand to their values.
• Handle $? which should expand to the exit status of the most recently executed
foreground pipeline.
• Handle ctrl-C, ctrl-D and ctrl-\ which should behave like in bash.
• In interactive mode:
◦ ctrl-C displays a new prompt on a new line.
◦ ctrl-D exits the shell.
◦ ctrl-\ does nothing.
• Your shell must implement the following builtins:
◦ echo with option -n
◦ cd with only a relative or absolute path
◦ pwd with no options
◦ export with no options
◦ unset with no options
◦ env with no options or arguments
◦ exit with no options
The readline() function can cause memory leaks. You don’t have to fix them. But
that doesn’t mean your own code, yes the code you wrote, can have memory
leaks.

Bonus ? • && and || with parenthesis for priorities.

- Overall Structure→Input Lexing  Parsing  Execution
  1. Lexing (Tokenization): Break the raw input string into a series of tokens (words, operators, redirections, pipes, etc.).
  2. Parsing: Analyze the tokens to build a command structure (command table) that represents the intended execution.
  3. Execution: Use the parsed structure to execute commands, handling redirections, pipes, and built-in commands.


