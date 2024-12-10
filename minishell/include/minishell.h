#ifndef MINISHELL_H
# define MINISHELL_H

# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <signal.h>
# include <stdbool.h>
# include <limits.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>

typedef enum e_tok_type
{
	WORD,
	PIPE,
	SIMPLEQ,
	DOUBLEQ,
	DOLLAR,
	OPEIN,
	OPEOUT,
	APPEND,
	HEREDOC,
	UNKNOWN,
	END,
}		t_tok_type;

#endif
