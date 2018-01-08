/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:13:07 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/29 14:07:17 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			get_cylinder(t_scene *s, char *a)
{
	static int	j;
	t_coord		l;

	if (!j)
		j = 0;
	a = cut_str(a, ' ');
	l = record_coord(a);
	s->cyl[j].c = fill_vector(l.x, l.y, l.z);
	a = cut_str(a, ' ');
	l = record_coord(a);
	s->cyl[j].dir = fill_vector(l.x, l.y, l.z);
	s->cyl[j].dir = normaliz_vector(s->cyl[j].dir);
	a = cut_str(a, ' ');
	s->cyl[j].r = get_rational_nbr(a);
	a = cut_str(a, ' ');
	s->cyl[j].col = color(a);
	j++;
}

int				intersect_cyl_t(t_rtv *m, t_vect e, t_vect d, t_cylinder *cyl)
{
	double		a;
	double		b;
	double		c;
	t_vect		tmp;

	d = dif_vector(d, scalar_multipl(dot_product(d, cyl->dir), cyl->dir));
	tmp = dif_vector(dif_vector(e, cyl->c), scalar_multipl(dot_product(cyl->dir,
					dif_vector(e, cyl->c)), cyl->dir));
	a = dot_product(d, d);
	b = 2 * dot_product(d, tmp);
	c = dot_product(tmp, tmp) - pow(cyl->r, 2);
	if (b * b - 4 * a * c < 0)
		return (-1);
	else if (b * b - 4 * a * c == 0)
	{
		m->t1 = -b / 2 / a;
		return (0);
	}
	m->t1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	m->t2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	if (m->t1 < 0 || m->t2 < 0)
		return (-1);
	return (1);
}

int				min_dist_cyl(t_scene *s, int n)
{
	int			i;
	double		d[n];
	double		min_d[2];

	i = -1;
	while (++i < n)
		d[i] = s->cyl[i].dist;
	i = 0;
	while (d[i] == -1 && i < n)
		i++;
	s->min_d_cyl = -1;
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
	s->min_d_cyl = min_d[1];
	return ((int)min_d[0]);
}

int				intersect_cyl(t_rtv *m, t_vect e, t_vect d)
{
	int			i;

	i = -1;
	while (++i < m->scene->n_cyl)
	{
		m->inter = intersect_cyl_t(m, e, d, &m->scene->cyl[i]);
		if (m->inter >= 0)
		{
			m->t1 = fmin(m->t1, m->t2);
			m->scene->cyl[i].p = sum_vector(e, scalar_multipl(m->t1, d));
			m->scene->cyl[i].dist = m->t1;
		}
		else
			m->scene->cyl[i].dist = -1;
	}
	i = min_dist_cyl(m->scene, m->scene->n_cyl);
	return (i);
}
