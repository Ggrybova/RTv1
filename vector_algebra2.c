/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_algebra2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 13:24:18 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/29 14:10:17 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libvect.h"

t_vect		sum_vector(t_vect a, t_vect b)
{
	t_vect	v;

	v.x = a.x + b.x;
	v.y = a.y + b.y;
	v.z = a.z + b.z;
	return (v);
}

t_vect		scalar_multipl(double c, t_vect a)
{
	t_vect	v;

	v.x = c * a.x;
	v.y = c * a.y;
	v.z = c * a.z;
	return (v);
}

t_vect		dif_vector(t_vect a, t_vect b)
{
	t_vect	v;

	v = scalar_multipl(-1, b);
	v = sum_vector(a, v);
	return (v);
}

double		dot_product(t_vect a, t_vect b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

double		dot_product_def(t_vect a, t_vect b, double fi)
{
	return (mod_vector(a) * mod_vector(b) * cos(fi));
}
