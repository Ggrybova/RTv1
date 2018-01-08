/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libvect.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 13:43:12 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/29 14:04:17 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBVECT_H
# define LIBVECT_H
# include <math.h>

typedef struct	s_dir
{
	double		cos_u;
	double		cos_v;
	double		cos_w;
}				t_dir;

typedef struct	s_vect
{
	double		x;
	double		y;
	double		z;
}				t_vect;

t_vect			fill_vector(double x, double y, double z);
t_vect			unit_vector(void);
t_vect			null_vector(void);
t_dir			direct_cos(t_vect a);
double			mod_vector(t_vect a);
t_vect			sum_vector(t_vect a, t_vect b);
t_vect			scalar_multipl(double c, t_vect a);
t_vect			dif_vector(t_vect a, t_vect b);
double			dot_product(t_vect a, t_vect b);
double			dot_product_def(t_vect a, t_vect b, double fi);
double			angle_vector(t_vect a, t_vect b);
t_vect			cross_product(t_vect a, t_vect b);
double			cross_product_def(t_vect a, t_vect b, double fi);
double			triple_product(t_vect a, t_vect b, t_vect c);
double			triple_product_def(t_vect a, t_vect b, t_vect c);
int				collin_vector(t_vect a, t_vect b);
int				orthog_vector(t_vect a, t_vect b);
double			vector_project(t_vect a, t_vect b);
t_vect			normaliz_vector(t_vect a);

#endif
