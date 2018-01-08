/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 10:41:24 by ggrybova          #+#    #+#             */
/*   Updated: 2016/11/30 12:20:34 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcpy(char *dst, const char *src)
{
	const	char	*s;
	char			*d;
	size_t			i;

	s = (const char*)src;
	d = (char *)dst;
	i = 0;
	while (i++ < ft_strlen(src))
		*d++ = *s++;
	*d = '\0';
	return (dst);
}
