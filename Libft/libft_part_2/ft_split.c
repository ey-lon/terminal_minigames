/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 13:29:50 by abettini          #+#    #+#             */
/*   Updated: 2023/03/12 20:56:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_s_count(char const *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_strlenmod(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**mat;
	int		count;
	int		i;
	int		j;

	i = 0;
	j = 0;
	count = ft_s_count(s, c);
	mat = malloc(sizeof(char *) * (count + 1));
	while (j < count)
	{
		while (1)
		{
			if (s[i] != c)
			{
				mat[j] = ft_substr(s, i, ft_strlenmod(&s[i], c));
				i = i + ft_strlenmod(&s[i], c);
				break ;
			}
			i++;
		}
		j++;
	}
	mat[j] = NULL;
	return (mat);
}

/*
int	main()
{
	char	**arr;
	int j = 0;
	char str[] = "111ciao,111come1va?11111";
	char c = '1';
	arr = ft_split(str, c);
	while (arr[j] != 0)
	{
		printf("%s\n", arr[j]);
		j++;
	}
	return (0);
}
*/
