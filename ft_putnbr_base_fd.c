/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/06 09:46:35 by skoulen           #+#    #+#             */
/*   Updated: 2022/11/06 09:49:06 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_base_helper(int n, int base, char *symbols, int fd)
{
	int	sign;

	sign = ft_sign(n);
	if (n >= base || n <= -base)
		ft_putnbr_base_helper(n / base, base, symbols, fd);
	ft_putchar_fd(*(symbols + (n % base) * sign), fd);
}

void	ft_putnbr_base_fd(int n, char *symbols, int fd)
{
	int	base;

	base = ft_strlen(symbols);
	if (base < 2)
		return ;
	if (n < 0)
		ft_putchar_fd('-', fd);
	ft_putnbr_base_helper(n, base, symbols, fd);
}
