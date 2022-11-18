/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 10:09:36 by skoulen           #+#    #+#             */
/*   Updated: 2022/10/14 13:45:38 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	putnbr_helper(int n, int fd)
{
	int	sign;

	sign = 1;
	if (n < 0)
		sign = -1;
	if (n >= 10 || n <= -10)
		putnbr_helper(n / 10, fd);
	ft_putchar_fd('0' + (n % 10) * sign, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n < 0)
		ft_putchar_fd('-', fd);
	putnbr_helper(n, fd);
}
