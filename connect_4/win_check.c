#include "connect_4.h"

//rows------------------------------------------------------------------------

static char	ft_c4_row_check(char **mat, int max_marks)
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
		check = 0;
		x = 0;
		while (mat[y][x])
		{
			if (!check)
				temp = mat[y][x];
			if (temp != FREE)
			{
				if (mat[y][x] == temp)
					check++;
				else
					check = 0;
				if (check == max_marks)
					return (temp);
			}
			x++;
		}
		y++;
	}
	return (0);
}

//columns---------------------------------------------------------------------

static char	ft_c4_column_check(char **mat, int max_marks)
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
		check = 0;
		y = 0;
		while (mat[y])
		{
			if (!check)
				temp = mat[y][x];
			if (temp != FREE)
			{
				if (mat[y][x] == temp)
					check++;
				else
					check = 0;
				if (check == max_marks)
					return (temp);
			}
			y++;
		}
		x++;
	}
	return (0);
}

//diagonal_1------------------------------------------------------------------

static char	ft_c4_diag1_check(char **mat, int max_marks)
{
	int		x;
	int		y;
	char	temp;
	int		check;

	if (!mat || !mat[0] || !mat[0][0])
		return (0);
	check = 0;
	y = 0;
	x = 0;
	while (mat[y] && mat[y][x])
	{
		if (!check)
			temp = mat[y][x];
		if (temp != FREE)
		{
			if (mat[y][x] == temp)
				check++;
			else
				check = 0;
			if (check == max_marks)
				return (temp);
		}
		y++;
		x++;
	}
	return (0);
}

//diagonal_2------------------------------------------------------------------

static char	ft_c4_diag2_check(char **mat, int max_marks, int x)
{
	int		y;
	char	temp;
	int		check;

	if (!mat || !mat[0] || !mat[0][0])
		return (0);
	check = 0;
	y = 0;
	while (mat[y] && x >= 0)
	{
		if (!check)
			temp = mat[y][x];
		if (temp != FREE)
		{
			if (mat[y][x] == temp)
				check++;
			else
				check = 0;
			if (check == max_marks)
				return (temp);
		}
		y++;
		x--;
	}
	return (0);
}

//diagonal_call---------------------------------------------------------------

char	ft_c4_call_diag1_check(char **mat, int max_marks)
{
	int		x;
	int		y;
	char	temp;
	char	**ptr;

	if (!mat || !mat[0] || !mat[0][0])
		return (0);
	temp = 0;
	y = ft_matlen(mat) - 1;
	while (!temp && y > 0)
	{
		ptr = &((&mat[y])[0]);
		temp = ft_c4_diag1_check(ptr, max_marks);
		y--;
	}
	x = 0;
	while (!temp && mat[0][x])
	{
		ptr = &((&mat[0])[x]);
		temp = ft_c4_diag1_check(ptr, max_marks);
		x++;
	}
	return (temp);
}

char	ft_c4_call_diag2_check(char **mat, int max_marks)
{
	int		x;
	int		y;
	char	temp;
	char	**ptr;

	if (!mat || !mat[0] || !mat[0][0])
		return (0);
	temp = 0;
	y = ft_matlen(mat) - 1;
	x = ft_strlen(mat[0]) - 1;
	while (!temp && y > 0)
	{
		ptr = &((&mat[y])[0]);
		temp = ft_c4_diag2_check(ptr, max_marks, x);
		y--;
	}
	while (!temp && x >= 0)
	{
		ptr = &((&mat[y])[0]);
		temp = ft_c4_diag2_check(ptr, max_marks, x);
		x--;
	}
	return (temp);
}

//win_check------------------------------------------------------------------

char	ft_c4_win_check(char **mat, int max_marks)
{
	char	temp;

	if (!mat || !mat[0] || !mat[0][0])
		return (0);
	//rows------------------------------------------------------------------------
	temp = ft_c4_row_check(mat, max_marks);
	if (temp)
		return (temp);
	//columns---------------------------------------------------------------------
	temp = ft_c4_column_check(mat, max_marks);
	if (temp)
		return (temp);
	//diagonal_1------------------------------------------------------------------
	temp = ft_c4_call_diag1_check(mat, max_marks);
	if (temp)
		return (temp);
	//diagonal_2------------------------------------------------------------------
	temp = ft_c4_call_diag2_check(mat, max_marks);
	if (temp)
		return (temp);
	return (0);
}
