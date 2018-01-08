/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:17:13 by ggrybova          #+#    #+#             */
/*   Updated: 2016/12/02 10:27:17 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned	char	*a;
	unsigned	char	*b;
	int					i;

	i = 0;
	a = (unsigned char*)s1;
	b = (unsigned char*)s2;
	if (a[i] == '\0')
		return (0 - b[i]);
	if (b[i] == '\0')
		return (a[i] - 0);
	while ((a[i] || b[i]) && n-- > 0)
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
