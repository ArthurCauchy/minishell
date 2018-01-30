/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:20:15 by acauchy           #+#    #+#             */
/*   Updated: 2018/01/30 16:07:02 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_separator(char c)
{
	return (c == ' '
			|| c == '\t'
			|| c == '\n');
}

char	**parse_input(char *input)
{
	char	**parsed;
	size_t	i;
	size_t	j;
	size_t	k;
	
	parsed = (char**)malloc(4096 * sizeof(char*));
	i = 0;
	j = 0;
	k = 0;
	while (input[i])
	{
		if (is_separator(input[i]))
		{
			parsed[j][k] = '\0';
			++j;
			k = 0;
		}
		else
			input[j][k] = input[i];
	}
	parsed[j] = NULL;
	return (parsed);
	// si erreur de parsing return NULL
}
