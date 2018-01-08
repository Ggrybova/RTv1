/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 15:11:42 by ggrybova          #+#    #+#             */
/*   Updated: 2017/08/16 15:25:15 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	**a;
	int		i;
	int		j;
	int		end;

	if (!s)
		return (NULL);
	i = -1;
	j = 0;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == '\0' || s[i + 1] == c))
			j++;
	if ((a = (char**)malloc(sizeof(char*) * j + 1)) == 0)
		return (NULL);
	a[j--] = NULL;
	end = i;
	while (i--)
	{
		if (s[i] != c && s[i + 1] == c)
			end = i;
		if (s[i] != c && (s[i - 1] == c || i == 0))
			if ((a[j--] = ft_strsub(s, (unsigned int)i, end - i + 1)) == 0)
				return (NULL);
	}
	return (a);
}
