#ifndef TICTACTOE_H
# define TICTACTOE_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <time.h>
# include "../Libft/libft.h"
# include "../utils/utils.h"

# define P1 1
# define P2 2
# define CPU 3
# define P1C 'X'
# define P2C 'O'
# define FREE ' '

// GRID_LIMITS-------------------------------

# define GRID_MIN 1
# define GRID_MAX 25

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_opt
{
	int		size;
	char	*p1_col;
	char	*p2_col;
}	t_opt;

typedef struct s_game
{
	t_opt	*opt;
	char	**mat;
	int		status;
	int		turn;
	int		player2;
}	t_game;

// ---------------------------------------
int		ft_pvp(t_opt opt);
int		ft_pve(t_opt opt);
// ---------------------------------------
void	ft_rules(t_opt opt);
//OPTIONS---------------------------------
void	ft_options(t_opt *opt);
void	ft_set_grid_size(int *size);
void	ft_set_players_color(t_opt *opt);
// ---------------------------------------
char	ft_win_check(char **mat);
int		ft_status_update(t_game *game, int player_who_moved);
int		ft_move(char **mat, int square, int player_who_moved);
//CPU-------------------------------------
int		ft_cpu_move(char **mat, int size);
//error_check-----------------------------
int		ft_arg_check(char *str, int size);
int		ft_err_check(char *str);
//print_mat-------------------------------
void	ft_print_mat_ttt(char **mat, t_opt *opt);

#endif