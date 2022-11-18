/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_unsigned_fd.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 10:46:41 by skoulen           #+#    #+#             */
/*   Updated: 2022/11/07 10:52:53 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_base_unsigned_helper(size_t n,
				size_t base, char *symbols, int fd)
{
	if (n >= base)
		ft_putnbr_base_unsigned_helper(n / base, base, symbols, fd);
	ft_putchar_fd(*(symbols + (n % base)), fd);
}

void	ft_putnbr_base_unsigned_fd(size_t n, char *symbols, int fd)
{
	size_t	base;

	base = ft_strlen(symbols);
	if (base < 2)
		return ;
	ft_putnbr_base_unsigned_helper(n, base, symbols, fd);
}
