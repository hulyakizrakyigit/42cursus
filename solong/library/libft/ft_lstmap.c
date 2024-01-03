/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hkizrak- <hkizrak-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 16:22:33 by hkizrak-          #+#    #+#             */
/*   Updated: 2023/10/16 16:22:33 by hkizrak-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;
	t_list	*list;

	if (!lst)
		return (0);
	current = lst;
	list = 0;
	while (current)
	{
		temp = ft_lstnew(f(current->content));
		if (!temp)
		{
			ft_lstclear(&list, del);
			return (0);
		}
		ft_lstadd_back(&list, temp);
		current = current->next;
	}
	return (list);
}
