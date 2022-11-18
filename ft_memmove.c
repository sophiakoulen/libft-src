/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <marvin@42lausanne.ch>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:33:49 by skoulen           #+#    #+#             */
/*   Updated: 2022/10/11 10:33:52 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*p_dst;
	const char	*p_src;

	if (!dest && !src)
		return (0);
	p_src = src;
	p_dst = dest;
	if ((p_src < p_dst) && (p_dst < p_src + n))
	{
		i = 0;
		while (i < n)
		{
			p_dst[n - 1 - i] = p_src[n - 1 - i];
			i++;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
