#include "utils.h"

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