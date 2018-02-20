/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:37:26 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/20 09:37:28 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ask_for_input(t_env **env)
{
	static char	input[INPUT_MAX_LEN];
	int			size_read;

	print_prompt(env);
	size_read = read(0, input, INPUT_MAX_LEN - 1);
	if (size_read == -1)
		exit_error("read() error");
	input[size_read] = '\0';
	if (size_read > 0 && input[size_read - 1] == '\n')
		input[size_read - 1] = '\0';
	return (ft_strdup(input));
}
