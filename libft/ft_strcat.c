/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:32:00 by ggrybova          #+#    #+#             */
/*   Updated: 2016/11/29 13:38:08 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	const	char	*a;
	char			*b;
	size_t			i;

	a = (const char*)s2;
	b = (char *)s1;
	i = 0;
	while (*b)
		b++;
	while (i++ < ft_strlen(s2))
	{
		*b++ = *a++;
	}
	*b = '\0';
	return (s1);
}
