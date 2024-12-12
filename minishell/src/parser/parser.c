/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 15:34:31 by witong            #+#    #+#             */
/*   Updated: 2024/12/12 17:49:59 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"


void	parse_command(t_token *current, t_commands *cmd)
{
	int i = 0;
	while (current && !is_redirection(current->type))
	{
		if(current->type == WORD || current->type == SINGLEQ)
		{
			cmd->full_cmd[i] = ft_strdup(current->value);
			i++;
		}
		current = current->next;
	}
	cmd->full_cmd[i] = NULL;
}

int	parser(t_token *tokens)
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
		parse_command(tokens, cmd);
		current = current->next;
	}
	if (current->type == REDIRIN)
	if (current->type == REDIROUT)
	if (current->type == HEREDOC)
	if (current->type == APPEND)

}
