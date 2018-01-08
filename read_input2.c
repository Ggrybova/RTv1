/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 19:56:37 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/29 14:26:46 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char		*cut_str(char *str, char c)
{
	while (*str != c && *str != '\0')
		str++;
	if (*str != '\0')
		str++;
	return (str);
}

double		get_rational_nbr(char *a)
{
	double	nbr;
	int		i;
	int		k;
	char	sign;

	i = 0;
	k = 0;
	sign = 0;
	if (a[i] == '-')
		sign = 1;
	while (a[i] != ',' && a[i] != '.' && a[i] != '\n' &&
			a[i] != '\0' && a[i] != ' ')
		i++;
	if (a[i] != '.')
		nbr = abs(ft_atoi(a));
	else
	{
		while (a[++i] != ',' && a[i] != '\n' && a[i] != '\0' && a[i] != ' ')
			k++;
		nbr = abs(ft_atoi(a)) + abs(ft_atoi(cut_str(a, '.'))) / pow(10, k);
	}
	if (sign == 1)
		return (-nbr);
	return (nbr);
}

t_coord		record_coord(char *a)
{
	t_coord	c;

	c.x = get_rational_nbr(a);
	a = cut_str(a, ',');
	c.y = get_rational_nbr(a);
	a = cut_str(a, ',');
	c.z = get_rational_nbr(a);
	return (c);
}
