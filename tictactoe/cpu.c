#include "tictactoe.h"

//CPU----------------------------------------------------------------------

static int	*ft_free_join(int *arr, int arr_size, int n)
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

int	ft_ttt_cpu_move(char **mat, int size)
{
	int		square;
	int		*arr;
	int		arr_size;

	arr = NULL;
	arr_size = 0;
	square = 1;
	while (square < size)
	{
		if (ft_search_char_at_pos_n(mat, FREE, square))
		{
			arr = ft_free_join(arr, arr_size, square);
			arr_size++;
		}
		square++;
	}
	if (arr_size)
	{
		square = arr[rand() % ((arr_size - 1) + 1)];
		ft_printf("%d\n", square);
		ft_ttt_move(mat, square, CPU);
	}
	else
		ft_printf("No move available\n");
	if (arr)
		free(arr);
	return (0);
}

//rand() % (MAX - MIN + 1) + MIN;