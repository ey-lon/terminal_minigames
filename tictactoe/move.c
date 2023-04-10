#include "tictactoe.h"

//movement-----------------------------------------------------------------

int	ft_ttt_move(char **mat, int square, int player_who_moved)
{
	if (!mat)
		return (1);
	if (!ft_search_char_at_pos_n(mat, FREE, square))
		return (ft_printf("Square already occupied.\n") * 0 + 1);
	else if (player_who_moved == P1)
		ft_set_char_at_pos_n(mat, P1C, square);
	else
		ft_set_char_at_pos_n(mat, P2C, square);
	return (0);
}
