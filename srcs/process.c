/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 09:42:57 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/21 17:12:41 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			g_running_proc = -1;

static void	post_process(int status)
{
	if (WIFSIGNALED(status))
	{
		print_sig_error(WTERMSIG(status));
	}
}

int			start_process(t_env **env, char **args)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		exit_error("fork() error");
	if (pid == 0)
	{
		if (execve(args[0], args, env_to_array(env)))
			exit_error("execve() error");
	}
	else
	{
		g_running_proc = pid;
		wait(&status);
		if (status == -1)
			exit_error("wait() error");
		g_running_proc = -1;
		post_process(status);
	}
	return (0);
}
