/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 22:22:51 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/28 22:37:41 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void			get_cone(t_scene *s, char *a)
{
	static int	j;
	t_coord		l;

	if (!j)
		j = 0;
	a = cut_str(a, ' ');
	l = record_coord(a);
	s->con[j].c = fill_vector(l.x, l.y, l.z);
	a = cut_str(a, ' ');
	l = record_coord(a);
	s->con[j].dir = fill_vector(l.x, l.y, l.z);
	s->con[j].dir = normaliz_vector(s->con[j].dir);
	a = cut_str(a, ' ');
	s->con[j].ang = get_rational_nbr(a);
	s->con[j].ang = s->con[j].ang * PI / 180;
	a = cut_str(a, ' ');
	s->con[j].col = color(a);
	j++;
}

int				intersect_con_t(t_rtv *m, t_vect e, t_vect d, t_cone *con)
{
	double		a;
	double		b;
	double		c;
	t_vect		tmp;
	double		tmp2;

	tmp2 = dot_product(d, con->dir);
	d = dif_vector(d, scalar_multipl(dot_product(d, con->dir), con->dir));
	tmp = dif_vector(dif_vector(e, con->c), scalar_multipl(dot_product(con->dir,
					dif_vector(e, con->c)), con->dir));
	a = cos(con->ang) * cos(con->ang) * dot_product(d, d) - sin(con->ang) *
		sin(con->ang) * pow(tmp2, 2);
	b = 2 * cos(con->ang) * cos(con->ang) * dot_product(d, tmp) - 2 *
		sin(con->ang)
		* sin(con->ang) * tmp2 * dot_product(dif_vector(e, con->c), con->dir);
	c = cos(con->ang) * cos(con->ang) * dot_product(tmp, tmp) - sin(con->ang) *
		sin(con->ang) * pow(dot_product(dif_vector(e, con->c), con->dir), 2);
	if (b * b - 4 * a * c < 0)
		return (-1);
	m->t1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
	m->t2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
	if (m->t1 < 0 || m->t2 < 0)
		return (-1);
	return (1);
}

int				min_dist_con(t_scene *s, int n)
{
	int			i;
	double		d[n];
	double		min_d[2];

	i = -1;
	while (++i < n)
		d[i] = s->con[i].dist;
	i = 0;
	while (d[i] == -1 && i < n)
		i++;
	s->min_d_con = -1;
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
	s->min_d_con = min_d[1];
	return ((int)min_d[0]);
}

int				intersect_con(t_rtv *m, t_vect e, t_vect d)
{
	int			i;

	i = -1;
	while (++i < m->scene->n_con)
	{
		m->inter = intersect_con_t(m, e, d, &m->scene->con[i]);
		if (m->inter >= 0)
		{
			m->t1 = fmin(m->t1, m->t2);
			m->scene->con[i].p = sum_vector(e, scalar_multipl(m->t1, d));
			m->scene->con[i].dist = m->t1;
		}
		else
			m->scene->con[i].dist = -1;
	}
	i = min_dist_con(m->scene, m->scene->n_con);
	return (i);
}
