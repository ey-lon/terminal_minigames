#include "guess_n.h"

static void	ft_gn_options_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  OPTIONS                   |\n");
	ft_printf("|                            |\n");
	ft_printf("|  1. Range                  |\n");
	ft_printf("|  2. Attempts               |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'q' to go back       |\n");
	ft_printf("------------------------------\n");
}

void	ft_gn_options(t_opt *opt)
{
	char	*str;
	int		check;

	check = 0;
	while (!check)
	{
		ft_gn_options_header();
		str = get_next_line(0);
		if (!ft_strncmp("q\n", str, 2))
			check = -1;
		else if (!ft_strncmp("1\n", str, 2))
			ft_get_range(&(opt->min), &(opt->max));
		else if (!ft_strncmp("2\n", str, 2))
			ft_get_attempts(&(opt->att_lmt));
		else
			ft_printf("Unknown command.\n");
		if (str)
			free(str);
	}
}
