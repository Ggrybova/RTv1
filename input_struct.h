/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_struct.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:21:11 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/29 14:21:23 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_STRUCT_H
# define INPUT_STRUCT_H
# include "libvect.h"

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct	s_coord
{
	double		x;
	double		y;
	double		z;
}				t_coord;

typedef struct	s_camera
{
	t_coord		cam;
	t_vect		dir;
	t_vect		dir_x;
	t_vect		dir_y;

}				t_camera;

typedef struct	s_sphere
{
	t_vect		c;
	double		r;
	t_color		col;
	t_coord		centre;
	double		dist;
	t_vect		p;
}				t_sphere;

typedef struct	s_cylinder
{
	t_vect		dir;
	t_vect		c;
	double		r;
	t_color		col;
	double		dist;
	t_vect		p;
	t_vect		n;
}				t_cylinder;

typedef struct	s_cone
{
	t_vect		dir;
	t_vect		c;
	double		ang;
	t_color		col;
	double		dist;
	t_vect		p;
	t_vect		n;
}				t_cone;

typedef struct	s_plane
{
	t_vect		dir;
	t_vect		q;
	t_color		col;
	double		dist;
	t_vect		p;
	t_vect		n;
}				t_plane;

typedef struct	s_scene
{
	t_camera	cam;
	t_coord		lig;
	double		scr;
	int			n_sph;
	t_sphere	*sph;
	double		min_d_sph;
	int			n_cyl;
	t_cylinder	*cyl;
	double		min_d_cyl;
	int			n_con;
	t_cone		*con;
	double		min_d_con;
	int			n_pl;
	t_plane		*pl;
	double		min_d_pl;
	t_color		back;
	int			hit;
}				t_scene;

#endif
