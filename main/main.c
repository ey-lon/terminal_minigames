#include "terminal_games.h"

void	ft_terminal_games_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  Terminal Games            |\n");
	ft_printf("|                            |\n");
	ft_printf("|  1. GUESS THE NUMBER       |\n");
	ft_printf("|  2. TIC-TAC-TOE            |\n");
	ft_printf("|  3. CONNECT 4              |\n");
	//ft_printf("|  0. info                   |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'exit' to quit       |\n");
	ft_printf("------------------------------\n");
}

int main(void)
{
	char	*str;
	int		check;
	
	check = 0;
	while (!check)
	{
		ft_terminal_games_header();
		str = get_next_line(0);
		//if (!ft_strncmp("0\n", str, 2))
		//	ft_info();
		//else
		if (!ft_strncmp("exit\n", str, 5))
			check = -1;
		else if (!ft_strncmp("1\n", str, 2))
			ft_guess_n();
		else if (!ft_strncmp("2\n", str, 2))
			ft_tictactoe();
		else if (!ft_strncmp("3\n", str, 2))
			ft_connect_4();
		else
			ft_printf("Unknown command.\n");
		if (str)
			free(str);
	}
	return (0);
}
