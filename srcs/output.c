/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:35:34 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/20 09:35:35 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_prompt(t_env **env)
{
	char	*user;

	ft_putstr("\033[1;36;40m");
	if ((user = read_from_env(env, "USER")))
		ft_fminiprint(1, "%r0s%'s ", user);
	ft_putstr("minish$ ");
	ft_putstr("\033[0m");
	free(user);
}

void	print_sig_error(int sig)
{
	if (sig == SIGABRT)
		ft_putendl_fd("Abort.", 2);
	else if (sig == SIGBUS)
		ft_putendl_fd("Bus error.", 2);
	else if (sig == SIGFPE)
		ft_putendl_fd("Floating Point Exception.", 2);
	else if (sig == SIGILL)
		ft_putendl_fd("Illegal instruction.", 2);
	else if (sig == SIGSEGV)
		ft_putendl_fd("Segmentation Fault.", 2);
	else if (sig == SIGTERM)
		ft_putendl_fd("Terminated.", 2);
	else if (sig != SIGINT)
		ft_putendl_fd("Unknown fatal signal recieved.", 2);
}
