/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 14:37:11 by arotondo          #+#    #+#             */
/*   Updated: 2024/12/16 16:29:29 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

bool	parser_error(t_token **tokens)
{
	if ((*tokens)->type == PIPE && (*tokens)->next->type && (*tokens)->next->type == PIPE)
		return (unexpected_token(tokens), true);
	else if ((*tokens)->type == PIPE && (!(*tokens)->next->type || (*tokens)->next->type == END))
		return (unexpected_token(tokens), true);
	else if (is_redirection2((*tokens)->type) && (!(*tokens)->next->type || !is_word((*tokens)->next->type)))
		return (unexpected_token(tokens), true);
	else if (!(*tokens)->prev && (*tokens)->type == PIPE)
		return (unexpected_token(tokens), true);
	return (false);
}
