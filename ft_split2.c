/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 14:22:31 by skoulen           #+#    #+#             */
/*   Updated: 2022/11/21 14:39:41 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_scantok(char **str, char *sep)
{
	int	i;

	while (**str && ft_strchr(sep, **str))
		(*str)++;
	i = 0;
	while ((*str)[i] && !ft_strchr(sep, (*str)[i]))
		i++;
	*str += i;
	return (i > 0);
}

static char	*ft_gettok(char *str, char *sep)
{
	int		i;
	char	*copy;
	char	*res;

	while (*str && ft_strchr(sep, *str))
		(str)++;
	copy = ft_strdup(str);
	if (!copy)
		return (0);
	i = 0;
	while (copy[i] && !ft_strchr(sep, copy[i]))
		i++;
	if (i == 0)
		return (0);
	copy[i] = 0;
	res = ft_strdup(copy);
	free(copy);
	return (res);
}

static char	**cleanup(char **arr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (0);
}

char	**ft_split2(char *str, char *sep)
{
	char	**res;
	size_t	len;
	size_t	i;
	char	*ptr;

	len = 0;
	ptr = str;
	while (ft_scantok(&ptr, sep))
		len++;
	res = malloc(sizeof(*res) * (len + 1));
	if (!res)
		return (0);
	i = 0;
	while (i < len)
	{
		res[i] = ft_gettok(str, sep);
		if (!res[i])
			return (cleanup(res, i));
		ft_scantok(&str, sep);
		i++;
	}
	res[i] = 0;
	return (res);
}
