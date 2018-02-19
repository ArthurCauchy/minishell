/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   starter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:03:19 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/12 17:27:35 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void start_command(t_env **env, t_env **cmd_env, char **args)
{
	int		retcode;
	char	*after_path;

	if (args[0])
	{
		retcode = search_start_builtin(cmd_env, args);
		if (retcode == -2)
		{
			if (ft_strchr(args[0], '/'))
			{
				if (!is_there_a_file(args[0]))
				{
					ft_fminiprint(2, "%l0s%: Command not found.\n", args[0]);
					return ;
				}
			}
			else
			{
				if ((after_path = find_cmd_path(env, cmd_env, args[0])))
				{
					free(args[0]);
					args[0] = after_path;
				}
				else
				{
					ft_fminiprint(2, "%l0s%: Command not found.\n", args[0]);
					return ;
				}
			}
			if (is_executable(args[0]))
				start_process(cmd_env, args);
			else
					ft_fminiprint(2, "%l0s%: Permission denied.\n", args[0]);
		}
	}
}
