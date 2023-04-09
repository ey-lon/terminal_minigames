#include "tictactoe.h"

static void	ft_move_update( int player_who_moved)
{
	if (player_who_moved == P1)
		ft_printf("Player 1 chose:\n");
	else if (player_who_moved == P2)
		ft_printf("Player 2 chose:\n");
	else
		ft_printf("The Computer chose:\n");
}

//---------------------------------------------------------------------------------

static int	ft_win_update(t_game *game, char winner)
{
	if (!winner && ++game->turn < game->opt->size * game->opt->size)
		return (0);
	else if (!winner)
		return (ft_printf("It'a tie!\n") * 0 + 4);
	else if (winner == P1C)
		return (ft_printf("Player 1 wins!\n") * 0 + 1);
	else if (game->player2 == P2)
		return (ft_printf("player 2 wins!\n") * 0 + 2);
	else if (game->player2 == CPU)
		return (ft_printf("CPU wins!\n") * 0 + 3);
	return (0);
}

//---------------------------------------------------------------------------------

int	ft_status_update(t_game *game, int player_who_moved)
{
	int	status;

	ft_move_update(player_who_moved);
	ft_print_mat_ttt(game->mat, game->opt);
	status = ft_win_update(game, ft_win_check(game->mat));
	return (status);
}
