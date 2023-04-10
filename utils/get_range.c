#include "utils.h"

void	ft_get_range_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  RANGE                     |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'q' to go back       |\n");
	ft_printf("------------------------------\n");
}

int	ft_get_min(int *min)
{
	ft_printf("Insert MIN:\n");
	if (ft_get_n(min))
		return (1);
	return (0);
}

int	ft_get_max(int *max, int min)
{
	int		check;

	check = 0;
	while (!check)
	{
		ft_printf("Insert MAX:\n");
		if (ft_get_n(max))
			return (1);
		else if (*max > min)
			check = 1;
		else
			ft_printf("Error\nMAX must be greater than MIN (%d).\n", min);
	}
	return (0);
}

int	ft_get_range(int *min, int *max)
{
	int	min_temp;
	int max_temp;

	ft_get_range_header();
	if (ft_get_min(&min_temp))
		return (1);
	if (ft_get_max(&max_temp, min_temp))
		return (2);
	*min = min_temp;
	*max = max_temp;
	ft_printf("MIN = [%d]\nMAX = [%d]\n", *min, *max);
	return (0);
}
