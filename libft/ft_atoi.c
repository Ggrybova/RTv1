/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 10:32:29 by ggrybova          #+#    #+#             */
/*   Updated: 2016/12/02 12:27:46 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	unsigned	char	*a;
	int					sign;
	int					r;

	a = (unsigned char*)str;
	r = 0;
	sign = 0;
	while (*a == '\t' || *a == '\n' || *a == '\v' || *a == '\f' ||
			*a == '\r' || *a == ' ')
		a++;
	if (*a == '-')
	{
		sign = 1;
		a++;
	}
	else if (*a == '+')
		a++;
	while (*a > 47 && *a < 58)
	{
		r = r * 10 + ((int)*a - '0');
		a++;
	}
	if (sign == 1)
		return (-r);
	return (r);
}
