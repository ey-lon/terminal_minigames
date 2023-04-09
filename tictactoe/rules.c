#include "tictactoe.h"

void	ft_rules(t_opt opt)
{
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("  RULES\n");
	ft_printf("  Tic-tac-toe is played on a %d x %d grid by two players,\n", opt.size, opt.size);
	ft_printf("  who alternately place the marks %s%c%s and %s%c%s in one of the %d spaces in the grid.\n", opt.p1_col, P1C, NOCOL, opt.p2_col, P2C, NOCOL, opt.size * opt.size);
	ft_printf("  The first player to get %d of their marks in a row (vertically, horizontally or diagonally) is the winner.\n", opt.size);
	ft_printf("  When all the squares are full, the game is over.\n");
	ft_printf("-------------------------------------------------------------\n");
}
