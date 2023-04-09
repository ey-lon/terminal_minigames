/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 13:42:45 by abettini          #+#    #+#             */
/*   Updated: 2023/03/11 16:12:48 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*p_ret;
	t_list	*p_temp;

	p_ret = NULL;
	while (lst != NULL)
	{
		p_temp = ft_lstnew(f(lst->content));
		if (p_temp == NULL)
		{
			ft_lstclear(&p_ret, del);
			return (NULL);
		}
		ft_lstadd_back(&p_ret, p_temp);
		lst = lst -> next;
	}
	return (p_ret);
}
