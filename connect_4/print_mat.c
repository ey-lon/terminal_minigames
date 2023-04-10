#include "connect_4.h"

static void ft_c4_print_line(char c, int len)
{
	int x;

	x = 0;
	ft_printf("\t|");
	while (x < len)
	{
		if (x > 0 && x < len)
			ft_printf("%c", c);
		ft_printf("---");
		x++;
	}
	ft_printf("|\n");
}

static void	ft_c4_print_columns_n(int len)
{
	int	x;

	x = 0;
	ft_printf("\t ");
	while (x < len)
	{
		if(x > 0)
			ft_printf("|");
		x++;
		if (x > 9)
			ft_printf("%s%-3d%s", BLACK, x, NOCOL);
		else
			ft_printf("%s %d %s", BLACK, x, NOCOL);
	}
	ft_printf("\n");
}

void	ft_c4_print_mat(char **mat, t_opt *opt)
{
	int	x;
	int	y;
	int len;

	if (!mat || !mat[0])
		return ;
	len = ft_strlen(mat[0]);
	ft_printf("\n");
	ft_c4_print_columns_n(len);
	ft_c4_print_line('-', len);
	y = 0;
	while (mat[y])
	{
		if (y > 0)
			ft_c4_print_line('+', len);
		x = 0;
		ft_printf("\t");
		while (mat[y][x])
		{
			ft_printf("|");
			if (mat[y][x] == P1C)
				ft_printf("%s %c %s", opt->p1_col, mat[y][x], NOCOL);
			else if (mat[y][x] != FREE)
				ft_printf("%s %c %s", opt->p2_col, mat[y][x], NOCOL);
			else
				ft_printf("   ");
			x++;
		}
		ft_printf("|\n");
		y++;
	}
	ft_c4_print_line('-', len);
	ft_printf("\n");
}