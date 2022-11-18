/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbr_len_unsigned.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 13:15:53 by skoulen           #+#    #+#             */
/*   Updated: 2022/11/07 10:52:44 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_nbr_len_unsigned(size_t n, size_t base)
{
	int	len;

	if (base < 2)
		return (-1);
	len = 1;
	while (n > (base - 1))
	{
		n /= base;
		len++;
	}
	return (len);
}
