/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:23:26 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/10 17:54:06 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char *find_cmd_path(t_env **env, char *cmd)
{
	char	*path;
	char	**split_path;
	char	**cur;

	(void)cmd; // TEMPORARYYYY
	if (!(path = read_from_env(env, "PATH")))
		return (NULL);
	split_path = ft_strsplit(path, ':'); // faire gaffe a un faux path pourri
	cur = split_path;
	while (*cur)
	{
		ft_putendl(*cur);
		// ici faut tenter des trucs avec access()
		++cur;
	}
	return (NULL); // command not found IN PATH
}
