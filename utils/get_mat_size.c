#include "utils.h"

static void	ft_get_mat_size_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  SIZE                      |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'q' to go back       |\n");
	ft_printf("------------------------------\n");
}

int	ft_get_square_mat_size(int *n, int min, int max)
{
	ft_get_mat_size_header();
	if (ft_get_limited_n(n, min, max))
		return (1);
	ft_printf("SIZE = [%d] x [%d]\n", *n, *n);
	return (0);
}

int	ft_get_mat_size(int *x, int *y, int min, int max)
{
	int		check;
	int		y_temp;
	int		x_temp;

	check = 0;
	//ft_get_mat_size_header();
	ft_printf("Insert the WIDTH(x)\n");
	if (!ft_get_limited_n(&x_temp, min, max))
	{
		ft_printf("Insert the HEIGHT(y)\n");
		if (!ft_get_limited_n(&y_temp, min, max))
			check = 1;
	}
	if (!check)
		return (1);
	*x = x_temp;
	*y = y_temp;
	ft_printf("SIZE = [%d] x [%d]\n", *x, *y);
	return (0);
}