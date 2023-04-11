#include "tictactoe.h"

static void	ft_ttt_options_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  OPTIONS                   |\n");
	ft_printf("|                            |\n");
	ft_printf("|  1. Grid size              |\n");
	ft_printf("|  2. Players colors         |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'q' to go back       |\n");
	ft_printf("------------------------------\n");
}

 void	ft_ttt_options(t_opt *opt)
{
	char	*str;
	int		check;

	check = 0;
	while (!check)
	{
		ft_ttt_options_header();
		str = get_next_line(0);
		if (!ft_strncmp("q\n", str, 5))
			check = -1;
		else if (!ft_strncmp("1\n", str, 2))
			ft_get_square_mat_size(&opt->size, GRID_MIN, GRID_MAX);
		else if (!ft_strncmp("2\n", str, 2))
			ft_get_players_color(&opt->p1_col, &opt->p2_col);
		else
			ft_printf("Unknown command.\n");
		if (str)
			free(str);
	}
}
