/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_env.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 11:03:45 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/05 12:45:57 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_env	*create_entry(char *key, char *value)
{
	t_env	*new;

	if (!(new = (t_env*)malloc(sizeof(t_env))))
		exit_error("env create_entry() malloc error");
	if (!(new->key = key))
		exit_error("env create_entry() 'key' malloc error");
	if (!(new->value = value))
		exit_error("env create_entry() 'value' malloc error");
	new->next = NULL;
	return (new);
}

void			clear_env(t_env *env)
{
	t_env	*prev;

	prev = NULL;
	while (env)
	{
		prev = env;
		env = env->next;
		free(prev->key);
		free(prev->value);
		free(prev);
	}
}

void			set_env(t_env **head, char *key, char *value)
{
	t_env	*new_entry;
	t_env	*cur;

	if (!*head)
	{
		*head = create_entry(key, value);
		return ;
	}
	cur = *head;
	while (cur)
	{
		if (ft_strcmp(cur->key, key) == 0)
		{
			free(key);
			free(cur->value);
			cur->value = value;
			return ;
		}
		if (!cur->next)
		{
			new_entry = create_entry(key, value);
			cur->next = new_entry;
			return ;
		}
		cur = cur->next;
	}
}

void			unset_env(t_env *head, char *key)
{
	t_env	*cur;
	t_env	*prev;
	t_env	*tmp;

	cur = head;
	prev = NULL;
	while (cur)
	{
		if (ft_strcmp(cur->key, key) == 0)
		{
			if (prev)
				prev->next = cur->next;
			tmp = cur->next;
			free(cur->key);
			free(cur->value);
			free(cur);
			cur = tmp;
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
