/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:03:50 by skoulen           #+#    #+#             */
/*   Updated: 2022/10/19 10:34:27 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*create_or_cleanup(t_list *new_list, t_list *iter,
	void *(*f)(void *), void (*del)(void *))
{
	void	*new_content;
	t_list	*new_elem;

	new_content = f(iter->content);
	if (!new_content)
	{
		ft_lstclear(&new_list, del);
		return (0);
	}
	new_elem = ft_lstnew(new_content);
	if (!new_elem)
	{
		del(new_content);
		ft_lstclear(&new_list, del);
		return (0);
	}
	return (new_elem);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	**new_iter;
	t_list	*new_elem;

	new_list = 0;
	new_iter = &new_list;
	while (lst)
	{
		new_elem = create_or_cleanup(new_list, lst, f, del);
		if (!new_elem)
			return (0);
		ft_lstadd_back(new_iter, new_elem);
		lst = lst->next;
		new_iter = &(*new_iter)->next;
	}
	return (new_list);
}
