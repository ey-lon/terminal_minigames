#include "utils.h"

int	ft_search_char_at_pos_n(char **mat, char c, int n)
{
	int	y;
	int	x;

	if (!mat || n < 1)
		return (0);
	y = 0;
	while (mat[y] && n > 0)
	{
		x = 0;
		while (mat[y][x] && n > 0)
		{
			n--;
			if (!n)
			{
				if (mat[y][x] == c)
					return (1);
				return (0);
			}
			x++;
		}
		y++;
	}
	return (0);
}

int	ft_set_char_at_pos_n(char **mat, char c, int n)
{
	int	y;
	int	x;

	if (!mat || n < 1)
		return (1);
	y = 0;
	while (mat[y])
	{
		x = 0;
		while (mat[y][x])
		{
			n--;
			if (!n)
			{
				mat[y][x] = c;
				return (0);
			}
			x++;
		}
		y++;
	}
	return (1);
}

int	ft_search_char_in_column_n(char **mat, char c, int n)
{
	int	y;
	int	x;
	int len;

	len = ft_strlen(mat[0]);
	if (!mat || n < 1 || n - 1 > len)
		return (0);
	x = n - 1;
	y = 0;
	while (mat[y])
	{
		if (mat[y][x] == c)
				return (1);
		y++;
	}
	return (0);
}

int	ft_put_char_in_column_n_at_last_pos(char **mat, char c, int n, char pos)
{
	int	y;
	int	x;
	int len;

	len = ft_strlen(mat[0]);
	if (!mat || n < 1 || n - 1 > len)
		return (1);
	y = 0;
	x = n - 1;
	while (mat[y])
	{
		if (mat[y][x] == pos && (!mat[y + 1] || mat[y + 1][x] != pos))
		{
			mat[y][x] = c;
			return (0);
		}
		y++;
	}
	return (1);
}
