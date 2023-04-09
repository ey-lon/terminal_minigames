/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 14:11:30 by abettini          #+#    #+#             */
/*   Updated: 2023/03/12 12:02:44 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*p;
	int		i;

	c = (char)c;
	p = (char *) s;
	i = 0;
	while (p[i] != 0)
		i++;
	while (i >= 0)
	{
		if (p[i] == c)
			return (&p[i]);
		i--;
	}
	return (0);
}

/*
#include <stdio.h>

int main()
{
	const char a[] = "ciao come va";
	printf("%s\n", ft_strrchr(a, '\0'));
	printf("%s", ft_strrchr(a, 'z'));
	printf("%s\n", ft_strrchr(a, 'o'));
	return (0);
}
*/
