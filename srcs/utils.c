/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:03:19 by acauchy           #+#    #+#             */
/*   Updated: 2018/01/26 12:23:39 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	exit_error(char *errmsg)
{
	if (errmsg)
		ft_putendl_fd(errmsg, 2);
	else
		ft_putendl_fd("error", 2);
	exit(1);
}

int	is_executable(char *filepath, char **errmsg)
{
	if (access(filepath, X_OK) != 0)
	{
		if (access(filepath, F_OK) == 0)
		{
			*errmsg = ft_strjoin(filepath, ": Permission denied.");
			return (0);
		}
		*errmsg = ft_strjoin(filepath, ": Command not found.");
		return (0);
	}
	return (1);
}
