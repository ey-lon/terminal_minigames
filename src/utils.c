#include "guess_n.h"

int	ft_digits_check(char *str)
{
	int	i;

	if (str)
	{
		if (str[0] == '-' || str[0] == '+' || ft_isdigit(str[0]))
		{
			i = 1;
			while (str[i] != '\n' && str[i])
			{
				if (!ft_isdigit(str[i]))
					return (0);
				i++;
			}
			return (1);
		}
		else
			return (0);
	}
	return (-1);
}

int	ft_exit(char *str)
{
	if (!ft_strncmp("exit\n", str, 5))
	{
		free(str);
		return (1);
	}
	return (0);
}
