#include "tictactoe.h"

static void	ft_menu_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  TicTacToe                 |\n");
	ft_printf("|                            |\n");
	ft_printf("|  1. Player vs CPU          |\n");
	ft_printf("|  2. Player vs Player       |\n");
	ft_printf("|  3. Rules                  |\n");
	ft_printf("|  4. Options                |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'q' to go back       |\n");
	ft_printf("------------------------------\n");
}

static void ft_opt_init(t_opt *opt)
{
	opt->size = 3;
	opt->p1_col = NOCOL;
	opt->p2_col = NOCOL;
}

int	ft_ttt(void)
{
	char	*str;
	t_opt	opt;
	int		check;

	ft_opt_init(&opt);
	check = 0;
	while (!check)
	{
		ft_menu_header();
		str = get_next_line(0);
		if (!ft_strncmp("q\n", str, 2))
			check = -1;
		else if (!ft_strncmp("1\n", str, 2))
			ft_pve(opt);
		else if (!ft_strncmp("2\n", str, 2))
			ft_pvp(opt);
		else if (!ft_strncmp("3\n", str, 2))
			ft_rules(opt);
		else if (!ft_strncmp("4\n", str, 2))
			ft_options(&opt);
		else
			ft_printf("Unknown command.\n");
		if (str)
			free(str);
	}
	return (0);
}
