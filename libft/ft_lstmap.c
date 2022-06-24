/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yahokari <yahokari@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 20:21:21 by yahokari          #+#    #+#             */
/*   Updated: 2022/04/19 22:11:27 by yahokari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*copy_lst;

	if (lst == NULL || f == NULL)
		return (NULL);
	copy_lst = ft_lstnew(f(lst->content));
	if (copy_lst == NULL)
		return (NULL);
	new_lst = copy_lst;
	lst = lst->next;
	while (lst != NULL)
	{
		copy_lst = ft_lstnew(f(lst->content));
		if (copy_lst == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, copy_lst);
		lst = lst->next;
	}
	return (new_lst);
}
