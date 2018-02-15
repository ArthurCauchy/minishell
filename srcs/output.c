#include "minishell.h"

void	print_prompt(t_env **env)
{
	char	*user;

	ft_putstr("\033[1;36;40m");
	if ((user = read_from_env(env, "USER")))
		ft_miniprint("%r0s%'s ", user);
	ft_putstr("minish$ ");
	ft_putstr("\033[0m");
	free(user);
}
