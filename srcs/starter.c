/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:03:19 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/22 15:19:12 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	replace_exec_name(char **arg, char *newname)
{
	free(*arg);
	*arg = newname;
}

static void	try_start_process(t_env **cmd_env, char **args)
{
	if (is_executable(args[0]))
		start_process(cmd_env, args);
	else
		ft_fminiprint(2, "%l0s%: Permission denied.\n", args[0]);
}

void		start_command(t_env **env, t_env **cmd_env, char **args)
{
	int		retcode;
	char	*after_path;
	int		notfound;

	if (!args[0])
		return ;
	notfound = 1;
	if ((retcode = search_start_builtin(cmd_env, args)) == -2)
	{
		if (ft_strchr(args[0], '/'))
		{
			if (is_there_a_file(args[0]))
				notfound = 0;
		}
		else if ((after_path = find_cmd_path(env, cmd_env, args[0])))
		{
			replace_exec_name(&args[0], after_path);
			notfound = 0;
		}
		if (notfound == 1)
			ft_fminiprint(2, "%l0s%: Command not found.\n", args[0]);
		else
			try_start_process(cmd_env, args);
	}
}
