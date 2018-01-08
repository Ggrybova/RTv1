/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:23:33 by ggrybova          #+#    #+#             */
/*   Updated: 2016/12/11 16:49:52 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	char	*ft_pozitiv_itoa(int n)
{
	int		i;
	int		num;
	char	*str;

	i = 0;
	num = n;
	while (n > 0 && ++i > 0)
		n = n / 10;
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	while (num > 0)
	{
		str[--i] = num % 10 + '0';
		num = num / 10;
	}
	return (str);
}

static	char	*ft_negativ_itoa(int n)
{
	int		i;
	int		num;
	char	*str;

	i = 1;
	n = n * -1;
	num = n;
	while (n > 0 && ++i > 0)
		n = n / 10;
	if (!(str = (char *)malloc(i + 1)))
		return (NULL);
	str[i] = '\0';
	while (num > 0)
	{
		str[--i] = num % 10 + '0';
		num = num / 10;
	}
	str[--i] = '-';
	return (str);
}

char			*ft_itoa(int n)
{
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		return (ft_negativ_itoa(n));
	return (ft_pozitiv_itoa(n));
}
