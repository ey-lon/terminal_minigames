/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 08:42:43 by abettini          #+#    #+#             */
/*   Updated: 2022/10/12 10:16:06 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*p1;
	char	*p2;
	char	*p;

	p1 = (char *) s1;
	p2 = (char *) s2;
	p = malloc(sizeof(char) * (ft_strlen(p1) + ft_strlen(p2) + 1));
	ft_strlcpy(p, p1, ft_strlen(s1) + 1);
	ft_strlcat(p, p2, ft_strlen(s1) + ft_strlen(s2) + 1);
	return (p);
}

/*
#include <stdio.h>

int	main()
{
	char	*a = "ciao,";
	char	*b = "come va?";
	char	*f;

	f = ft_strjoin(a, b);
	printf("%s", f);	
	return (0);
}
*/
