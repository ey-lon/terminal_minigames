#include "utils.h"

char	ft_char_at_pos_n(char **mat, int n)
{
	int	y;
	int	x;

	if (!mat || n < 1)
		return (0);
	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			n--;
			if (!n)
				return (mat[y][x]);
			x++;
		}
		y++;
	}
	return (0);
}

void	ft_set_char_at_pos_n(char **mat, int n, char c)
{
	int	y;
	int	x;

	if (!mat || n < 1)
		return ;
	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			n--;
			if (!n)
			{
				mat[y][x] = c;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	ft_print_mat(char **mat)
{
	int	x;
	int	y;
	int	i;
	int	len;

	if (!mat || !mat[0])
		return ;
	y = 0;
	while (mat[y])
	{
		ft_printf("\n\t");
		if (y > 0)
		{
			i = 0;
			len = ft_strlen(mat[y]);
			while (i < len)
			{
				if (i > 0 && i < len)
					ft_printf("+");
				ft_printf("---");
				i++;
			}
			ft_printf("\n\t");
		}
		x = 0;
		while (mat[y][x])
		{
			if (x > 0)
				ft_printf(" |");
			ft_printf(" %c", mat[y][x]);
			x++;
		}
		y++;
	}
	ft_printf("\n\n");
}
