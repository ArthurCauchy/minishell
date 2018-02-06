/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_pwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:06:00 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/06 16:18:37 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin_pwd(t_env **env, char **args)
{
	char	current_dir[MAX_PATH_SIZE];

	(void)env;
	(void)args;
	if (!getcwd(current_dir, MAX_PATH_SIZE))
		exit_error("getcwd() error");
	ft_putendl(current_dir);
	return (0);
}
