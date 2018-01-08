/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 11:06:59 by ggrybova          #+#    #+#             */
/*   Updated: 2016/11/28 16:02:17 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned	char	*a;
	const		char	*b;

	a = (unsigned char*)dst;
	b = (const char*)src;
	while (n-- > 0)
		*a++ = *b++;
	return (dst);
}
