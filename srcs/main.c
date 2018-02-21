/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:03:19 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/21 14:57:27 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env		**g_envptr = NULL;

static void	init_minishell(t_env **env, char **envp)
{
	init_signals();
	init_builtins();
	init_env(env, envp);
	g_envptr = env;
}

int			main(int argc, char **argv, char **envp)
{
	char	*rep;
	char	*errmsg;
	char	**args;
	t_env	*env;

	(void)argc;
	(void)argv;
	env = NULL;
	args = NULL;
	errmsg = NULL;
	init_minishell(&env, envp);
	while (42)
	{
		rep = ask_for_input(0, &env, &errmsg);
		if (errmsg)
		{
			ft_putendl_fd(errmsg, 2);
			free(errmsg);
			errmsg = NULL;
			free(rep);//bof bof
			continue ;//bof bof 2
		}
		args = parse_input(rep, &errmsg);
		if (!args)
		{
			ft_putendl_fd(errmsg, 2);
			free(errmsg);
			errmsg = NULL;
		}
		free(rep);
		if (args)
		{
			start_command(&env, &env, args);
			delete_args(args);
		}
	}
	return (EXIT_SUCCESS);
}
