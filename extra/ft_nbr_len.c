/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:46:56 by skoulen           #+#    #+#             */
/*   Updated: 2022/11/06 09:48:48 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
	ft_nbr_len computes the amount of characters one would need
	to represent a number with a given base. It takes into acount
	exactly one minus sign is n is negative and no plus sign if
	n is positive.

	If base is smaller than 2, this function returns -1.

	The result is computed using ft_nbr_abs_len, which computes the
	number of digits a number has in a given base.
*/

int	ft_nbr_len(int n, int base)
{
	int	abs_len;

	if (base < 2)
		return (-1);
	abs_len = ft_nbr_abs_len(n, base);
	if (n < 0)
		return (abs_len + 1);
	else
		return (abs_len);
}
