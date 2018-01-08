/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_algebra3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 13:25:54 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/29 13:35:16 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

double		angle_vector(t_vect a, t_vect b)
{
	return (acos(dot_product(a, b) / mod_vector(a) / mod_vector(b)));
}

t_vect		cross_product(t_vect a, t_vect b)
{
	t_vect	v;

	v.x = a.y * b.z - a.z * b.y;
	v.y = a.z * b.x - a.x * b.z;
	v.z = a.x * b.y - a.y * b.x;
	return (v);
}

double		cross_product_def(t_vect a, t_vect b, double fi)
{
	return (fabs(mod_vector(a)) * fabs(mod_vector(b)) * sin(fi));
}

double		triple_product(t_vect a, t_vect b, t_vect c)
{
	return (a.x * (b.y * c.z - b.z * c.y) - a.y * (b.x * c.z - b.z * c.x)
		+ a.z * (b.x * c.y - b.y * c.x));
}

double		triple_product_def(t_vect a, t_vect b, t_vect c)
{
	return (dot_product(cross_product(a, b), c));
}
