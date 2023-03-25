/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 09:53:26 by abettini          #+#    #+#             */
/*   Updated: 2023/03/11 16:43:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_print_chr(int c);
int	ft_print_str(char *str);
int	ft_print_dec(int n);
int	ft_print_uns(unsigned int n);
int	ft_print_hex(unsigned int n, char format);
int	ft_print_ptr(long unsigned int n);

#endif
