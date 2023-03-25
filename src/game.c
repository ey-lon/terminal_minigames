#include "guess_n.h"

int	ft_status_update(int n, int nbr, int att)
{
	if (nbr == n)
	{
		ft_printf("Congrats! You Won in %d attempts.\n", att);
		return (1);
	}
	else if (nbr > n)
		ft_printf("The number to find is smaller\n");
	else if (nbr < n)
		ft_printf("The number to find is greater\n");
	ft_printf("attempts = %d\n", att);
	return (0);
}

void	ft_game_init(t_game *game, t_opt opt)
{
	srand(time(0));
	game->n = rand() % (opt.max + 1 - opt.min) + opt.min;
	game->att = 0;
	game->status = 0;
}

void	ft_game(t_opt opt)
{
	char		*str;
	t_game		game;

	ft_game_init(&game, opt);
	ft_rules(opt);
	ft_printf("GAME ON!\n");
	while (!game.status)
	{
		str = get_next_line(0);
		if (!ft_strncmp("exit\n", str, 5))
			game.status = (ft_printf("You gave up!\n") * 0 - 1);
		else if (ft_digits_check(str))
		{
			game.att++;
			game.status = ft_status_update(game.n, ft_atoi(str), game.att);
		}
		else
			ft_printf("Invalid argument.\n");
		if (!game.status && opt.att_lmt > 0 && game.att == opt.att_lmt)
			game.status = (ft_printf("You Lose!\
				\nThe number was [%d].\n", game.n) * 0 - 1);
		if (str)
			free(str);
	}
}
