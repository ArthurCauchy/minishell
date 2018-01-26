#include "minishell.h"

int	builtin_exit(char *input)
{
	(void)input;
	clear_builtins();
	exit (0);
}

int	builtin_pwd(char *input)
{
	char	current_dir[4096];

	(void)input;
	if (!getcwd(current_dir, 4096))
		exit_error("getcwd() error");
	ft_putendl(current_dir);
	return (0);
}

int	builtin_cd(char *input)
{
	char	**split;

	split = ft_strsplit(input, ' ');
	if (split[1])
		return (chdir(split[1]));
	else
	{
		ft_putendl("must cd home");
		return (0);
	}
	return (-1);
}
