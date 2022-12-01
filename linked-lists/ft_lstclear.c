/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:47:21 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/01 14:44:24 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	if (!(*lst))
		return ;
	if (!(*lst)->next)
	{
		ft_lstdelone(*lst, del);
	}
	else
	{
		ft_lstclear(&(*lst)->next, del);
		ft_lstdelone(*lst, del);
	}
	*lst = 0;
}
