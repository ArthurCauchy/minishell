/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:03:19 by acauchy           #+#    #+#             */
/*   Updated: 2018/01/25 13:26:17 by acauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_prompt(void)
{
	ft_putstr_fd(PROMPT, 1);
}

static void	exit_error(char *errmsg)
{
	if (errmsg)
		ft_putendl_fd(errmsg, 2);
	else
		ft_putendl_fd("error", 2);
	exit(1);
}

static char *ask_for_input(void)
{
	static char	input[4096];
	int			size_read;

	print_prompt();
	size_read = read(0, input, 4096);
	if (size_read == -1)
		exit_error("read() error");
	input[size_read] = '\0';
	if (size_read > 0 && input[size_read - 1] == '\n')
		input[size_read - 1] = '\0';
	return (ft_strdup(input));
}

static void start_process(char *input)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		exit_error("fork() error");
	if (pid == 0)
	{
		execv(input, NULL);
		free(input);
		exit(0);
	}
	else
	{
		wait(&status);
		if (status == -1)
			exit_error("wait() error");
	}
}

int			main(void)
{
	char	*rep;
	
	while ((rep = ask_for_input()))
	{
		if (strcmp(rep, "") == 0)
		{
			free(rep);
			continue;
		}
		if (strcmp(rep, "exit") == 0)
		{
			free(rep);
			break ;
		}
		start_process(rep);
		free(rep);
	}
	return (0);
}
