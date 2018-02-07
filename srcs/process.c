#include "minishell.h"

int	start_process(t_env **env, char **args)
{
	pid_t	pid;
	int		status;

	(void)env;
	// avant faut convertir l'env en un char**
	// tester aussi que l'executable est valide
	pid = fork();
	if (pid == -1)
		exit_error("fork() error");
	if (pid == 0)
	{
		if (execve(args[0], args, NULL)) // NULL -> env
			exit_error("execve() error");
	}
	else
	{
		wait(&status);
		if (status == -1)
			exit_error("wait() error");
	}
	// gerer status (arret du child), voir si c'est code d'exit ou signal etc...
	return (0); // et return selon
}
