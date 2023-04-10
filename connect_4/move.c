#include "connect_4.h"

//movement-----------------------------------------------------------------

int	ft_c4_move(char **mat, int column, int player_who_moved)
{
	if (!mat)
		return (1);
	if (!ft_search_char_in_column_n(mat, FREE, column))
		return (ft_printf("Column full.\n") * 0 + 1);
	else if (player_who_moved == P1)
		ft_put_char_in_column_n_at_last_pos(mat, P1C, column, FREE);
	else
		ft_put_char_in_column_n_at_last_pos(mat, P2C, column, FREE);
	return (0);
}
