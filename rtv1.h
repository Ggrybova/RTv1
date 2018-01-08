/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:21:51 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/29 14:06:05 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H
# define WIDTH 1000
# define HEIGHT 1000
# define PI 3.14159265359
# define SCREEN 100
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include "input_struct.h"
# include "libvect.h"
# include <stdlib.h>
# include <math.h>

typedef struct	s_im
{
	int			w;
	int			h;
	void		*im;
	char		*addr;
	int			b_p_p;
	int			size_l;
	int			end;
}				t_im;

typedef struct	s_rtv
{
	void		*rtv;
	void		*win;
	t_im		image;

	t_scene		*scene;
	t_color		color;
	t_vect		e;
	t_vect		d;
	t_vect		s;
	t_vect		p;
	double		t1;
	double		t2;
	t_vect		n;
	t_vect		l;
	int			inter;
	int			n_obj;
}				t_rtv;

char			*read_file(char *file);
double			get_rational_nbr(char *a);
void			num_obj(t_scene *s, char *str);
t_scene			*read_input(char *file);
char			*cut_str(char *str, char c);
t_color			color(char *str);
t_color			fill_color(int r, int g, int b);
t_color			choose_color(t_scene *s, int hit, int i);
t_coord			record_coord(char *a);
int				rtv1(t_rtv *m);
void			get_sphere(t_scene *s, char *a);
void			get_cylinder(t_scene *s, char *a);
void			get_cone(t_scene *s, char *a);
int				intersection(t_rtv *m, t_vect e, t_vect d);
int				intersect_sph(t_rtv *m, t_vect e, t_vect d);
int				intersect_sph_t(t_rtv *m, t_vect e, t_vect d, t_sphere *sph);
int				min_dist_sph(t_scene *s, int n);
int				intersect_cyl(t_rtv *m, t_vect e, t_vect d);
int				intersect_cyl_t(t_rtv *m, t_vect e, t_vect d, t_cylinder *cyl);
int				min_dist_cyl(t_scene *s, int n);
int				intersect_con(t_rtv *m, t_vect e, t_vect d);
int				intersect_con_t(t_rtv *m, t_vect e, t_vect d, t_cone *con);
int				min_dist_con(t_scene *s, int n);
void			get_plane(t_scene *s, char *a);
int				intersect_pl(t_rtv *m, t_vect e, t_vect d);
int				intersect_pl_t(t_rtv *m, t_vect e, t_vect d, t_plane *pl);
int				min_dist_pl(t_scene *s, int n);
t_color			shading(t_rtv *m, t_color color, t_vect n, int hit);
int				hook_func(int key);
int				hook_func2(void *ss);

void			*mlx_init();

#endif
