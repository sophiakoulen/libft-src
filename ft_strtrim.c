/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:31:42 by skoulen           #+#    #+#             */
/*   Updated: 2022/10/16 12:41:22 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	in_set(char c, char const *set)
{
	while (*set && *set != c)
		set++;
	return (*set != 0);
}

static char const	*trim_begin(char const *s, char const *set)
{
	while (*s && in_set(*s, set))
		s++;
	return (s);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	size_t	len;

	s1 = trim_begin(s1, set);
	len = ft_strlen(s1);
	if (len)
	{
		while (in_set(s1[len - 1], set))
			len--;
	}
	ptr = ft_substr(s1, 0, len);
	if (!ptr)
		return (0);
	return (ptr);
}
