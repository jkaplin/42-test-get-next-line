/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkaplin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 18:00:11 by jkaplin           #+#    #+#             */
/*   Updated: 2019/03/07 08:42:23 by jkaplin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin_lst;
	t_list	*new_elem;
	t_list	*ptr_lst;

	ptr_lst = f(lst);
	begin_lst = ft_lstnew(ptr_lst->content, ptr_lst->content_size);
	if (begin_lst == NULL)
		return (NULL);
	new_elem = begin_lst;
	while (lst->next)
	{
		lst = lst->next;
		ptr_lst = f(lst);
		ptr_lst = ft_lstnew(ptr_lst->content, ptr_lst->content_size);
		if (new_elem == NULL)
			return (NULL);
		new_elem->next = ptr_lst;
		new_elem = new_elem->next;
	}
	return (begin_lst);
}
