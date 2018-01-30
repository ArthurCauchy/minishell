/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:06:00 by acauchy           #+#    #+#             */
/*   Updated: 2018/01/30 13:52:37 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_cd(t_env **env, char *input)
{
	char	**split;
	char	*home;

	split = ft_strsplit(input, ' ');
	if (split[1])
		return (chdir(split[1]));
	else
	{
		if (!(home = read_from_env(env, "HOME")))
		{
			ft_putendl_fd("No directory is given and HOME empty"
					" or undefined. CWD unchanged.", 2);
			return (-1);
		}
		chdir(home);
		free(home);
		return (0);
	}
	return (-1);
}
