/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 15:18:19 by ggrybova          #+#    #+#             */
/*   Updated: 2016/12/01 11:44:51 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	char			*a;
	const	char	*b;

	a = dst;
	b = src;
	while (n--)
		if ((*a++ = *b++) == c)
			return (a);
	return (NULL);
}
