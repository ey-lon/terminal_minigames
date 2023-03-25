#include "guess_n.h"

int	ft_set_min(int *min)
{
	char	*str;

	str = NULL;
	while (1)
	{
		ft_printf("Insert min:\n");
		if (str)
			free(str);
		str = get_next_line(0);
		if (!ft_strncmp("exit\n", str, 5))
		{
			free(str);
			return (1);
		}
		else if (ft_digits_check(str))
		{
			*min = ft_atoi(str);
			free(str);
			break ;
		}
		else
			ft_printf("Invalid argument.\n");
	}
	return (0);
}

int	ft_set_max(int *max, int min)
{
	char	*str;

	str = NULL;
	while (1)
	{
		ft_printf("Insert max:\n");
		if (str)
			free(str);
		str = get_next_line(0);
		if (!ft_strncmp("exit\n", str, 5))
		{
			free(str);
			return (1);
		}
		else if (ft_digits_check(str))
		{
			*max = ft_atoi(str);
			if (*max > min)
			{
				free(str);
				break ;
			}
			else
				ft_printf("MAX must be greater than MIN (%d).\n", min);
		}
		else
			ft_printf("Invalid argument.\n");
	}
	return (0);
}

void	ft_set_range(int *max, int *min)
{
	ft_printf("----------------------------\n");
	ft_printf("|  RANGE                   |\n");
	ft_printf("|                          |\n");
	ft_printf("|  type 'exit' to go back  |\n");
	ft_printf("----------------------------\n");
	if (ft_set_min(min) || ft_set_max(max, *min))
	{
		*min = 1;
		*max = 100;
	}
	ft_printf("MIN = [%d]\nMAX = [%d]\n", *min, *max);
}
