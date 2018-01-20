/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:03:19 by acauchy           #+#    #+#             */
/*   Updated: 2018/01/20 12:29:14 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_prompt(void)
{
	ft_putstr_fd(PROMPT, 1);
}

static char *read_input(void)
{
	static char	input[4096];
	size_t		size_read = 0;

	size_read = read(0, input, 4096);
	/*if (size_read == -1)
		exit_error("error: read");*/
	input[size_read] = '\0';
	return (ft_strdup(input));
}

int			main(void)
{
	print_prompt();
	ft_putendl(read_input());
	return (0);
}
