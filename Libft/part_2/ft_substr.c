/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/10 10:32:22 by abettini          #+#    #+#             */
/*   Updated: 2023/03/12 13:32:02 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	str_len;

	str_len = ft_strlen(s);
	if (start < str_len)
	{
		if (len > str_len - start)
			str_len = str_len - start;
		else
			str_len = len;
		p = malloc(sizeof(char) * (str_len + 1));
		ft_strlcpy(p, &s[start], str_len + 1);
	}
	else
	{
		p = malloc(sizeof(char));
		*p = '\0';
	}
	return (p);
}
