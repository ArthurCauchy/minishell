/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_manager.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:24:18 by acauchy           #+#    #+#             */
/*   Updated: 2018/01/30 13:50:23 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_builtin	**get_builtins(void)
{
	static t_builtin	*builtins[BUILTIN_MAX] = {NULL};

	return (builtins);
}

/*
** Clear the loaded builtins.
** Has to be performed before exiting to avoir memory leaks.
*/

void				clear_builtins(void)
{
	t_builtin	**builtins;
	int			i;

	builtins = get_builtins();
	i = 0;
	while (i < BUILTIN_MAX && builtins[i] != NULL)
	{
		free(builtins[i]);
		++i;
	}
}

/*
** Loads a new builtin command.
*/

void				load_builtin(char *name, int (*func)(t_env**, char*))
{
	t_builtin	*new;
	t_builtin	**builtins;
	int			i;

	if (!(new = (t_builtin*)malloc(sizeof(t_builtin))))
		exit_error("load_builtin malloc() error");
	new->name = name;
	new->func = func;
	builtins = get_builtins();
	i = 0;
	while (i < BUILTIN_MAX && builtins[i] != NULL)
		++i;
	builtins[i] = new;
}

/*
** Search a builtin correspunding to 'input' param and execute
** the correspunding function.
**
** Returns :
** 0 = ok
** 1 = not a builtin
** -1 = error with the builtin
*/

int					search_start_builtin(t_env **env, char *input)
{
	char		**split;
	t_builtin	**builtins;
	int			i;

	split = ft_strsplit(input, ' ');
	if (!split[0])
		return (0);
	builtins = get_builtins();
	i = 0;
	while (i < BUILTIN_MAX && builtins[i] != NULL)
	{
		if (strcmp(split[0], builtins[i]->name) == 0)
			return (builtins[i]->func(env, input));
		++i;
	}
	free(split);
	return (1);
}