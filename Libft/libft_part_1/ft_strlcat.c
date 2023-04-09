/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 15:14:51 by abettini          #+#    #+#             */
/*   Updated: 2022/10/14 10:22:11 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (dest[i] != 0 && i < size)
		i++;
	while (src[j] != 0 && (i + j + 1) < size)
	{
		dest[j + i] = src[j];
		j++;
	}
	if (i < size)
		dest[j + i] = 0;
	return (i + ft_strlen(src));
}
