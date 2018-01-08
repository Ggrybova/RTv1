/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:41:43 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/28 21:58:40 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int			find_min_dist(double a1, double a2, double a3, double a4)
{
	int		i;
	double	d[4];
	double	min_d[2];

	d[0] = a1;
	d[1] = a2;
	d[2] = a3;
	d[3] = a4;
	i = 0;
	while (d[i] == -1 && i < 4)
		i++;
	if (i == 4)
		return (-1);
	min_d[0] = i;
	min_d[1] = d[i];
	while (++i < 4)
	{
		if (d[i] != -1)
		{
			min_d[0] = (min_d[1] <= d[i]) ? min_d[0] : i;
			min_d[1] = (min_d[1] <= d[i]) ? min_d[1] : d[i];
		}
	}
	return ((int)min_d[0] + 1);
}

int			get_norm_vect(t_rtv *m, int i, int figure)
{
	t_vect	a;

	if (figure == 1)
	{
		m->p = m->scene->sph[i].p;
		m->n = normaliz_vector(dif_vector(m->p, m->scene->sph[i].c));
	}
	else if (figure == 2)
	{
		m->p = m->scene->cyl[i].p;
		a = dif_vector(m->p, fill_vector(m->scene->cyl[i].c.x,
					m->scene->cyl[i].c.y, m->scene->cyl[i].c.z));
		m->n = normaliz_vector(dif_vector(a, scalar_multipl(dot_product(a,
					m->scene->cyl[i].dir), m->scene->cyl[i].dir)));
	}
	else if (figure == 3)
	{
		m->p = m->scene->con[i].p;
		a = dif_vector(m->p, fill_vector(m->scene->con[i].c.x,
					m->scene->con[i].c.y, m->scene->con[i].c.z));
		m->n = dif_vector(a, scalar_multipl(dot_product(a,
					m->scene->con[i].dir), m->scene->con[i].dir));
		m->n = normaliz_vector(m->n);
	}
	return (i);
}

int			intersection(t_rtv *m, t_vect e, t_vect d)
{
	int		i[4];
	int		min;

	i[0] = intersect_sph(m, e, d);
	i[1] = intersect_cyl(m, e, d);
	i[2] = intersect_con(m, e, d);
	i[3] = intersect_pl(m, e, d);
	min = find_min_dist(m->scene->min_d_sph, m->scene->min_d_cyl,
			m->scene->min_d_con, m->scene->min_d_pl);
	m->scene->hit = min - 1;
	if (min == 1)
		return (get_norm_vect(m, i[0], 1));
	if (min == 2)
		return (get_norm_vect(m, i[1], 2));
	if (min == 3)
		return (get_norm_vect(m, i[2], 3));
	if (min == 4)
	{
		m->p = m->scene->pl[i[3]].p;
		m->n = m->scene->pl[i[3]].dir;
		return (i[3]);
	}
	return (-1);
}
