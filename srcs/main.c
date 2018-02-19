/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:03:19 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/12 17:27:35 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
	init_signals();
	init_builtins();
	init_env(&env, envp);
	while ((rep = ask_for_input(&env)))
	{ // TODO check rep merdique (NULL etc)
		args = parse_input(rep, &errmsg);
		if (!args)
		{
			ft_putendl(errmsg);
			free(errmsg);
		}
		else
		{
			free(rep);
			start_command(&env, &env, args);
			delete_args(args);
		}
	}
	return (EXIT_SUCCESS);
}
