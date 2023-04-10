#ifndef TICTACTOE_H
# define TICTACTOE_H

# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include <time.h>
# include "../Libft/libft.h"
# include "../utils/utils.h"


//PLAYERS-------------------------------
# define P1 1
# define P2 2
# define CPU 3
//MARKS---------------------------------
# define P1C 'X'
# define P2C 'O'
# define FREE ' '
//GRID_LIMITS---------------------------
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
	int		player2;
	int		status;
	int		turn;
}	t_game;

//MAIN------------------------------------
int		ft_ttt_pvp(t_opt opt);
int		ft_ttt_pve(t_opt opt);
//RULES-----------------------------------
void	ft_ttt_rules(t_opt opt);
//OPTIONS---------------------------------
void	ft_ttt_options(t_opt *opt);
void	ft_ttt_set_players_color(t_opt *opt);
//movement--------------------------------
int		ft_ttt_move(char **mat, int square, int player_who_moved);
//CPU-------------------------------------
int		ft_ttt_cpu_move(char **mat, int size);
//status_update---------------------------
char	ft_ttt_win_check(char **mat);
int		ft_ttt_status_update(t_game *game, int player_who_moved);
//print_mat-------------------------------
void	ft_ttt_print_mat(char **mat, t_opt *opt);

#endif