/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_algebra1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 13:21:26 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/29 14:16:00 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_vect		fill_vector(double x, double y, double z)
{
	t_vect	v;

	v.x = x;
	v.y = y;
	v.z = z;
	return (v);
}

t_vect		unit_vector(void)
{
	t_vect	v;

	v.x = 1;
	v.y = 1;
	v.z = 1;
	return (v);
}

t_vect		null_vector(void)
{
	t_vect	v;

	v.x = 0;
	v.y = 0;
	v.z = 0;
	return (v);
}

double		mod_vector(t_vect a)
{
	return (sqrt(pow(a.x, 2) + pow(a.y, 2) + pow(a.z, 2)));
}

t_dir		direct_cos(t_vect a)
{
	t_dir	c;

	c.cos_u = a.x / mod_vector(a);
	c.cos_v = a.y / mod_vector(a);
	c.cos_w = a.z / mod_vector(a);
	return (c);
}
