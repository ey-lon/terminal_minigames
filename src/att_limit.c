#include "guess_n.h"

void	ft_attempts_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  ATTEMPTS                  |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'exit' to go back    |\n");
	ft_printf("------------------------------\n");
}

void	ft_att_status(int *n)
{
	if (*n > 0)
		ft_printf("ATTEMPTS = [%d]\n", *n);
	else
	{
		*n = 0;
		ft_printf("ATTEMPTS = [Unlimited]\n");
	}
}

void	ft_set_attempts(int *n)
{
	char	*str;
	int		check;

	ft_attempts_header();
	check = 0;
	while (!check)
	{
		ft_printf("Insert the maximum number of attempts:\n");
		str = get_next_line(0);
		if (!ft_strncmp("exit\n", str, 5))
			check = -1;
		else if (!ft_err_check(str))
		{
			*n = ft_atoi(str);
			check = 1;
		}
		else
			ft_printf("Invalid argument.\n");
		if (str)
			free(str);
	}
	ft_att_status(n);
}
