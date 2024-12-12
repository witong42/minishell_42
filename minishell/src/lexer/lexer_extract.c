/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_extract.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: witong <witong@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 15:15:54 by witong            #+#    #+#             */
/*   Updated: 2024/12/12 10:49:43 by witong           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	*extract_word(const char *line, int *i)
{
	int		start;

	start = *i;
	while (line[*i] && !ft_isspace(line[*i]) && !is_special_char(line[(*i)]))
		(*i)++;
	return (ft_substr(line, start, *i - start));
}
char *extract_single_quote(const char *line, int *i)
{
	int		start;

	(*i)++;
	start = *i;
	while (line[*i] && line[*i] != '\'')
		(*i)++;
	if (line[*i] != '\'')
	{
		ft_putstr_fd("lexer: unclosed quotes", 2);
		return (NULL);
	}
	(*i)++;
	return (ft_substr(line, start, *i - start -1));
}

char *extract_double_quote(const char *line, int *i)
{
	int		start;

	(*i)++;
	start = *i;
	while (line[*i] && line[*i] != '"')
		(*i)++;
	if (line[*i] != '"')
	{
		ft_putstr_fd("lexer: unclosed quotes", 2);
		return (NULL);
	}
	(*i)++;
	return (ft_substr(line, start, *i - start -1));
}

char *extract_dollar(const char *line, int *i)
{
	int		start;

	(*i)++;
	start = *i;
	while (line[*i] && (ft_isalnum(line[*i]) || line[*i] == '_'))
		(*i)++;
	return (ft_substr(line, start, *i - start));
}
