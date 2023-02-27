/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_abs_len.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:46:51 by skoulen           #+#    #+#             */
/*   Updated: 2022/11/06 09:47:47 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_nbr_abs_len (for number-absolute-length) computes
	the the length (that is, the number of digits) of the
	absolute value of a number in a given base.
	
	The result is computed using successive divisions by base,
	and yields thus a linear time complexity.

	If base is lower than two, the function returns -1.

	For binary, an improvement would be to compute the length
	using bitwise operations, yielding a result in constant time.
*/

int	ft_nbr_abs_len(int n, int base)
{
	int	len;

	if (base < 2)
	{
		return (-1);
	}
	len = 1;
	while (n > (base - 1) || n < -(base - 1))
	{
		n /= base;
		len++;
	}
	return (len);
}
