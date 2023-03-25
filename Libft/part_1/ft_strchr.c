/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:02:08 by abettini          #+#    #+#             */
/*   Updated: 2023/03/12 12:03:31 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*p;

	c = (char)c;
	p = (char *)s;
	while (*p != 0)
	{
		if (*p == c)
			return (p);
		p++;
	}
	if (*p == c)
		return (p);
	return (0);
}

/*
#include <stdio.h>

int	main()
{
	const char a[] = "tripouille";
	printf("%s", ft_strchr(a, '\0'));
	printf("%s", strchr(a, '\0'));
	return (0);
}
*/
