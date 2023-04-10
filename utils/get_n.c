#include "utils.h"

int	ft_get_n(int *n)
{
	char	*str;
	int		check;

	check = 0;
	//ft_printf("(type 'q' to go back.)\n");
	while (!check)
	{
		str = get_next_line(0);
		if (!ft_strncmp("q\n", str, 2))
			check = -1;
		else if (!ft_err_check(str))
		{
			*n = ft_atoi(str);
			check = 1;
		}
		else
			ft_printf("Error\nInvalid argument.\n");
		if (str)
			free(str);
	}
	if (check == -1)
		return (1);
	return (0);
}

int	ft_get_limited_n(int *n, int min, int max)
{
	int check;
	int n_temp;

	check = 0;
	while (!check)
	{
		ft_printf("Insert a number between %d and %d:\n", min, max);
		if (ft_get_n(&n_temp))
			return (1);
		else if (n_temp >= min && n_temp <= max)
			check = 1;
		else
			ft_printf("Error\n");
	}
	*n = n_temp;
	return (0);
}