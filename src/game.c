#include "guess_n.h"

int	ft_check_n(int n, int nbr, int att)
{
	if (nbr == n)
	{
		ft_printf("Congrats! You Won in %d attempts.\n", att);
		return (1);
	}
	else if (nbr > n)
		ft_printf("The number to find is smaller\n");
	else if (nbr < n)
		ft_printf("The number to find is greater\n");
	return (0);
}

void	ft_game(t_opt opt)
{
	char		*str;
	int			n;
	int			att;

	ft_printf("GAME ON!\n");
	str = NULL;
	att = 0;
	n = rand() % (opt.max + 1 - opt.min) + opt.min;
	while (1)
	{
		att++;
		if (str)
			free(str);
		str = get_next_line(0);
		if (!ft_strncmp("exit\n", str, 5))
		{
			free(str);
			ft_printf("You gave up!\n");
			break ;
		}
		else if (ft_digits_check(str))
		{
			if (ft_check_n(n, ft_atoi(str), att))
			{
				free(str);
				break ;
			}
			ft_printf("attempts = %d\n", att);
		}
		else
			ft_printf("Invalid argument.\n");
		if (opt.att_lmt > 0 && att == opt.att_lmt)
		{
			free(str);
			ft_printf("You Lose! Too many attempts.\n");
			break ;
		}
	}
}
