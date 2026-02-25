/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arotondo <arotondo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:06:42 by arotondo          #+#    #+#             */
/*   Updated: 2025/02/28 14:40:04 by arotondo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	check_flag(char **flag, int *idx)
{
	int		i;
	int		j;
	bool	ret;

	i = 1;
	if (flag[i] == NULL)
		return (false);
	while (flag[i] && flag[i][0] == '-')
	{
		j = 1;
		while (flag[i][j] == 'n')
			j++;
		if (flag[i][j] == '\0')
		{
			(*idx)++;
			i++;
		}
		else
			break ;
	}
	ret = *idx > 0;
	return (ret);
}

int	ft_echo(int nb, char **arg, char **envp)
{
	int		i;
	bool	flag;

	(void)envp;
	i = 0;
	flag = check_flag(arg, &i);
	while (++i < nb)
	{
		ft_putstr_fd(arg[i], 1);
		if (i != nb - 1)
			ft_putchar_fd(' ', 1);
	}
	last_check(flag);
	return (0);
}

void	last_check(int flag)
{
	if (flag == false)
		write(1, "\n", 1);
}
