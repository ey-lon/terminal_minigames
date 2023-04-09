#include "guess_n.h"

static void	ft_gn_menu_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  Guess the number          |\n");
	ft_printf("|                            |\n");
	ft_printf("|  1. Play                   |\n");
	ft_printf("|  2. Rules                  |\n");
	ft_printf("|  3. Options                |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'q' to go back       |\n");
	ft_printf("------------------------------\n");
}

static void	ft_gn_opt_init(t_opt *opt)
{
	opt->max = 100;
	opt->min = 1;
	opt->att_lmt = 0;
}

int	ft_guess_n(void)
{
	char	*str;
	t_opt	opt;
	int		check;

	ft_gn_opt_init(&opt);
	check = 0;
	while (!check)
	{
		ft_gn_menu_header();
		str = get_next_line(0);
		if (!ft_strncmp("q\n", str, 2))
			check = -1;
		else if (!ft_strncmp("1\n", str, 2))
			ft_gn_game(opt);
		else if (!ft_strncmp("2\n", str, 2))
			ft_gn_rules(opt);
		else if (!ft_strncmp("3\n", str, 2))
			ft_gn_options(&opt);
		else
			ft_printf("Unknown command.\n");
		if (str)
			free(str);
	}
	return (0);
}
