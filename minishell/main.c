/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 11:04:51 by witong            #+#    #+#             */
/*   Updated: 2024/12/10 12:34:43 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	count_line(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	**arraydup(char **array)
{
	char	**dup;
	int		lc;
	int		i;

	lc = count_line(array);
	dup = (char **)malloc(sizeof(char*) * (lc + 1));
	if (!dup)
		return (NULL);
	dup[lc] = NULL;
	lc = 0;
	while (array[lc])
	{
		dup[lc] = strdup(array[lc]); //replace by ft_strdup
		//if(!dup[lc])
			//free
		i = 0;
		while (array[lc][i])
		{
			dup[lc][i] = array[lc][i];
			i++;
		}
		dup[lc][i] = '\0';
		lc++;
	}
	return (dup);
}

int	main(int ac, char **av, char **envp)
{
	(void) ac;
	(void) av;
	(void) envp;
	char *input;
	int	i;
	char **env;

	i = 0;
	env = arraydup(envp);
	if (!env)
		printf("Error");
	while (env[i])
		printf("%s\n", env[i++]);
	while (1)
	{
		input = readline("minishell>");
		if (!input)
			break ;
		if (*input != '\0')
			add_history(input);
	}
	rl_clear_history();
	return (0);
}
