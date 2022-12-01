/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 14:31:02 by skoulen           #+#    #+#             */
/*   Updated: 2022/12/01 14:44:43 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "list.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new_elt;

	new_elt = malloc(sizeof(*new_elt));
	if (!new_elt)
		return (0);
	new_elt->content = content;
	new_elt->next = 0;
	return (new_elt);
}
