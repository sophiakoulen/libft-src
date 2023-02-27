/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 18:18:12 by skoulen           #+#    #+#             */
/*   Updated: 2022/11/06 09:53:47 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	ft_itoa_base_helper is a helper function for ft_itoa_base.
	
	Its purpose is to write the absolute value of a number to a string,
	using the given base and symbols.

	This function works recursively: computing the last digit of number is easy
	(using modulo), but it is the last digit that has to be printed.
	
	We solve this quirk using the recursion stack.
	As long as we are not at the last digit, the function calls itself and
	increments a pointer storing where we have to write next.
	Then, when we have written the last digit, we pop the recursion stack
	and the other digits will be printed starting from the end.

	It achieves a similar result to going to the end of our allocated string and
	printing the digits to it backwards.
	The advantage of this method is that we do not have to compute in advance the
	number of digits that we'll print.

	I admit that, to me, it still feels like it is working "magically".

*/

static char	*ft_itoa_base_helper(int n, int base, char *symbols, char *ptr)
{
	if (n >= base || n <= -base)
		ptr = ft_itoa_base_helper(n / base, base, symbols, ptr);
	*ptr = *(symbols + (n % base) * ft_sign(n));
	*(ptr + 1) = 0;
	return (ptr + 1);
}

/*
	ft_itoa_base converts an integer to a string with a given base.
	The base is given using a string of symbols used to represent the number.
	
	Ex 1: for conventional base 10, use symbols = "0123456789"
	Ex 2: for binary, use "01"
	Ex 3: for hexadecimal, use "0123456789ABCDEF"
	Ex 4: a custom base 5: "qWeRtY" will represent 5 as "Wq", 4 as "Y",
	25 as "Wqq"...

	It is computed using a recursive helper function that writes the
	absolute value to a buffer.

	First, we compute the number of characters we'll need and allocate a string.
	Then, we write a minus sign if our number is negative.
	Then, a recursive helper function will write to that buffer using
	the provided symbols.
*/

char	*ft_itoa_base(int n, char *symbols)
{
	char	*str;
	char	*ptr;
	size_t	len;
	int		base;

	base = ft_strlen(symbols);
	len = ft_nbr_len(n, base);
	str = malloc(len + 1);
	if (!str)
		return (0);
	ptr = str;
	if (ft_sign(n) == -1)
	{
		*ptr = '-';
		ptr++;
	}
	ft_itoa_base_helper(n, base, symbols, ptr);
	return (str);
}
