/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:19:16 by ggrybova          #+#    #+#             */
/*   Updated: 2016/12/11 18:23:43 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*a;
	int		i;

	i = 0;
	if (s)
	{
		a = (char *)malloc(ft_strlen(s) + 1);
		if (!a)
			return (NULL);
		while (*s)
		{
			*a = (*f)(*s);
			s++;
			a++;
			i++;
		}
		*a = '\0';
		return (a - i);
	}
	return (NULL);
}
