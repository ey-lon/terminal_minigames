/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:06:23 by abettini          #+#    #+#             */
/*   Updated: 2023/04/02 15:07:17 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_conv(va_list ap, t_ptf ptf)
{
	int	print_len;

	print_len = 0;
	if (ptf.format == 'c')
		print_len = ft_print_chr(va_arg(ap, int), ptf);
	else if (ptf.format == 's')
		print_len = ft_print_str(va_arg(ap, char *), ptf);
	else if (ptf.format == 'p')
		print_len = ft_print_ptr(va_arg(ap, long unsigned int), ptf);
	else if (ptf.format == 'd' || ptf.format == 'i')
		print_len = ft_print_dec(va_arg(ap, int), ptf);
	else if (ptf.format == 'u')
		print_len = ft_print_uns(va_arg(ap, unsigned int), ptf);
	else if (ptf.format == 'x' || ptf.format == 'X')
		print_len = ft_print_hex(va_arg(ap, unsigned int), ptf);
	else if (ptf.format == '%')
		print_len = write(1, "%", 1);
	else
		print_len = ft_print_unknown(ptf);
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_len;
	va_list	ap;

	if (str)
	{
		print_len = 0;
		va_start(ap, str);
		i = 0;
		while (str[i])
		{
			if (str[i] == '%')
				print_len += ft_flags(ap, str, &i);
			else
				print_len += write(1, &str[i], 1);
			i++;
		}
		va_end(ap);
	}
	else
		print_len = -1;
	return (print_len);
}
