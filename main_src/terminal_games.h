#ifndef TERMINAL_GAMES_H
# define TERMINAL_GAMES_H

# include "../utils/utils.h"
# include "../Libft/libft.h"

//PLAYERS-------------------

# define P1 1
# define P2 2
# define CPU 3

//GRID_LIMITS---------------

# define GRID_MIN 1
# define GRID_MAX 25

//guess_n-------------------
int		ft_guess_n(void);
//ticatactoe----------------
int		ft_tictactoe(void);
//connect_4-----------------
int		ft_connect_4(void);

#endif