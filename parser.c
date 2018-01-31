/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 14:20:15 by acauchy           #+#    #+#             */
/*   Updated: 2018/01/31 17:23:13 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int		is_separator(char c)
{
	return (c == ' '
			|| c == '\t'
			|| c == '\n');
}

static int		next_param(char *input, char **args, char *buff, ssize_t *j)
{
	if (*buff == '\0')
		return (*input == '\0' ? 1 : 0);
	args[*j] = ft_strdup(buff);
	if (*input == '\0')
		return (1);
	++*j;
	return (0);
}

static ssize_t	parse_n_copy(char *input, char **args)
{
	static char	buff[INPUT_MAX_LEN];
	size_t		i;
	ssize_t		j;

	i = 0;
	j = 0;
	while (j < PARAMS_MAX - 1)
	{
		if (is_separator(*input) || *input == '\0')
		{
			buff[i] = '\0';
			i = 0;
			if (next_param(input, args, buff, &j) == 1)
				return (j);
		}
		else
			buff[i++] = *input;
		++input;
	}
	return (-1);
}

void			delete_args(char **args)
{
	size_t	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		++i;
	}
	free(args);
}

char			**parse_input(char *input, char **errmsg)
{
	char		**args;
	ssize_t		last_arg_pos;

	if (!(args = (char**)malloc(PARAMS_MAX * sizeof(char*))))
		exit_error("error allocating args array in parse_input()");
	last_arg_pos = parse_n_copy(input, args);
	if (last_arg_pos == -1)
	{
		delete_args(args);
		*errmsg = ft_strdup("Too many arguments.");
		return (NULL);
	}
	args[last_arg_pos + 1] = NULL;
	return (args);
}
