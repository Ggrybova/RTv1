/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/24 13:52:55 by ggrybova          #+#    #+#             */
/*   Updated: 2016/12/12 10:15:46 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	const	char	*a;
	char			*b;
	size_t			i;

	a = s2;
	b = s1;
	i = 0;
	while (*b)
		b++;
	while (i++ < ft_strlen(s2) && n > 0)
	{
		*b++ = *a++;
		n--;
	}
	*b = '\0';
	return (s1);
}
