/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 14:40:01 by ggrybova          #+#    #+#             */
/*   Updated: 2016/12/16 10:41:38 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if ((*big) == '\0' || len < 1)
		return (NULL);
	if ((*little) == '\0')
		return ((char*)big);
	i = ft_strlen(little);
	while (len-- >= i && *big)
	{
		if (!ft_strncmp(big++, little, i))
			return ((char*)(big - 1));
	}
	return (NULL);
}
