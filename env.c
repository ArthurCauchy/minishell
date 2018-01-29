/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:48:57 by acauchy           #+#    #+#             */
/*   Updated: 2018/01/29 14:01:56 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env(void)
{
	size_t	i;

	i = 0;
	while (environ[i])
	{
		ft_putendl(environ[i]);
		++i;
	}
}

char *read_from_env(char *key)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (environ[i])
	{
		j = 0;
		while (environ[i][j])
		{
			if (key[j] != environ[i][j])	
			{
				if (environ[i][j] == '=')
				{
					return (ft_strdup(&environ[i][j + 1]));
				}
				else
					break ;
			}
			++j;
			if (!key)
				break ;
		}
		++i;
	}
	return (NULL);
}
