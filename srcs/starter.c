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
	char	*errmsg;

	errmsg = NULL;
	if (args[0])
	{
		retcode = search_start_builtin(env, args);
		if (retcode == -2)
		{
			if ((after_path = find_cmd_path(env, args[0], &errmsg)))
			{
				free(args[0]);
				args[0] = after_path;
				start_process(env, args);
			}
			else if (is_executable(args[0], &errmsg))
				start_process(env, args);
			else
			{
				ft_putendl_fd(errmsg, 2);
				free(errmsg);
			}
		}
	}
}