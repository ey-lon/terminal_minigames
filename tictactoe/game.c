#include "tictactoe.h"

static int	ft_ttt_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  TicTacToe                 |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'exit' to quit       |\n");
	ft_printf("------------------------------\n");
	return (0);
}

static void	ft_game_init(t_game *game, t_opt *opt, int player2)
{
	game->opt = opt;
	game->turn = 0;
	game->status = 0;
	game->player2 = player2;
	game->mat = ft_mat_create(opt->size, opt->size);
	ft_mat_fill(game->mat, opt->size, opt->size, FREE);
	ft_print_mat_ttt(game->mat, game->opt);
	ft_printf("GAME ON!\n");
	ft_ttt_header();
}

//PVE------------------------------------------------------------------------------

int	ft_pve(t_opt opt)
{
	t_game	game;
	char	*str;

	srand(time(0));
	ft_game_init(&game, &opt, CPU);
	ft_printf("Player 1 turn!\n");
	while (!game.status)
	{
		str = get_next_line(0);
		if (!ft_strncmp("exit\n", str, 5))
			game.status = ft_printf("You gave up!\n") * 0 - 1;
		else if (!ft_arg_check(str, opt.size))
		{
			if (!ft_move(game.mat, ft_atoi(str), P1))
			{
				game.status = ft_status_update(&game, P1);
				if (!game.status)
				{
					ft_printf("CPU turn!\n");
					ft_cpu_move(game.mat, opt.size);
					game.status = ft_status_update(&game, CPU);
				}
				if (!game.status)
					ft_printf("Player 1 turn!\n");
			}
		}
		else
			ft_printf("Invalid argument.\n");
		if (str)
			free(str);
	}
	ft_free_mat(game.mat);
	return (0);
}

//PVP------------------------------------------------------------------------------

int	ft_pvp(t_opt opt)
{
	t_game	game;
	char	*str;
	int		player;

	ft_game_init(&game, &opt, P2);
	player = P1;
	ft_printf("Player %d turn!\n", player);
	while (!game.status)
	{
		str = get_next_line(0);
		if (!ft_strncmp("exit\n", str, 5))
			game.status = (ft_printf("Game ended!\n") * 0 - 1);
		else if (!ft_arg_check(str, opt.size))
		{
			if (!ft_move(game.mat, ft_atoi(str), player))
			{
				game.status = ft_status_update(&game, player);
				if (!game.status)
				{
					if (player == P1)
						player = P2;
					else
						player = P1;
					ft_printf("Player %d turn!\n", player);
				}
			}
		}
		else
			ft_printf("Invalid argument.\n");
		if (str)
			free(str);
	}
	ft_free_mat(game.mat);
	return (0);
}
