/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yfaustin <yfaustin@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 01:58:18 by yfaustin          #+#    #+#             */
/*   Updated: 2025/03/28 16:05:02 by yfaustin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, int (*f)(int data), void (*del)(int data))
{
	t_list	*new;
	t_list	*start;

	if (!lst || !f || !del)
		return (0);
	new = ft_lstnew(f(lst->data));
	if (!new)
		return (0);
	start = new;
	lst = lst->next;
	while (lst)
	{
		new->next = ft_lstnew(f(lst->data));
		if (!new->next)
		{
			ft_lstclear(&start, del);
			return (0);
		}
		new = new->next;
		lst = lst->next;
	}
	new->next = NULL;
	return (start);
}
