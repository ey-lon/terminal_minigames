#include "connect_4.h"

void	ft_c4_rules(t_opt opt)
{
	ft_printf("-------------------------------------------------------------\n");
	ft_printf("  RULES\n\n");
	ft_printf("  Connect 4 is played on a %d x %d grid by two players.\n", opt.grid_width, opt.grid_height);
	ft_printf("  The players alternately place the marks %s%c%s and %s%c%s in one of the %d columns in the grid.\n", opt.p_col[1], opt.p_symbol[1], NOCOL, opt.p_col[2], opt.p_symbol[2], NOCOL, opt.grid_width);
	ft_printf("  The first player to get %d of their marks in a row (vertically, horizontally or diagonally) wins.\n", opt.max_marks);
	ft_printf("  When all the squares are full, the game is over.\n");
	ft_printf("-------------------------------------------------------------\n");
}
