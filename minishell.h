/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:10:52 by acauchy           #+#    #+#             */
/*   Updated: 2018/01/26 14:25:00 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __MINISHELL_H
# define __MINISHELL_H

# include <sys/types.h>
# include <sys/wait.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

# define PROMPT "segvsh$ "
# define BUILTIN_MAX 42

typedef struct 		s_cmdline
{
	char	*command;
	char	**args;
}					t_cmdline;

typedef struct		s_builtin
{
	char	*name;
	int		(*func)(char*);
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
** builtin.c
*/

int					builtin_exit(char *input);
int					builtin_pwd(char *input);
int					builtin_cd(char *input);

/*
** builtin_manager.c
*/

void				clear_builtins(void);
void				load_builtin(char *name, int (*func)(char*));
int					search_start_builtin(char *input);

#endif
