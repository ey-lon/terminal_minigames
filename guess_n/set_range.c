#include "guess_n.h"

void	ft_gn_range_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  RANGE                     |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'q' to go back       |\n");
	ft_printf("------------------------------\n");
}

int	ft_gn_set_range(int *min, int *max)
{
	ft_gn_range_header();
	if (ft_get_min_max(min, max))
		return (1);
	ft_printf("MIN = [%d]\nMAX = [%d]\n", *min, *max);
	return (0);
}