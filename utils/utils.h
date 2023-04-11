#ifndef UTILS_H
# define UTILS_H

# include "../Libft/libft.h"

// COLORS------------------------------------

# define NOCOL "\e[0m"
# define BLACK "\e[1;30m"
# define RED "\e[1;31m"
# define GREEN "\e[1;32m"
# define YELLOW "\e[1;33m"
# define BLUE "\e[1;34m"
# define PURPLE "\e[1;35m"
# define CYAN "\e[1;36m"
# define WHITE "\e[1;37m"

//err_check-----------------------------
int		ft_err_check(char *str);
int		ft_arg_check(char *str, int min, int max);
//get_data_from_stdin-------------------
int		ft_get_n(int *n);
int		ft_get_limited_n(int *n, int min, int max);
int		ft_get_attempts(int *n);
int		ft_get_range(int *min, int *max);
int		ft_get_mat_size(int *x, int *y, int min, int max);
int		ft_get_square_mat_size(int *n, int min, int max);
void	ft_get_players_color(char **s1, char **s2);
int		ft_get_color(char **color);
//mat_fts---------------------------------
int		ft_matlen(char **mat);
void	ft_free_mat(char **mat);
char	**ft_mat_create(int max_x, int max_y);
void	ft_mat_fill(char **mat, int max_x, int max_y, char c);
//mat_chars-------------------------------
int		ft_search_char_at_pos_n(char **mat, char c, int n);
int		ft_set_char_at_pos_n(char **mat, char c, int n);
int		ft_search_char_in_column_n(char **mat, char c, int n);
int		ft_put_char_in_column_n_at_last_pos(char **mat, char c, int n, char pos);
void	ft_print_mat(char **mat);

#endif