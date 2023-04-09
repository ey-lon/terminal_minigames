/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 16:09:56 by abettini          #+#    #+#             */
/*   Updated: 2023/04/02 15:06:48 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_flags_init(t_ptf *ptf)
{
	ptf->flags = PTF_NOFLAGS;
	ptf->format = 0;
	ptf->prec_count = 0;
	ptf->pad_count = 0;
	ptf->pad = ' ';
}

void	ft_flags_update(va_list ap, t_ptf *ptf)
{
	if (ft_flag_check(ptf->flags, PTF_WIDTH))
	{
		ptf->pad_count = va_arg(ap, int);
		if (ptf->pad_count < 0)
		{
			ptf->pad_count = -ptf->pad_count;
			ptf->flags |= PTF_MINUS;
		}
	}
	if (ft_flag_check(ptf->flags, PTF_PLUS))
		ptf->flags = ft_remove_flag(ptf->flags, PTF_SPACE);
	if ((ft_flag_check(ptf->flags, PTF_PREC) \
		|| ft_flag_check(ptf->flags, PTF_MINUS) \
		|| ptf->format == 's' || ptf->format == 'c') \
		&& ft_check_format(ptf->format))
		ptf->flags = ft_remove_flag(ptf->flags, PTF_ZERO);
	if (ft_flag_check(ptf->flags, PTF_ZERO))
		ptf->pad = '0';
}

int	ft_flags(va_list ap, const char *s, int *i)
{
	int		print_len;
	t_ptf	ptf;

	*i += 1;
	ft_flags_init(&ptf);
	ft_set_flags(&ptf, s, i);
	ft_flags_update(ap, &ptf);
	print_len = ft_conv(ap, ptf);
	return (print_len);
}
