#include "minishell.h"

int g_running_proc = -1;

static void	post_process(int status)
{
	if (WIFSIGNALED(status))
	{
		print_sig_error(WTERMSIG(status));
	}
}

int					start_process(t_env **env, char **args)
{
	pid_t	pid;
	int		status;

	(void)env;
	// avant il faudrait tester que l'executable est valide
	pid = fork();
	if (pid == -1)
		exit_error("fork() error");
	if (pid == 0)
	{
		if (execve(args[0], args, env_to_array(env))) // NULL -> env
			exit_error("execve() error");
	}
	else
	{
		g_running_proc = pid;
		wait(&status);
		if (status == -1)
			exit_error("wait() error");
		g_running_proc = -1;
	}
	post_process(status);
	// gerer status (arret du child), voir si c'est code d'exit ou signal etc...
	return (0); // et return selon
}
