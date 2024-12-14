/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:02:33 by witong            #+#    #+#             */
/*   Updated: 2024/12/14 15:01:56 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_tok_type	check_redirection(char c)
{
	if (c == '|')
		return (PIPE);
	else if (c == '<')
		return (REDIRIN);
	else if (c == '>')
		return (REDIROUT);
	return (UNKNOWN);
}

t_tok_type check_double_ops(char c1, char c2)
{
	if (c1 == '<' && c2 == '<')
		return (HEREDOC);
	if (c1 == '>' && c2 == '>')
		return (APPEND);
	return (UNKNOWN);
}
void illegal_token(char c)
{
	ft_putstr_fd("lexer: unsupported token error near '", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("'\n", 2);
}
