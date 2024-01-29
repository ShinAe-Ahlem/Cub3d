#include "../includes/game.h"

void    check_removed_env(char **env)
{
    if (env[0] == NULL || !*env)
    {
		ft_error(ERROR_ENV_NF);
        exit (EXIT_FAILURE);
    }
}

void    check_partial_removal(char **env)
{
	int	a;
	int	nb_env;	
	int	text_found;

	nb_env = 0;
    a = 0;
	while (env[nb_env])
		nb_env++;
	text_found = 0;
	while (a < nb_env)
	{
		if (ft_strnstr_tf(env[a], "DISPLAY", ft_strlen(env[a])) == 1)
			a++;
		else
		{
			text_found++;
			a++;
		}
	}
	if (text_found == 0)
	{
		ft_error(ERROR_ENV_DISP);
        exit (EXIT_FAILURE);
    }
}

void	check_env(char **env)
{
    check_removed_env(env);
    check_partial_removal(env);
}
