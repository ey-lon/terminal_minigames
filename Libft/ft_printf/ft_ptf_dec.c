/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_dec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:48:17 by abettini          #+#    #+#             */
/*   Updated: 2023/04/02 15:06:56 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		write(1, "2147483648", 10);
		return ;
	}
	if (n < 0)
		n = -n;
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		n = n % 10;
	}
	n = n + '0';
	write(1, &n, 1);
}

static int	ft_int_len(int n)
{
	int	len;

	if (n == -2147483648)
		len = 10;
	else
	{
		len = 1;
		if (n < 0)
			n = -n;
		while (n >= 10)
		{
			n = n / 10;
			len++;
		}
	}
	return (len);
}

static int	ft_dec_symbol(t_ptf ptf, int n, int x)
{
	int	len;

	len = 0;
	if (ft_flag_check(ptf.flags, PTF_SPACE) && n >= 0)
	{
		len++;
		if (x == 0)
			write(1, " ", 1);
	}
	if (ft_flag_check(ptf.flags, PTF_PLUS) && n >= 0)
	{
		len++;
		if ((ft_flag_check(ptf.flags, PTF_ZERO) && x == 0) \
			|| (!ft_flag_check(ptf.flags, PTF_ZERO) && x == 1))
			write(1, "+", 1);
	}
	if (n < 0)
	{
		len++;
		if ((ft_flag_check(ptf.flags, PTF_ZERO) && x == 0) \
			|| (!ft_flag_check(ptf.flags, PTF_ZERO) && x == 1))
			write(1, "-", 1);
	}
	return (len);
}

int	ft_print_dec(int n, t_ptf ptf)
{
	int	print_len;
	int	len;

	if (n == 0 && ft_flag_check(ptf.flags, PTF_PREC) && ptf.prec_count < 1)
		len = 0;
	else
		len = ft_int_len(n);
	print_len = len;
	ptf.prec_count = ft_n_of(len, ptf.prec_count);
	ptf.pad_count = ft_n_of(len + ptf.prec_count, ptf.pad_count);
	ptf.pad_count -= ft_dec_symbol(ptf, n, 0);
	if (!ft_flag_check(ptf.flags, PTF_MINUS))
		print_len += ft_print_special(ptf.pad, ptf.pad_count);
	print_len += ft_dec_symbol(ptf, n, 1);
	print_len += ft_print_special('0', ptf.prec_count);
	if (len)
		ft_putnbr(n);
	if (ft_flag_check(ptf.flags, PTF_MINUS))
		print_len += ft_print_special(ptf.pad, ptf.pad_count);
	return (print_len);
}

// calcola pad (controllando ' ', '+' e/o '-')
// stampa pad [left] se non c'e' PTF_MINUS
// stampa ' ' se c'e' PTF_SPACE, 
//	stampa '+' se c'e' PTF_PLUS, stampa '-' se n < 0
// stampa prec
// stampa n
// stampa pad [right] se c'e' PTF_MINUS
