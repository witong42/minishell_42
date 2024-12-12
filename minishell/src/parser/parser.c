/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:34:31 by witong            #+#    #+#             */
/*   Updated: 2024/12/12 17:44:26 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

int	parsing(t_token *tokens)
{
	t_token	*current;
	int	pipe;
	int	i;

	i = 0;
	t_commands	*cmd;


	if(!tokens)
		return(-1);
	current = tokens;
	while (current)
	{
		if (current->type == PIPE)
			cmd[pipe++];
		current = current->next;
	}
	while (pipe > 0)
	{
		t_commands cmd;
	}
	i = 0;
	while (current && !is_redirection(current->type))
	{
		if(current->type == WORD || current->type == SINGLEQ)
		{
			t_commands->full_cmd[i] = ft_strdup(current->value);
			i++;
		}
		current = current->next;
	}
	t_commands->full_cmd[i] = NULL;
	if (current->type == REDIRIN)
	if (current->type == REDIROUT)
	if (current->type == HEREDOC)
	if (current->type == APPEND)

}
