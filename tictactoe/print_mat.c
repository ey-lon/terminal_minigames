#include "tictactoe.h"

static void ft_ttt_print_line(char *str)
{
	int x;
	int len;

	x = 0;
	len = ft_strlen(str);
	while (x < len)
	{
		if (x > 0 && x < len)
			ft_printf("+");
		ft_printf("---");
		x++;
	}
	ft_printf("\n\t");
}

void	ft_ttt_print_mat(char **mat, t_opt *opt)
{
	int	x;
	int	y;
	int	square;

	if (!mat || !mat[0])
		return ;
	square = 1;
	y = 0;
	while (mat[y])
	{
		ft_printf("\n\t");
		if (y > 0)
			ft_ttt_print_line(mat[y]);
		x = 0;
		while (mat[y][x])
		{
			if (x > 0)
				ft_printf("|");
			if (mat[y][x] == P1C)
				ft_printf("%s %c %s", opt->p1_col, mat[y][x], NOCOL);
			else if (mat[y][x] != FREE)
				ft_printf("%s %c %s", opt->p2_col, mat[y][x], NOCOL);
			else if (square > 9)
				ft_printf("%s%-3d%s", BLACK, square, NOCOL);
			else
				ft_printf("%s %d %s", BLACK, square, NOCOL);
			x++;
			square++;
		}
		y++;
	}
	ft_printf("\n\n");
}