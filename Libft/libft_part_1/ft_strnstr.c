/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 10:06:33 by abettini          #+#    #+#             */
/*   Updated: 2022/10/11 13:18:01 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t		i;
	size_t		j;
	char		*b;

	b = (char *) big;
	i = 0;
	if (little[i] == '\0')
		return (b);
	while (b[i] != '\0' && i < len)
	{
		j = 0;
		while (little[j] && big[i + j] && (i + j) < len)
		{
			if (b[i + j] == little[j])
				j++;
			else
				break ;
		}
		if (little[j] == 0)
			return (&b[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
#include <string.h>

int	main()
{
	const char a[] = "aaCIAOaaaiCIAaa";
	const char *b = "CIAO";

	printf("%s", ft_strnstr(a, b, 5));
	return (0);
}
*/
