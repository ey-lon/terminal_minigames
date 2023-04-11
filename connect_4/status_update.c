#include "connect_4.h"

static void	ft_c4_move_update(int player, int cpu)
{
	if (cpu && player != P1)
		ft_printf("The Computer chose:\n");
	else
		ft_printf("Player %c chose:\n", player);
}

//---------------------------------------------------------------------------------

static int	ft_c4_win_update(t_game *game, char winner)
{
	if (!winner && ++game->turn < game->opt->grid_width * game->opt->grid_height)
		return (0);
	else if (!winner)
		return (ft_printf("It'a tie!\n") * 0 - 1);
	if (game->cpu && winner != P1)
		return (ft_printf("CPU wins!\n") * 0 + CPU);
	else
		return (ft_printf("Player %c wins!\n", winner) * 0 + winner);
	return (0);
}

//---------------------------------------------------------------------------------

int	ft_c4_status_update(t_game *game, int player)
{
	int	status;

	ft_c4_move_update(player, game->cpu);
	ft_c4_print_mat(game->mat, game->opt);
	status = ft_c4_win_update(game, ft_c4_win_check(game->mat, game->opt->max_marks));
	return (status);
}
