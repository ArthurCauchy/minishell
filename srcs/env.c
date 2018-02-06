/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 10:48:57 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/06 14:51:06 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_env(t_env **env, char **envp)
{
	size_t	i;
	size_t	j;

	(void)env;
	i = 0;
	while (envp[i])
	{
		j = 0;
		while (envp[i][j])
		{
			if (envp[i][j++] == '=')
			{
				set_env(env, ft_strsub(envp[i], 0, j - 1), ft_strdup(&envp[i][j]));
				break ;
			}
		}
		++i;
	}
}

void	print_env(t_env **env)
{
	t_env	*cur;

	cur = *env;
	while (cur)
	{
		ft_miniprint("%l0s%=%l0s%\n", cur->key, cur->value);
		cur = cur->next;
	}
}

char	*read_from_env(t_env **env, char *key)
{
	t_env	*cur;

	cur = *env;
	while (cur)
	{
		if (ft_strcmp(cur->key, key) == 0)
			return (ft_strdup(cur->value));
		cur = cur->next;
	}
	return (NULL);
}
