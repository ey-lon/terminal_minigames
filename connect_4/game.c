#include "connect_4.h"

static int	ft_c4_header(void)
{
	ft_printf("------------------------------\n");
	ft_printf("|  Connect 4                 |\n");
	ft_printf("|                            |\n");
	ft_printf("|  type 'exit' to quit       |\n");
	ft_printf("------------------------------\n");
	return (0);
}

static void	ft_c4_game_init(t_game *game, t_opt *opt, int player2)
{
	game->opt = opt;
	game->turn = 0;
	game->status = 0;
	game->player2 = player2;
	game->mat = ft_mat_create(opt->grid_width, opt->grid_height);
	ft_mat_fill(game->mat, opt->grid_width, opt->grid_height, FREE);
	ft_c4_print_mat(game->mat, game->opt);
	ft_printf("GAME ON!\n");
	ft_c4_header();
}

//PVE------------------------------------------------------------------------------

int	ft_c4_pve(t_opt opt)
{
	t_game	game;
	char	*str;

	srand(time(0));
	ft_c4_game_init(&game, &opt, CPU);
	ft_printf("Player 1 turn!\n");
	while (!game.status)
	{
		str = get_next_line(0);
		if (!ft_strncmp("exit\n", str, 5))
			game.status = ft_printf("You gave up!\n") * 0 - 1;
		else if (!ft_arg_check(str, 1, opt.grid_width))
		{
			if (!ft_c4_move(game.mat, ft_atoi(str), P1))
			{
				game.status = ft_c4_status_update(&game, P1);
				if (!game.status)
				{
					ft_printf("CPU turn!\n");
					ft_c4_cpu_move(game.mat, opt.grid_width);
					game.status = ft_c4_status_update(&game, CPU);
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

int	ft_c4_pvp(t_opt opt)
{
	t_game	game;
	char	*str;
	int		player;

	ft_c4_game_init(&game, &opt, P2);
	player = P1;
	ft_printf("Player %d turn!\n", player);
	while (!game.status)
	{
		str = get_next_line(0);
		if (!ft_strncmp("exit\n", str, 5))
			game.status = (ft_printf("Game ended!\n") * 0 - 1);
		else if (!ft_arg_check(str, 1, opt.grid_width))
		{
			if (!ft_c4_move(game.mat, ft_atoi(str), player))
			{
				game.status = ft_c4_status_update(&game, player);
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
