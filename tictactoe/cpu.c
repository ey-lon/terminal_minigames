#include "tictactoe.h"

//CPU----------------------------------------------------------------------

int	*ft_free1_join(int *arr, int arr_size, int n)
{
	int		*new_arr;
	int		i;

	new_arr = malloc(sizeof(int) * (arr_size + 1));
	i = 0;
	while (i < arr_size)
	{
		new_arr[i] = arr[i];
		i++;
	}
	new_arr[i] = n;
	if (arr_size)
		free(arr);
	return (new_arr);
}

int	ft_cpu_move(char **mat, int size)
{
	int		square;
	int		*arr;
	int		arr_size;
	int		temp;

	arr = NULL;
	arr_size = 0;
	square = 1;
	while (square < (size * size))
	{
		if (ft_char_at_pos_n(mat, square) == FREE)
		{
			temp = square;
			arr = ft_free1_join(arr, arr_size, temp);
			arr_size++;
		}
		square++;
	}
	if (arr_size)
	{
		square = arr[rand() % ((arr_size - 1) + 1)];
		ft_printf("%d\n", square);
		ft_move(mat, square, CPU);
	}
	else
		ft_printf("No move available\n");
	if (arr)
		free(arr);
	return (0);
}

//rand() % (MAX - MIN + 1) + MIN;