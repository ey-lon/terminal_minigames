#include "connect_4.h"

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

int	ft_c4_cpu_move(char **mat, int size)
{
	int		column;
	int		*arr;
	int		arr_size;

	arr = NULL;
	arr_size = 0;
	column = 1;
	while (column < size)
	{
		if (ft_search_char_in_column_n(mat, FREE, column))
		{
			arr = ft_free_join(arr, arr_size, column);
			arr_size++;
		}
		column++;
	}
	if (arr_size)
	{
		column = arr[rand() % ((arr_size - 1) + 1)];
		ft_printf("%d\n", column);
		ft_c4_move(mat, column, CPU);
	}
	else
		ft_printf("No move available\n");
	if (arr)
		free(arr);
	return (0);
}

//rand() % (MAX - MIN + 1) + MIN;