/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_env.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:06:00 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/20 14:53:18 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	add_to_tmp_env(t_env **env, char *str)
{
	char		*eq_char;

	eq_char = ft_strchr(str, '=');
	set_env(env, ft_strsub(str, 0, eq_char - str), ft_strdup(eq_char + 1));
}

int			builtin_env(t_env **env, char **args)
{
	t_env	*tmp_env;
	int		i;

	if (args[1] && ft_strcmp("-i", args[1]) == 0)
	{
		i = 2;
		tmp_env = NULL;
	}
	else
	{
		i = 1;
		tmp_env = copy_env(env);
	}
	while (args[i] && ft_strchr(args[i], '='))
	{
		add_to_tmp_env(&tmp_env, args[i]);
		++i;
	}
	if (args[i])
		start_command(env, &tmp_env, args + i);
	else
		print_env(&tmp_env);
	clear_env(tmp_env);
	return (0);
}
