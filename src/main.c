#include "guess_n.h"

void	ft_rules(t_opt opt)
{
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("  RULES\n");
	ft_printf("  Guess the number between [%d] and [%d]", opt.min, opt.max);
	if (opt.att_lmt > 0)
		ft_printf(" in no more than [%d] attempts", opt.att_lmt);
	ft_printf(".\n");
	ft_printf("-------------------------------------------------------------\n");
}

void	ft_menu_header(void)
{
	ft_printf("----------------------------\n");
	ft_printf("|  Guess the number        |\n");
	ft_printf("|                          |\n");
	ft_printf("|  1. Play                 |\n");
	ft_printf("|  2. Rules                |\n");
	ft_printf("|  3. Options              |\n");
	ft_printf("|                          |\n");
	ft_printf("|  type 'exit' to quit     |\n");
	ft_printf("----------------------------\n");
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

	ft_opt_init(&opt);
	str = NULL;
	while (1)
	{
		ft_menu_header();
		if (str)
			free(str);
		str = get_next_line(0);
		if (!ft_strncmp("exit\n", str, 5))
		{
			free(str);
			return (0);
		}
		else if (!ft_strncmp("1\n", str, 2))
			ft_game(opt);
		else if (!ft_strncmp("2\n", str, 2))
			ft_rules(opt);
		else if (!ft_strncmp("3\n", str, 2))
			ft_options(&opt);
		else
			ft_printf("Unknown command.\n");
	}
}
