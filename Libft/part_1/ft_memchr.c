/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 14:29:32 by abettini          #+#    #+#             */
/*   Updated: 2022/10/17 10:27:45 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	i = 0;
	p = (unsigned char *) s;
	while (i < n)
	{
		if (p[i] == (unsigned char)c)
			return ((void *)&p[i]);
		i++;
	}
	return (0);
}

/*
#include <string.h>
#include <stdio.h>

int main()
{
	const char a[] = "ciao come va";
	int c = 'o';
	long unsigned int n = 8;
	char *ptr = ft_memchr(a, c, n);
	//char *ptr = memchr(a, c, n);
	printf("%s", ptr);
	return (0);
}
*/
