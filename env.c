/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:48:57 by acauchy           #+#    #+#             */
/*   Updated: 2018/01/29 15:36:21 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**get_env(char **envp)
{
	static char	**env = {NULL};

	if (envp)
		env = envp;
	return (env);
}

void	print_env(void)
{
	char	**env;
	size_t	i;

	env = get_env(NULL);
	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		++i;
	}
}

char	*read_from_env(char *key)
{
	char	**env;
	size_t	i;
	size_t	j;

	env = get_env(NULL);
	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j])
		{
			if (key[j] != env[i][j])
			{
				if (env[i][j] == '=')
					return (ft_strdup(&env[i][j + 1]));
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
