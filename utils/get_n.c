#include "utils.h"

int	ft_get_n(int *n)
{
	char	*str;
	int		check;

	check = 0;
	while (!check)
	{
		str = get_next_line(0);
		if (!ft_strncmp("q\n", str, 2))
			return (1);
		else if (!ft_err_check(str))
		{
			*n = ft_atoi(str);
			check = 1;
		}
		else
			ft_printf("Invalid argument.\n");
		if (str)
			free(str);
	}
	return (0);
}