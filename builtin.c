/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:06:00 by acauchy           #+#    #+#             */
/*   Updated: 2018/01/29 13:33:06 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_exit(char *input)
{
	(void)input;
	clear_builtins();
	exit (0);
}

int	builtin_pwd(char *input)
{
	char	current_dir[4096];

	(void)input;
	if (!getcwd(current_dir, 4096))
		exit_error("getcwd() error");
	ft_putendl(current_dir);
	return (0);
}

int	builtin_cd(char *input)
{
	char	**split;
	char	*home;

	split = ft_strsplit(input, ' ');
	if (split[1])
		return (chdir(split[1]));
	else
	{
		home = read_from_env("HOME");
		chdir(home);
		free(home);
		return (0);
	}
	return (-1);
}

int	builtin_env(char *input)
{
	(void)input;
	print_env();
	return (0);
}
