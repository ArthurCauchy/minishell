#include "minishell.h"

void	print_prompt(t_env **env)
{
	char	*user;

	if ((user = read_from_env(env, "USER")))
		ft_miniprint("\033[1;31;40m%r0s%'s ", user);
	ft_putstr("\033[1;33;40mcash$ ");
	ft_putstr("\033[0m");
	free(user);
}
