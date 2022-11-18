/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 10:34:20 by skoulen           #+#    #+#             */
/*   Updated: 2022/10/16 13:48:21 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	size_t	i;

	while (*s && start)
	{
		s++;
		start--;
	}
	i = 0;
	while (s[i] && i < len)
		i++;
	ptr = malloc(i + 1);
	if (!ptr)
		return (0);
	ft_strlcpy(ptr, s, i + 1);
	return (ptr);
}
