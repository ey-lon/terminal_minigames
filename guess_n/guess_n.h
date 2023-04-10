#ifndef GUESS_N_H
# define GUESS_N_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <time.h>
# include "../Libft/libft.h"
# include "../utils/utils.h"

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

//MAIN------------------------------------
void	ft_gn_game(t_opt opt);
//RULES-----------------------------------
void	ft_gn_rules(t_opt opt);
//OPTIONS---------------------------------
void	ft_gn_options(t_opt *opt);
//status_update---------------------------
int		ft_gn_status_update(int n, int nbr, int att);
// ---------------------------------------

#endif