/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 14:39:01 by witong            #+#    #+#             */
/*   Updated: 2025/02/26 11:01:27 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

char	*ft_strjoin2(const char *s1, const char *s2)
{
	char	*str;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = '\0';
	return (str);
}

char	**mini_env(void)
{
	char	**new_env;
	char	*cwd;

	new_env = (char **)malloc(sizeof(char *) * 4);
	if (!new_env)
		return (NULL);
	cwd = getcwd(NULL, 0);
	if (!cwd)
	{
		free(new_env);
		return (NULL);
	}
	new_env[0] = ft_strjoin2("PWD=", cwd);
	new_env[1] = ft_strdup("SHLVL=1");
	new_env[2] = ft_strdup("_=/usr/bin/env");
	new_env[3] = NULL;
	free(cwd);
	if (!new_env[0] || !new_env[1] || !new_env[2])
	{
		free_array(new_env);
		return (NULL);
	}
	return (new_env);
}

char	*ft_getenv(const char *name, char **envp)
{
	size_t	len;
	size_t	i;

	if (!envp || !*envp || !*name)
		return (NULL);
	len = ft_strlen(name);
	i = 0;
	while (envp[i])
	{
		if (!ft_strncmp(envp[i], name, len) && envp[i][len] == '=')
			return (envp[i] + len + 1);
		i++;
	}
	return (NULL);
}

char	**arraydup(char **array)
{
	char	**dup;
	int		lc;

	lc = count_line(array);
	dup = (char **)malloc(sizeof(char *) * (lc + 1));
	if (!dup)
		return (perror(""), NULL);
	dup[lc] = NULL;
	lc = 0;
	while (array[lc])
	{
		dup[lc] = ft_strdup(array[lc]);
		if (!dup[lc])
		{
			free_array(dup);
			return (NULL);
		}
		lc++;
	}
	return (dup);
}

void	free_array(char **array)
{
	int	i;
	int	size;

	if (!array || !*array)
		return ;
	i = 0;
	size = count_line(array);
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
