/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 13:29:41 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/29 14:25:29 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_color		color(char *str)
{
	t_color	col;
	int		*rgb;
	int		i;
	int		k;

	k = -1;
	rgb = (int *)malloc(sizeof(int) * 2);
	while (++k <= 3 && (i = -1) < 0)
	{
		str = cut_str(str, 'x');
		while (++i < 2 && (rgb[i] = 0) > -1)
		{
			if (str[i] >= 65 && str[i] <= 70)
				rgb[i] = (int)str[i] - 55;
			else if (str[i] >= 97 && str[i] <= 102)
				rgb[i] = (int)str[i] - 87;
			else if (str[i] >= 48 && str[i] <= 57)
				rgb[i] = (int)str[i] - 48;
		}
		col.red = (k == 0) ? rgb[0] * 16 + rgb[1] : col.red;
		col.green = (k == 1) ? rgb[0] * 16 + rgb[1] : col.green;
		col.blue = (k == 2) ? rgb[0] * 16 + rgb[1] : col.blue;
	}
	free(rgb);
	return (col);
}

t_color		fill_color(int r, int g, int b)
{
	t_color	c;

	c.red = r;
	c.green = g;
	c.blue = b;
	return (c);
}

t_color		choose_color(t_scene *s, int hit, int i)
{
	t_color	c;

	c.red = 0;
	c.green = 0;
	c.blue = 0;
	if (hit == 0)
		c = s->sph[i].col;
	else if (hit == 1)
		c = s->cyl[i].col;
	else if (hit == 2)
		c = s->con[i].col;
	else if (hit == 3)
		c = s->pl[i].col;
	return (c);
}
