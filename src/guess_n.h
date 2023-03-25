#ifndef GUESS_N_H
# define GUESS_N_H

# include <unistd.h>
# include <stdio.h>
# include <time.h>
# include "../Libft/libft.h"

typedef struct s_opt
{
	int	max;
	int	min;
	int	att_lmt;
}	t_opt;

typedef struct s_game
{
	int	n;
	int	att;
	int	status;
}	t_game;

// ---------------------------------------
void	ft_game(t_opt opt);
void	ft_options(t_opt *opt);
void	ft_set_range(int *max, int *min);
void	ft_set_att_limit(int *n);
//utils ----------------------------------
int		ft_digits_check(char *str);

#endif