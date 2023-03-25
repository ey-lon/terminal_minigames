/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 10:06:23 by abettini          #+#    #+#             */
/*   Updated: 2023/03/11 18:17:22 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int	ft_conv(va_list ap, char format)
{
	int	print_len;

	print_len = 0;
	if (format == 'c')
		print_len = ft_print_chr(va_arg(ap, int));
	else if (format == 's')
		print_len = ft_print_str(va_arg(ap, char *));
	else if (format == 'p')
		print_len = ft_print_ptr(va_arg(ap, long unsigned int));
	else if (format == 'd' || format == 'i')
		print_len = ft_print_dec(va_arg(ap, int));
	else if (format == 'u')
		print_len = ft_print_uns(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		print_len = ft_print_hex(va_arg(ap, unsigned int), format);
	else if (format == '%')
	{
		write(1, "%", 1);
		print_len = 1;
	}
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		print_len;
	va_list	ap;

	if (str)
	{
		va_start(ap, str);
		print_len = 0;
		i = 0;
		while (str[i])
		{
			if (str[i] == '%')
			{
				print_len += ft_conv(ap, str[i + 1]);
				i++;
			}
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
