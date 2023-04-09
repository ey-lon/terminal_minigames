#include "tictactoe.h"

//movement-----------------------------------------------------------------

int	ft_move(char **mat, int square, int player_who_moved)
{
	if (!mat || square < 1)
		return (1);
	if (ft_char_at_pos_n(mat, square) != FREE)
		return (ft_printf("Square already occupied.\n") * 0 + 1);
	else if (player_who_moved == P1)
		ft_set_char_at_pos_n(mat, square, P1C);
	else
		ft_set_char_at_pos_n(mat, square, P2C);
	return (0);
}
