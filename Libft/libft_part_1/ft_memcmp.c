/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:19:50 by abettini          #+#    #+#             */
/*   Updated: 2022/10/12 09:44:57 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*p1;
	unsigned char	*p2;
	size_t			i;
	int				res;

	p1 = (unsigned char *) s1;
	p2 = (unsigned char *) s2;
	res = 0;
	i = 0;
	while (i < n && !res)
	{
		if (p1[i] > p2[i])
			res = 1;
		if (p1[i] < p2[i])
			res = -1;
		i++;
	}
	return (res);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	char *s1 = "ciao1aa";
	char *s2 = "ciao2aa";
	long unsigned int n = 6;
	printf("%d\n", ft_memcmp(s1, s2, n));
	printf("%d\n", memcmp(s1, s2, n));
	return (0);
}
*/
