/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:34:21 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/29 14:17:03 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		lambert_shading(t_vect n, t_vect l, int hit)
{
	double	l_d;

	if (hit == 3)
	{
		l_d = dot_product(l, n) / mod_vector(l);
		if (l_d > 0)
		{
			l_d = (mod_vector(l) - 0) * (0 - 1) / (500 - 0) + 1;
		}
	}
	else
		l_d = dot_product(l, n) / mod_vector(l);
	if (l_d < 0)
		l_d = 0;
	if (l_d > 1)
		l_d = 1;
	return (l_d);
}

double		specular_shading(t_vect n, t_vect l, t_vect p, int hit)
{
	t_vect	h;
	t_vect	tmp;
	double	spec_coef;
	double	l_s;

	spec_coef = 0.95;
	tmp = scalar_multipl(-1, p);
	p = normaliz_vector(tmp);
	h = sum_vector(l, p);
	h = normaliz_vector(h);
	l_s = dot_product(n, h);
	l_s = pow(l_s, 1);
	if (hit == 3)
		l_s = 0;
	if (l_s > 1)
		l_s = 1;
	else if (l_s >= spec_coef && l_s < 1)
		l_s = 1.0 - ((1.0 - l_s) / (1 - spec_coef));
	else
		l_s = 0;
	return (l_s);
}

t_color		shading(t_rtv *m, t_color color, t_vect n, int hit)
{
	double	l_d;
	double	l_s;
	t_color	p;
	t_vect	l0;

	l0 = sum_vector(m->e, fill_vector(m->scene->lig.x, m->scene->lig.y,
			m->scene->lig.z));
	m->l = dif_vector(l0, m->p);
	l_d = lambert_shading(n, m->l, hit);
	l_s = specular_shading(n, m->l, m->p, hit);
	p.blue = (int)((l_d * color.blue + l_s * 255));
	p.green = (int)((l_d * color.green + l_s * 255));
	p.red = (int)((l_d * color.red + l_s * 255));
	p.blue = (p.blue > 255) ? 255 : p.blue;
	p.green = (p.green > 255) ? 255 : p.green;
	p.red = (p.red > 255) ? 255 : p.red;
	return (p);
}
