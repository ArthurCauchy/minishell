/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:10:52 by acauchy           #+#    #+#             */
/*   Updated: 2018/01/30 13:59:36 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_H
# define __MINISHELL_H

# include <stdio.h>

# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define PROMPT "segvsh$ "
# define BUILTIN_MAX 42

typedef struct		s_cmdline
{
	char	*command;
	char	**args;
}					t_cmdline;

typedef struct		s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct		s_builtin
{
	char	*name;
	int		(*func)(t_env**, char*);
}					t_builtin;

/*
** cmdline.c
*/

t_cmdline			*str_to_cmdline(char *str);

/*
** utils.c
*/

void				exit_error(char *errmsg);

/*
** builtin_manager.c
*/

void				clear_builtins(void);
void				load_builtin(char *name, int (*func)(t_env**, char*));
int					search_start_builtin(t_env **env, char *input);

/*
** builtin_[builtin_name].c
*/

int					builtin_exit(t_env **env, char *input);
int					builtin_pwd(t_env **env, char *input);
int					builtin_cd(t_env **env, char *input);
int					builtin_env(t_env **env, char *input);

/*
** s_env.c
*/

void				clear_env(t_env *env);
void				unset_env(t_env *head, char *key);
void				set_env(t_env **head, char *key, char *value);

/*
** env.c
*/

void				init_env(t_env **env, char **envp);
void				print_env(t_env **env);
char				*read_from_env(t_env **env, char *key);

#endif
