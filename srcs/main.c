/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acauchy <acauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 12:03:19 by acauchy           #+#    #+#             */
/*   Updated: 2018/02/05 13:02:30 by arthur           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	print_prompt(void)
{
	ft_putstr_fd(PROMPT, 1);
}

static char	*ask_for_input(void)
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

/*static void start_process(char *input)
{
	pid_t		pid;
	int			status;
	t_cmdline	*cmdline;

	pid = fork();
	if (pid == -1)
		exit_error("fork() error");
	if (pid == 0)
	{
		cmdline = str_to_cmdline(input);
		ft_putendl(cmdline->command);
		ft_putendl(cmdline->args[0]);
		execve(cmdline->command, cmdline->args, NULL);
		exit(0);
	}
	else
	{
		wait(&status);
		if (status == -1)
			exit_error("wait() error");
	}
}*/

int			main(int argc, char **argv, char **envp)
{
	char	*rep;
	char	*errmsg;
	char	**args;
	int		retcode;
	t_env	*env;

	(void)argc;
	(void)argv;
	env = NULL;
	load_builtin("exit", &builtin_exit);
	load_builtin("pwd", &builtin_pwd);
	load_builtin("cd", &builtin_cd);
	load_builtin("env", &builtin_env);
	load_builtin("setenv", &builtin_setenv);
	load_builtin("unsetenv", &builtin_unsetenv);
	init_env(&env, envp);
	while ((rep = ask_for_input()))
	{
		if (!(args = parse_input(rep, &errmsg)))
		{
			ft_putendl(errmsg);
			free(errmsg);
		}
		free(rep);
		if (args)
		{
			retcode = search_start_builtin(&env, args);
			if (retcode == 1)
			{
				ft_putendl("Not a builtin, should start a process.");
				//start_process(rep);
			}
			delete_args(args);
		}
	}
	return (EXIT_SUCCESS);
}
