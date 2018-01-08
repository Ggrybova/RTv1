/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/05 14:19:31 by ggrybova          #+#    #+#             */
/*   Updated: 2016/12/11 18:24:16 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
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
			*a = (*f)(i++, *s);
			s++;
			a++;
		}
		*a = '\0';
		return (a - i);
	}
	return (NULL);
}
