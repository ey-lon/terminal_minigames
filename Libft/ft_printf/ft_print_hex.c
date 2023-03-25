/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 14:48:17 by abettini          #+#    #+#             */
/*   Updated: 2023/03/11 15:37:27 by marvin           ###   ########.fr       */
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

int	ft_print_hex(unsigned int n, char format)
{
	int					len;

	ft_put_hex(n, format);
	len = 1;
	while (n >= 16)
	{
		n = n / 16;
		len++;
	}
	return (len);
}
