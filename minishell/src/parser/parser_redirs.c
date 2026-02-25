/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_redirs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 12:25:07 by witong            #+#    #+#             */
/*   Updated: 2025/02/22 01:39:18 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_redir	*create_redir(t_shell *shell, t_token *token)
{
	t_redir	*new_redir;

	new_redir = tracked_malloc(shell, sizeof(t_redir));
	if (!new_redir)
		return (NULL);
	if (token == NULL)
	{
		new_redir->type = END;
		new_redir->file = NULL;
	}
	else
	{
		new_redir->type = token->type;
		if (token->next)
			new_redir->file = ft_strdup_track(shell, token->next->value);
		else
			return (NULL);
	}
	new_redir->next = NULL;
	new_redir->prev = NULL;
	return (new_redir);
}

void	redir_add_back(t_redir **redirs, t_redir *new_redir)
{
	t_redir	*tmp;

	if (!redirs || !new_redir)
		return ;
	if (!*redirs)
	{
		*redirs = new_redir;
		return ;
	}
	tmp = *redirs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new_redir;
	new_redir->prev = tmp;
}

void	end_redir(t_shell *shell)
{
	t_redir	*new_redir;

	new_redir = create_redir(shell, NULL);
	if (new_redir && shell->cmd)
	{
		if (shell->cmd->redirs)
			redir_add_back(&shell->cmd->redirs, new_redir);
		else
			shell->cmd->redirs = new_redir;
	}
}
