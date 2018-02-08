/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:03:19 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/08 12:33:19 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			main(int argc, char **argv, char **envp)
{
	char	*rep;
	char	*errmsg;
	char	**args;
	int		retcode;
	t_env	*env;

	(void)argc;
	(void)argv;
	env = NULL;
	args = NULL;
	load_builtin("exit", &builtin_exit);
	load_builtin("pwd", &builtin_pwd);
	load_builtin("cd", &builtin_cd);
	load_builtin("env", &builtin_env);
	load_builtin("setenv", &builtin_setenv);
	load_builtin("unsetenv", &builtin_unsetenv);
	load_builtin("echo", &builtin_echo);
	init_env(&env, envp);
	while ((rep = ask_for_input(&env)))
	{
		args = parse_input(rep, &errmsg);
		if (!args)
		{
			ft_putendl(errmsg);
			free(errmsg);
		}
		free(rep);
		if (args)
		{
			if (args[0])
			{
				retcode = search_start_builtin(&env, args);
				if (retcode == -2)
				{
					ft_putendl("Not a builtin, should start a process.");
					start_process(&env, args);
				}
			}
			delete_args(args);
		}
	}
	return (EXIT_SUCCESS);
}
