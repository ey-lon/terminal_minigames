#include "utils.h"

//-------------------------------------------------------

static void	ft_get_players_color_header(void)
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

void	ft_get_players_color(char **s1, char **s2)
{
	char	*str;
	int		check;

	check = 0;
	while (!check)
	{
		ft_get_players_color_header();
		str = get_next_line(0);
		if (!ft_strncmp("q\n", str, 2))
			check = -1;
		else if (!ft_strncmp("1\n", str, 2))
		{
			ft_get_color(s1);
			ft_printf("Player 1 = [%s%c%s]\n", *s1, 'x', NOCOL);
		}
		else if (!ft_strncmp("2\n", str, 2))
		{
			ft_get_color(s2);
			ft_printf("Player 2 = [%s%c%s]\n", *s2, 'x', NOCOL);
		}
		else
			ft_printf("Unknown command.\n");
		if (str)
			free(str);
	}
}
