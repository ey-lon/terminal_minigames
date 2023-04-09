#include "utils.h"

int	ft_get_min(int *min)
{
	int check;

	check = 0;
	while (!check)
	{
		ft_printf("Insert MIN:\n");
		if (ft_get_n(min))
			return (1);
		else
			check = 1;
	}
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
			ft_printf("MAX must be greater than MIN (%d).\n", min);
	}
	return (0);
}

int	ft_get_min_max(int *max, int *min)
{
	int	min_temp;
	int max_temp;

	if (ft_get_min(&min_temp))
		return (1);
	if (ft_get_max(&max_temp, min_temp))
		return (2);
	*min = min_temp;
	*max = max_temp;
	return (0);
}
