#include "utils.h"

void	ft_get_color_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  COLOR                     |\n");
	ft_printf("|                            |\n");
	ft_printf("|  1. RED                    |\n");
	ft_printf("|  2. GREEN                  |\n");
	ft_printf("|  3. YELLOW                 |\n");
	ft_printf("|  4. BLUE                   |\n");
	ft_printf("|  5. PURPLE                 |\n");
	ft_printf("|  6. CYAN                   |\n");
	ft_printf("|  7. WHITE                  |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'q' to go back       |\n");
	ft_printf("------------------------------\n");
}

int	ft_get_color(char **color)
{
	char	*str;
	int		check;

	ft_get_color_header();
	check = 0;
	while (!check)
	{
		check = 1;
		str = get_next_line(0);
		if (!ft_strncmp("q\n", str, 2))
			return (1);
		else if (!ft_strncmp("1\n", str, 2))
			*color = RED;
		else if (!ft_strncmp("2\n", str, 2))
			*color = GREEN;
		else if (!ft_strncmp("3\n", str, 2))
			*color = YELLOW;
		else if (!ft_strncmp("4\n", str, 2))
			*color = BLUE;
		else if (!ft_strncmp("5\n", str, 2))
			*color = PURPLE;
		else if (!ft_strncmp("6\n", str, 2))
			*color = CYAN;
		else if (!ft_strncmp("7\n", str, 2))
			*color = WHITE;
		else
			check = ft_printf("Unknown command.\n") * 0;
		if (str)
			free(str);
	}
	return (0);
}