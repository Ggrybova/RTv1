/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 11:57:33 by ggrybova          #+#    #+#             */
/*   Updated: 2016/12/11 18:25:15 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
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
	}
	return (dst);
}
