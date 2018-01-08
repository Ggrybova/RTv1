/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 21:54:19 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/29 14:06:46 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			get_sphere(t_scene *s, char *a)
{
	static int	i;

	if (!i)
		i = 0;
	a = cut_str(a, ' ');
	s->sph[i].centre = record_coord(a);
	s->sph[i].c = fill_vector(s->sph[i].centre.x, s->sph[i].centre.y,
			s->sph[i].centre.z);
	a = cut_str(a, ' ');
	s->sph[i].r = get_rational_nbr(a);
	a = cut_str(a, ' ');
	s->sph[i].col = color(a);
	i++;
}

int				intersect_sph_t(t_rtv *m, t_vect e, t_vect d, t_sphere *sph)
{
	double		a;
	double		b;
	double		c;
	double		disc;
	t_vect		tmp;

	tmp = dif_vector(e, sph->c);
	a = dot_product(d, d);
	b = 2 * dot_product(d, tmp);
	c = dot_product(tmp, tmp) - pow(sph->r, 2);
	disc = b * b - 4 * a * c;
	if (disc < 0)
		return (-1);
	m->t1 = (-b - sqrt(b * b - 4 * a * c)) / 2 / a;
	m->t2 = (-b + sqrt(b * b - 4 * a * c)) / 2 / a;
	if (m->t1 < 0 && m->t2 < 0)
		return (-1);
	return (1);
}

int				min_dist_sph(t_scene *s, int n)
{
	int			i;
	double		d[n];
	double		min_d[2];

	i = -1;
	while (++i < n)
		d[i] = s->sph[i].dist;
	i = 0;
	while (d[i] == -1 && i < n)
		i++;
	s->min_d_sph = -1;
	if (i == n)
		return (-1);
	min_d[0] = i;
	min_d[1] = d[i];
	while (++i < n)
	{
		if (d[i] != -1)
		{
			min_d[0] = (min_d[1] <= d[i]) ? min_d[0] : i;
			min_d[1] = (min_d[1] <= d[i]) ? min_d[1] : d[i];
		}
	}
	s->min_d_sph = min_d[1];
	return ((int)min_d[0]);
}

int				intersect_sph(t_rtv *m, t_vect e, t_vect d)
{
	int			i;

	i = -1;
	while (++i < m->scene->n_sph)
	{
		m->inter = intersect_sph_t(m, e, d, &m->scene->sph[i]);
		if (m->inter >= 0)
		{
			m->t1 = (m->t1 < 0) ? m->t2 : m->t1;
			m->scene->sph[i].p = sum_vector(e, scalar_multipl(m->t1, d));
			m->scene->sph[i].dist = m->t1;
		}
		else
			m->scene->sph[i].dist = -1;
	}
	i = min_dist_sph(m->scene, m->scene->n_sph);
	return (i);
}
