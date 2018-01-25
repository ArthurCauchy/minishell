/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmdline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 13:45:50 by acauchy           #+#    #+#             */
/*   Updated: 2018/01/25 13:59:21 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_cmdline	*str_to_cmdline(char *str)
{
	t_cmdline	*new;
	char		**split;

	if (!(split = ft_strsplit(str, ' ')))
		return (NULL);
	if (!*split)
		return (NULL);
	if (!(new = (t_cmdline*)malloc(sizeof(t_cmdline))))
		return (NULL);	
	return (new);
}
