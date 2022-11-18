/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 21:16:37 by skoulen           #+#    #+#             */
/*   Updated: 2022/10/14 13:18:45 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	sign(int n)
{
	if (n >= 0)
		return (1);
	else
		return (-1);
}

static size_t	digitcount(int n)
{
	size_t	len;

	len = 1;
	if (sign(n) == -1)
		len++;
	while (n >= 10 || n <= -10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

static char	*itoa_helper(int n, char *ptr)
{
	if (n >= 10 || n <= -10)
		ptr = itoa_helper(n / 10, ptr);
	*ptr = (n % 10) * sign(n) + '0';
	*(ptr + 1) = 0;
	return (ptr + 1);
}

char	*ft_itoa(int n)
{
	char	*str;
	char	*ptr;
	size_t	len;

	len = digitcount(n);
	str = malloc(len + 1);
	if (!str)
		return (0);
	ptr = str;
	if (sign(n) == -1)
	{
		*str = '-';
		str++;
	}
	itoa_helper(n, str);
	return (ptr);
}
