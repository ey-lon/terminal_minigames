/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:48:17 by abettini          #+#    #+#             */
/*   Updated: 2023/04/02 15:06:59 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_put_hex(unsigned int n, char format)
{
	if (n >= 16)
	{
		ft_put_hex(n / 16, format);
		n = n % 16;
	}
	if (n >= 10)
	{
		if (format == 'X')
			n = n + 'A' - 10;
		else
			n = n + 'a' - 10;
	}
	else
		n = n + '0';
	write(1, &n, 1);
}

static int	ft_hex_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n = n / 16;
		len++;
	}
	return (len);
}

static int	ft_hex_symbol(t_ptf ptf, unsigned int n, int x)
{
	int	len;

	len = 0;
	if (ft_flag_check(ptf.flags, PTF_HASH) && n != 0)
	{
		len += 2;
		if ((ft_flag_check(ptf.flags, PTF_ZERO) && x == 0) \
				|| (!ft_flag_check(ptf.flags, PTF_ZERO) && x == 1))
		{
			if (ptf.format == 'x')
				write(1, "0x", 2);
			else
				write(1, "0X", 2);
		}
	}
	return (len);
}

int	ft_print_hex(unsigned int n, t_ptf ptf)
{
	int	print_len;
	int	len;

	if (n == 0 && ft_flag_check(ptf.flags, PTF_PREC) && ptf.prec_count < 1)
		len = 0;
	else
		len = ft_hex_len(n);
	print_len = len;
	ptf.prec_count = ft_n_of(len, ptf.prec_count);
	ptf.pad_count = ft_n_of(len + ptf.prec_count, ptf.pad_count);
	ptf.pad_count -= ft_hex_symbol(ptf, n, 0);
	if (!ft_flag_check(ptf.flags, PTF_MINUS))
		print_len += ft_print_special(ptf.pad, ptf.pad_count);
	print_len += ft_hex_symbol(ptf, n, 1);
	print_len += ft_print_special('0', ptf.prec_count);
	if (len)
		ft_put_hex(n, ptf.format);
	if (ft_flag_check(ptf.flags, PTF_MINUS))
		print_len += ft_print_special(ptf.pad, ptf.pad_count);
	return (print_len);
}
