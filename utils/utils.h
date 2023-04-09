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
//get_data_from_stdin-------------------
int		ft_get_n(int *n);
int		ft_get_min_max(int *max, int *min);
int		ft_get_color(char **color);
//mat_fts---------------------------------
int		ft_matlen(char **mat);
void	ft_free_mat(char **mat);
char	**ft_mat_create(int max_y, int max_x);
void	ft_mat_fill(char **mat, int max_y, int max_x, char c);
//mat_chars-------------------------------
char	ft_char_at_pos_n(char **mat, int n);
void	ft_set_char_at_pos_n(char **mat, int n, char c);
void	ft_print_mat(char **mat);

#endif