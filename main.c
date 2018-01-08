/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 18:32:07 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/29 15:09:02 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		pixel_coord_img(t_im *img, int x, int y, t_color *c)
{
	img->addr[y * img->size_l + x * (img->b_p_p / 8) + 2] = c->red;
	img->addr[y * img->size_l + x * (img->b_p_p / 8)] = c->green;
	img->addr[y * img->size_l + x * (img->b_p_p / 8) + 1] = c->blue;
}

void		put_ray(t_rtv *m)
{
	int		x;
	int		y;
	int		i;

	x = -1;
	while (++x < WIDTH && (y = -1) >= -1)
	{
		m->s.x = ((2 * (x + 1) / (double)WIDTH - 1) * ((double)WIDTH
					/ (double)HEIGHT) * tan(30 * PI / 180));
		while (++y < HEIGHT)
		{
			m->s.y = (2 * (y + 1) / (double)HEIGHT - 1) * tan(30 * PI / 180);
			m->color = m->scene->back;
			m->d = dif_vector(m->s, m->e);
			m->d = normaliz_vector(m->d);
			i = intersection(m, m->e, m->d);
			if (i >= 0)
			{
				m->color = choose_color(m->scene, m->scene->hit, i);
				m->color = shading(m, m->color, m->n, m->scene->hit);
			}
			pixel_coord_img(&m->image, x, y, &m->color);
		}
	}
}

int			rtv1(t_rtv *m)
{
	m->image.im = mlx_new_image(m->rtv, WIDTH, HEIGHT);
	m->image.addr = mlx_get_data_addr(m->image.im, &(m->image.b_p_p),
			&(m->image.size_l), &(m->image.end));
	m->e = fill_vector(m->scene->cam.cam.x, m->scene->cam.cam.y,
			m->scene->cam.cam.z);
	m->s.z = SCREEN;
	m->inter = -1;
	put_ray(m);
	mlx_put_image_to_window(m->rtv, m->win, m->image.im, 0, 0);
	mlx_destroy_image(m->rtv, m->image.im);
	return (1);
}

char		*choose_scene(char *s)
{
	if (ft_strncmp(s, "1", ft_strlen(s)) == 0)
		return ("scene1");
	else if (ft_strncmp(s, "2", ft_strlen(s)) == 0)
		return ("scene2");
	else if (ft_strncmp(s, "3", ft_strlen(s)) == 0)
		return ("scene3");
	else if (ft_strncmp(s, "4", ft_strlen(s)) == 0)
		return ("scene4");
	else
		return ("scene5");
}

int			main(int argc, char **argv)
{
	t_rtv	*m;
	char	*file;

	if (argc != 2 || !(ft_atoi(argv[1]) >= 1 && ft_atoi(argv[1]) <= 5))
	{
		ft_putstr("Available parameters:\n\t1 - scene 1:  2 sphere, one spot, "
			"shine effect;\n\t2 - scene 2:  a sphere, a cylinder, a  cone, one "
			"spot, shine effect;\n\t3 - scene 3:  2 cylinder, one spot, shine "
			"effect;\n\t4 - scene 4:  2 cone, a  plane, one spot, shine effect;"
			"\n\t5 - scene 5:  a sphere, a cylinder, a cone, one spot, shine "
			"effect;\n");
		exit(0);
	}
	m = (t_rtv *)malloc(sizeof(t_rtv));
	m->rtv = mlx_init();
	m->win = mlx_new_window(m->rtv, WIDTH, HEIGHT, "RTv1");
	file = choose_scene(argv[1]);
	m->scene = read_input(file);
	m->scene->back = fill_color(0, 0, 0);
	rtv1(m);
	mlx_hook(m->win, 2, 5, hook_func, m);
	mlx_hook(m->win, 17, 1L << 17, hook_func2, m);
	mlx_loop(m->rtv);
	sleep(200);
}
