/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 16:31:04 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/01 14:44:16 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"

void	ft_lstadd_back(t_list **lst, t_list *new_elt)
{
	t_list	*last;

	last = ft_lstlast(*lst);
	if (!last)
		*lst = new_elt;
	else
		last->next = new_elt;
}
