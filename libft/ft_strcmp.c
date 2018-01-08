/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 15:55:10 by ggrybova          #+#    #+#             */
/*   Updated: 2016/12/02 09:56:05 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
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
	while (a[i] || b[i])
	{
		if (a[i] != b[i])
			return (a[i] - b[i]);
		i++;
	}
	return (0);
}
