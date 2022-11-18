/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:55:54 by skoulen           #+#    #+#             */
/*   Updated: 2022/11/07 10:52:38 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_itoa_base_unsigned_helper(size_t n,
				size_t base, char *symbols, char *ptr)
{
	if (n >= base)
		ptr = ft_itoa_base_unsigned_helper(n / base, base, symbols, ptr);
	*ptr = *(symbols + (n % base));
	*(ptr + 1) = 0;
	return (ptr + 1);
}

char	*ft_itoa_base_unsigned(size_t n, char *symbols)
{
	char			*ptr;
	size_t			len;
	size_t			base;

	base = ft_strlen(symbols);
	len = ft_nbr_len(n, base);
	ptr = malloc(len + 1);
	if (!ptr)
		return (0);
	ft_itoa_base_unsigned_helper(n, base, symbols, ptr);
	return (ptr);
}
