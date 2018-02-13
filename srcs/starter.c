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

void start_command(t_env **env, char **args)
{
	int		retcode;
	char	*after_path;

	if (args[0])
	{
		retcode = search_start_builtin(env, args);
		if (retcode == -2)
		{
			if ((after_path = find_cmd_path(env, args[0])))
			{
				free(args[0]);
				args[0] = after_path;
				start_process(env, args);
			}
			else if (access(args[0], F_OK) == 0)
				start_process(env, args);
			else
			{
				ft_miniprint("%l0s%: command not found.\n", args[0]);
			}
		}
	}
}
