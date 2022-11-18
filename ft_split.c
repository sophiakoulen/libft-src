/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 19:08:33 by skoulen           #+#    #+#             */
/*   Updated: 2022/10/19 10:33:39 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*tok(const char **s, char sep)
{
	char	*tok;
	size_t	i;

	while (**s && **s == sep)
		(*s)++;
	i = 0;
	while ((*s)[i] && (*s)[i] != sep)
		i++;
	tok = ft_substr(*s, 0, i);
	*s += i;
	return (tok);
}

static size_t	word_count(char const *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		if (*s != c && (*(s + 1) == c || *(s + 1) == 0))
			count++;
		s++;
	}
	return (count);
}

static void	cleanup(char **arr, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

char	**ft_split(char const *s, char c)
{
	char			**arr;
	char			*str;
	unsigned int	i;

	arr = malloc((word_count(s, c) + 1) * sizeof(char *));
	if (!arr)
		return (0);
	i = 0;
	str = tok(&s, c);
	while (str && *str)
	{
		arr[i] = str;
		str = tok(&s, c);
		i++;
	}
	if (!str)
	{
		cleanup(arr, i);
		return (0);
	}
	free(str);
	arr[i] = 0;
	return (arr);
}
