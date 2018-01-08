/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 14:08:54 by ggrybova          #+#    #+#             */
/*   Updated: 2016/12/15 14:56:12 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncpy2(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	sl;

	if (len > 0)
	{
		sl = ft_strlen(src);
		i = -1;
		while (++i < len)
			if (i < sl)
				dst[i] = src[i];
			else
				dst[i] = '\0';
		dst[i] = '\0';
	}
	return (dst);
}

static	int		ft_space_begin(char const *str)
{
	int		i;

	i = 0;
	while (*str && (*str == '\t' || *str == ' ' || *str == '\n'))
	{
		i++;
		str++;
	}
	return (i);
}

static	int		ft_space_end(char const *str)
{
	int		i;
	int		j;

	i = 0;
	j = ft_space_begin(str);
	if (j == (int)ft_strlen(str))
		return (i - ft_strlen(str));
	while (*str)
		str++;
	str--;
	while (*str == '\t' || *str == ' ' || *str == '\n')
	{
		i++;
		str--;
	}
	return (i);
}

char			*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if (!s)
		return (NULL);
	k = ft_strlen(s);
	i = ft_space_begin(s);
	j = ft_space_end(s);
	str = (char *)malloc(k - i - j + 1);
	if (!str)
		return (NULL);
	if (i == k)
	{
		str[0] = '\0';
		return (str);
	}
	if (i == 0 && j == 0)
		return (ft_strcpy(str, s));
	if (i != 0)
		return (ft_strncpy2(str, s + i, k - j - i));
	else
		return (ft_strncpy2(str, s, k - j));
}
