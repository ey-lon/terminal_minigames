#include "terminal_games.h"

void	ft_terminal_games_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  Terminal Games            |\n");
	ft_printf("|                            |\n");
	ft_printf("|  1. Guess the Number       |\n");
	ft_printf("|  2. TIC-TAC-TOE            |\n");
	//ft_printf("|  3. info                   |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'exit' to quit       |\n");
	ft_printf("------------------------------\n");
}

int main(void)
{
	char	*str;
	int		check;

	check = 0;
	while (1)
	{
		ft_terminal_games_header();
		str = get_next_line(0);
		if (!ft_strncmp("exit\n", str, 5))
			check = -1;
		else if (!ft_strncmp("1\n", str, 2))
			ft_guess_n();
		else if (!ft_strncmp("2\n", str, 2))
			ft_ttt();
		//else if (!ft_strncmp("3\n", str, 2))
		//	ft_info();
		else
			ft_printf("Unknown command.\n");
		if (str)
			free(str);
	}
	return (0);
}
