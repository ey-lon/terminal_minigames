#include "guess_n.h"

void	ft_menu_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  Guess the number          |\n");
	ft_printf("|                            |\n");
	ft_printf("|  1. Play                   |\n");
	ft_printf("|  2. Rules                  |\n");
	ft_printf("|  3. Options                |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'exit' to quit       |\n");
	ft_printf("------------------------------\n");
}

void	ft_opt_init(t_opt *opt)
{
	opt->max = 100;
	opt->min = 1;
	opt->att_lmt = 0;
}

int	main(void)
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
		if (!ft_strncmp("exit\n", str, 5))
			check = -1;
		else if (!ft_strncmp("1\n", str, 2))
			ft_game(opt);
		else if (!ft_strncmp("2\n", str, 2))
			ft_rules(opt);
		else if (!ft_strncmp("3\n", str, 2))
			ft_options(&opt);
		else
			ft_printf("Unknown command.\n");
		if (str)
			free(str);
	}
}
