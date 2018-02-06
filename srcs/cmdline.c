/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:45:50 by acauchy           #+#    #+#             */
/*   Updated: 2018/01/26 10:29:26 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdline	*str_to_cmdline(char *str)
{
	t_cmdline	*new;
	char		**split;

	if (!(split = ft_strsplit(str, ' ')))
		return (NULL);
	if (!split[0])
		return (NULL);
	if (!(new = (t_cmdline*)malloc(sizeof(t_cmdline))))
		return (NULL);
	new->command = split[0];
	new->args = &split[0];
	return (new);
}
