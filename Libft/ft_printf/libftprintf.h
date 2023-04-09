/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:53:26 by abettini          #+#    #+#             */
/*   Updated: 2023/03/29 10:26:48 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

# define PTF_NOFLAGS 0
# define PTF_HASH 1
# define PTF_SPACE 2
# define PTF_PLUS 4
# define PTF_MINUS 8
# define PTF_ZERO 16
# define PTF_PREC 32
# define PTF_WIDTH 64

typedef struct s_ptf
{
	char	format;
	int		flags;
	int		prec_count;
	int		pad_count;
	char	pad;
}	t_ptf;

// ft_printf -----------------------------------------
int		ft_printf(const char *str, ...);
int		ft_print_chr(int c, t_ptf ptf);
int		ft_print_str(char *str, t_ptf ptf);
int		ft_print_dec(int n, t_ptf ptf);
int		ft_print_uns(unsigned int n, t_ptf ptf);
int		ft_print_hex(unsigned int n, t_ptf ptf);
int		ft_print_ptr(long unsigned int n, t_ptf ptf);
// flags ---------------------------------------------
int		ft_flags(va_list ap, const char *s, int *i);
void	ft_set_flags(t_ptf *ptf, const char *s, int *i);
int		ft_conv(va_list ap, t_ptf ptf);
int		ft_flag_check(int flags, int flag_to_find);
int		ft_remove_flag(int flags, int flag_to_find);
int		ft_print_special(int c, int count);
// unknown -------------------------------------------
int		ft_check_format(char format);
int		ft_print_unknown(t_ptf ptf);
// utils ---------------------------------------------
int		ft_n_of(int len, int x);
// libft ---------------------------------------------
int		ft_isdigit(int arg);
int		ft_atoi(const char *str);

#endif
