/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 12:23:26 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/12 17:15:33 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*try_access_indir(char *dir, char *cmd)
{
	char	*tmp;

	// virer les '/' en trop a la fin peut-etre ?
	tmp = ft_strjoin(dir, "/");
	tmp = ft_strjoin_free(tmp, ft_strdup(cmd));
	if (access(tmp, X_OK) == 0)
		return (tmp);
	free(tmp);
	return (NULL);
}

static void	free_splited_path(char **array)
{
	char **cur;

	cur = array;
	while (*cur)
	{
		free(*cur);
		++cur;
	}
	free(array);
}


char		*find_cmd_path(t_env **env, char *cmd)
{
	char	*path;
	char	**split_path;
	char	**cur;
	char	*ret;

	if (!(path = read_from_env(env, "PATH")))
		return (NULL);
	ret = NULL;
	split_path = ft_strsplit(path, ':'); // faire gaffe a un faux path pourri
	cur = split_path;
	while (*cur)
	{
		if ((ret = try_access_indir(*cur, cmd)))
			break ;
		++cur;
	}
	free_splited_path(split_path);
	free(path);
	return (ret); // command not found IN PATH
}
