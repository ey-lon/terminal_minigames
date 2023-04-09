#include "tictactoe.h"

//rows------------------------------------------------------------------------

static char	ft_row_check(char **mat)
{
	int		x;
	int		y;
	char	temp;
	int		check;

	if (!mat || !mat[0] || !mat[0][0])
		return (0);
	y = 0;
	while (mat[y])
	{
		temp = mat[y][0];
		check = 0;
		x = 0;
		while (mat[y][x] && !check && temp != FREE)
		{
			if (mat[y][x] != temp)
				check = 1;
			x++;
		}
		if (!check && temp != FREE)
			return (temp);
		y++;
	}
	return (0);
}

//columns---------------------------------------------------------------------

static char	ft_column_check(char **mat)
{
	int		x;
	int		y;
	char	temp;
	int		check;

	if (!mat || !mat[0] || !mat[0][0])
		return (0);
	x = 0;
	while (mat[0][x])
	{
		temp = mat[0][x];
		check = 0;
		y = 0;
		while (mat[y] && !check && temp != FREE)
		{
			if (mat[y][x] != temp)
				check = 1;
			y++;
		}
		if (!check && temp != FREE)
			return (temp);
		x++;
	}
	return (0);
}

//diagonal_1------------------------------------------------------------------

static char	ft_diag1_check(char **mat)
{
	int		x;
	int		y;
	char	temp;
	int		check;

	if (!mat || !mat[0] || !mat[0][0])
		return (0);
	temp = mat[0][0];
	check = 0;
	y = 0;
	x = 0;
	while (mat[y] && mat[y][x] && !check && temp != FREE)
	{
		if (mat[y][x] != temp)
			check = 1;
		y++;
		x++;
	}
	if (!check && temp != FREE)
		return (temp);
	return (0);
}

//diagonal_2------------------------------------------------------------------

static char	ft_diag2_check(char **mat)
{
	int		x;
	int		y;
	char	temp;
	int		check;

	if (!mat || !mat[0] || !mat[0][0])
		return (0);
	x = ft_strlen(mat[0]) - 1;
	temp = mat[0][x];
	check = 0;
	y = 0;
	while (mat[y] && x >= 0 && !check && temp != FREE)
	{
		if (mat[y][x] != temp)
			check = 1;
		y++;
		x--;
	}
	if (!check && temp != FREE)
		return (temp);
	return (0);
}

//win_check------------------------------------------------------------------

char	ft_win_check(char **mat)
{
	char	temp;

	if (!mat || !mat[0] || !mat[0][0])
		return (0);
	//rows------------------------------------------------------------------------
	temp = ft_row_check(mat);
	if (temp)
		return (temp);
	//columns---------------------------------------------------------------------
	temp = ft_column_check(mat);
	if (temp)
		return (temp);
	//diagonal_1------------------------------------------------------------------
	temp = ft_diag1_check(mat);
	if (temp)
		return (temp);
	//diagonal_2------------------------------------------------------------------
	temp = ft_diag2_check(mat);
	if (temp)
		return (temp);
	return (0);
}
