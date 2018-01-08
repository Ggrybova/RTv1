/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:38:51 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/28 22:41:19 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			get_plane(t_scene *s, char *a)
{
	static int	j;
	t_coord		l;
	t_vect		tmp;

	if (!j)
		j = 0;
	a = cut_str(a, ' ');
	l = record_coord(a);
	s->pl[j].q = fill_vector(l.x, l.y, l.z);
	a = cut_str(a, ' ');
	l = record_coord(a);
	s->pl[j].dir = fill_vector(l.x, l.y, l.z);
	s->pl[j].dir = normaliz_vector(s->pl[j].dir);
	tmp = dif_vector(s->pl[j].q, fill_vector(s->cam.cam.x, s->cam.cam.y,
				s->cam.cam.z));
	if (dot_product(tmp, s->pl[j].dir) > 0)
		s->pl[j].dir = scalar_multipl(-1, s->pl[j].dir);
	a = cut_str(a, ' ');
	s->pl[j].col = color(a);
	j++;
}

int				intersect_pl_t(t_rtv *m, t_vect e, t_vect d, t_plane *pl)
{
	double		a;
	double		b;

	b = dot_product(d, pl->dir);
	if (fabs(b) == 0)
		return (-1);
	a = dot_product(dif_vector(pl->q, e), pl->dir);
	m->t1 = a / b;
	if (m->t1 < 0)
		return (-1);
	return (1);
}

int				min_dist_pl(t_scene *s, int n)
{
	int			i;
	double		d[n];
	double		min_d[2];

	i = -1;
	while (++i < n)
		d[i] = s->pl[i].dist;
	i = 0;
	while (d[i] == -1 && i < n)
		i++;
	s->min_d_pl = -1;
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
	s->min_d_pl = min_d[1];
	return ((int)min_d[0]);
}

int				intersect_pl(t_rtv *m, t_vect e, t_vect d)
{
	int			i;

	i = -1;
	while (++i < m->scene->n_pl)
	{
		m->inter = intersect_pl_t(m, e, d, &m->scene->pl[i]);
		if (m->inter >= 0)
		{
			m->scene->pl[i].p = sum_vector(e, scalar_multipl(m->t1, d));
			m->scene->pl[i].dist = m->t1;
		}
		else
			m->scene->pl[i].dist = -1;
	}
	i = min_dist_pl(m->scene, m->scene->n_pl);
	return (i);
}
