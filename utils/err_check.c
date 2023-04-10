#include "utils.h"

int	ft_digits_check(char *str)
{
	int	i;

	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (((str[i] == '-' || str[i] == '+') \
		&& (str[i + 1] != '\n' && str[i + 1])) \
		|| ft_isdigit(str[i]))
	{
		i++;
		while (str[i] != '\n' && str[i])
		{
			if (!ft_isdigit(str[i]))
				return (1);
			i++;
		}
		return (0);
	}
	else
		return (1);
}

int	ft_int_limit_check(char *str)
{
	long long	res;
	int			sign;
	int			i;
	int			dig_n;	

	dig_n = 0;
	res = 0;
	sign = 1;
	i = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9' && dig_n <= 11)
	{
		res = res * 10 + str[i] - '0';
		i++;
		dig_n++;
	}
	if (dig_n > 10 || res * sign > INT_MAX || res * sign < INT_MIN)
		return (1);
	return (0);
}

int	ft_err_check(char *str)
{
	if (ft_digits_check(str))
		return (1);
	if (ft_int_limit_check(str))
		return (1);
	return (0);
}

int	ft_arg_check(char *str, int min, int max)
{
	int	check;

	check = 0;
	if (ft_err_check(str))
		check = 2;
	else if (ft_atoi(str) < min)
		check = 3;
	else if (ft_atoi(str) > max)
		check = 4;
	return (check);
}
