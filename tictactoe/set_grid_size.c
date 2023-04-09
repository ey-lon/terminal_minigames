#include "tictactoe.h"

static void	ft_set_size_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  SIZE                      |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'q' to go back       |\n");
	ft_printf("------------------------------\n");
}

void	ft_set_grid_size(int *size)
{
	int		check;

	ft_set_size_header();
	check = 0;
	while (!check)
	{
		ft_printf("Insert the size of the grid:\n");
		if (ft_get_n(size))
			check = -1;
		else if (*size >= GRID_MIN && *size <= GRID_MAX)
			check = 1;
		else
			ft_printf("The size must be between [%d] and [%d]\n", GRID_MIN, GRID_MAX);
	}
	ft_printf("SIZE = [%d] x [%d]\n", *size, *size);
}
