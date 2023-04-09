/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unknown.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/20 14:37:09 by abettini          #+#    #+#             */
/*   Updated: 2023/04/02 15:07:10 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	n = n + '0';
	write(1, &n, 1);
}

static int	ft_count_len(int n)
{
	int	len;

	ft_putnbr(n);
	if (n == -2147483648)
		return (11);
	len = 1;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n >= 10)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

int	ft_print_unknown(t_ptf ptf)
{
	int		print_len;

	print_len = 0;
	print_len += write(1, "%", 1);
	if (ft_flag_check(ptf.flags, PTF_HASH))
		print_len += write(1, "#", 1);
	if (ft_flag_check(ptf.flags, PTF_PLUS))
		print_len += write(1, "+", 1);
	else if (ft_flag_check(ptf.flags, PTF_SPACE))
		print_len += write(1, " ", 1);
	if (ft_flag_check(ptf.flags, PTF_MINUS))
		print_len += write(1, "-", 1);
	else if (ft_flag_check(ptf.flags, PTF_ZERO))
		print_len += write(1, "0", 1);
	if (ptf.pad_count > 0)
		print_len += ft_count_len(ptf.pad_count);
	if (ft_flag_check(ptf.flags, PTF_PREC))
	{
		print_len += write(1, ".", 1);
		print_len += ft_count_len(ptf.prec_count);
	}
	print_len += write(1, &ptf.format, 1);
	return (print_len);
}
