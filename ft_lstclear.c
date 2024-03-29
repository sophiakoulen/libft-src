/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:47:21 by skoulen           #+#    #+#             */
/*   Updated: 2023/02/27 11:11:58 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
