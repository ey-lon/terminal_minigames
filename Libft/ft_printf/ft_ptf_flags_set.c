/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 10:16:31 by abettini          #+#    #+#             */
/*   Updated: 2023/04/02 15:06:39 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_set_flags1(t_ptf *ptf, const char *s, int *i)
{
	while (s[*i] == '#' || s[*i] == '+' || s[*i] == ' ')
	{
		if (s[*i] == '#')
			ptf->flags |= PTF_HASH;
		else if (s[*i] == ' ')
			ptf->flags |= PTF_SPACE;
		else if (s[*i] == '+')
			ptf->flags |= PTF_PLUS;
		*i += 1;
	}
}

void	ft_set_flags2(t_ptf *ptf, const char *s, int *i)
{
	while (s[*i] == '-' || s[*i] == '0')
	{
		if (s[*i] == '-')
			ptf->flags |= PTF_MINUS;
		else if (s[*i] == '0')
			ptf->flags |= PTF_ZERO;
		*i += 1;
	}
	if (s[*i] == '*')
	{
		ptf->flags |= PTF_WIDTH;
		*i += 1;
	}
	else if (ft_isdigit(s[*i]))
	{
		ptf->pad_count = ft_atoi(&s[*i]);
		while (ft_isdigit(s[*i]))
			*i += 1;
	}
}

void	ft_set_flags3(t_ptf *ptf, const char *s, int *i)
{
	if (s[*i] == '.')
	{
		ptf->flags |= PTF_PREC;
		*i += 1;
		if (ft_isdigit(s[*i]))
		{
			ptf->prec_count = ft_atoi(&s[*i]);
			while (ft_isdigit(s[*i]))
				*i += 1;
		}
	}
}

void	ft_set_flags(t_ptf *ptf, const char *s, int *i)
{
	ft_set_flags1(ptf, s, i);
	ft_set_flags2(ptf, s, i);
	ft_set_flags3(ptf, s, i);
	ptf->format = s[*i];
}
