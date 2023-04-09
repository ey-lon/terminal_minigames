#include "tictactoe.h"

//-------------------------------------------------------

static void	ft_set_players_color_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  COLOR                     |\n");
	ft_printf("|                            |\n");
	ft_printf("|  1. Player 1 COLOR         |\n");
	ft_printf("|  2. Player 2 COLOR         |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'q' to go back       |\n");
	ft_printf("------------------------------\n");
}

void	ft_set_players_color(t_opt *opt)
{
	char	*str;
	int		check;

	check = 0;
	while (!check)
	{
		ft_set_players_color_header();
		str = get_next_line(0);
		if (!ft_strncmp("q\n", str, 2))
			check = -1;
		else if (!ft_strncmp("1\n", str, 2))
		{
			ft_get_color(&opt->p1_col);
			ft_printf("Player 1 = [%s%c%s]\n", opt->p1_col, P1C, NOCOL);
		}
		else if (!ft_strncmp("2\n", str, 2))
		{
			ft_get_color(&opt->p2_col);
			ft_printf("Player 2 = [%s%c%s]\n", opt->p2_col, P2C, NOCOL);
		}
		else
			ft_printf("Unknown command.\n");
		if (str)
			free(str);
	}
}
