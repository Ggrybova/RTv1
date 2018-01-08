/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_algebra4.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 13:43:56 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/29 14:14:04 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

int			collin_vector(t_vect a, t_vect b)
{
	t_vect	v;

	v = cross_product(a, b);
	if (v.x == 0 && v.y == 0 && v.z == 0)
		return (1);
	return (0);
}

int			orthog_vector(t_vect a, t_vect b)
{
	if (dot_product(a, b) == 0)
		return (1);
	return (0);
}

double		vector_project(t_vect a, t_vect b)
{
	return (mod_vector(b) * cos(angle_vector(a, b)));
}

t_vect		normaliz_vector(t_vect a)
{
	double	mod;
	t_vect	v;

	mod = mod_vector(a);
	v.x = a.x / mod;
	v.y = a.y / mod;
	v.z = a.z / mod;
	return (v);
}
