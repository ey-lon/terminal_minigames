#include "utils.h"

int	ft_matlen(char **mat)
{
	int	y;

	y = 0;
	if (mat)
	{
		while (mat[y])
			y++;
	}
	return (y);
}

void	ft_free_mat(char **mat)
{
	int	y;

	if (mat)
	{
		y = 0;
		while (mat[y])
		{
			free(mat[y]);
			y++;
		}
		free(mat);
	}
}

char	**ft_mat_create(int max_y, int max_x)
{
	char	**mat;
	int		y;

	mat = malloc(sizeof(char *) * (max_y + 1));
	y = 0;
	while (y < max_y)
	{
		mat[y] = malloc(sizeof(char) * max_x + 1);
		mat[y][max_x] = '\0';
		y++;
	}
	mat[y] = NULL;
	return (mat);
}

void	ft_mat_fill(char **mat, int max_y, int max_x, char c)
{
	int		y;
	int		x;

	y = 0;
	while (y < max_y)
	{
		x = 0;
		while (x < max_x)
		{
			mat[y][x] = c;
			x++;
		}
		y++;
	}
}
