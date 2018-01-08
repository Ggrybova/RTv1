/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 16:02:39 by ggrybova          #+#    #+#             */
/*   Updated: 2016/12/16 10:41:41 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	char	*b;
	size_t	i;
	size_t	c;

	b = (char*)big;
	if (*little == '\0')
		return (b);
	if (*b == '\0')
		return (NULL);
	c = ft_strlen(little);
	while (*b)
	{
		if (*b == *little)
		{
			i = 0;
			while (*b == *little && *b && *little++ && i++ < c + 1)
				b++;
			if (c == i)
				return (b - i);
			b = b - i;
			little = little - i;
		}
		b++;
	}
	return (NULL);
}
