/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrybova <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 17:08:25 by ggrybova          #+#    #+#             */
/*   Updated: 2017/10/29 14:26:24 by ggrybova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

char		*read_file(char *file)
{
	char	*s;
	char	*l;
	char	buf[10 + 1];
	int		fd;

	s = ft_strnew(0);
	if ((fd = open(file, O_RDONLY)) < 0 || read(fd, buf, 0) < 0 || !s)
	{
		ft_putstr("Cannot open file\n");
		exit(0);
	}
	ft_bzero(buf, 10 + 1);
	while (read(fd, buf, 10) > 0)
	{
		l = ft_strjoin(s, buf);
		free(s);
		s = ft_strdup(l);
		free(l);
		ft_bzero(buf, 10 + 1);
	}
	close(fd);
	return (s);
}

void		num_obj(t_scene *s, char *str)
{
	char	*a;

	s->n_sph = 0;
	s->n_cyl = 0;
	s->n_con = 0;
	s->n_pl = 0;
	a = str;
	while ((a = ft_strstr(a, "sphere")) != NULL && a++)
		s->n_sph++;
	a = str;
	while ((a = ft_strstr(a, "cylinder")) != NULL && a++)
		s->n_cyl++;
	a = str;
	while ((a = ft_strstr(a, "cone")) != NULL && a++)
		s->n_con++;
	a = str;
	while ((a = ft_strstr(a, "plane")) != NULL && a++)
		s->n_pl++;
	free(a);
}

void		fill_data(t_scene *s, char *a, int i)
{
	if (i == 0 && ft_strncmp(a, "camera", 6) == 0)
		s->cam.cam = record_coord(cut_str(a, ' '));
	else if (i == 1 && ft_strncmp(a, "light", 5) == 0)
		s->lig = record_coord(cut_str(a, ' '));
	else if (i > 1)
	{
		if (ft_strncmp(a, "sphere", 6) == 0)
			get_sphere(s, a);
		else if (ft_strncmp(a, "cylinder", 8) == 0)
			get_cylinder(s, a);
		else if (ft_strncmp(a, "cone", 4) == 0)
			get_cone(s, a);
		else if (ft_strncmp(a, "plane", 5) == 0)
			get_plane(s, a);
	}
	else
	{
		ft_putstr("Not correct input file\n");
		exit(0);
	}
}

t_scene		*read_input(char *file)
{
	int		i;
	char	*l;
	t_scene	*s;
	char	*str;
	char	*tmp;

	s = (t_scene *)malloc(sizeof(t_scene));
	str = read_file(file);
	num_obj(s, str);
	s->sph = (t_sphere *)malloc(sizeof(t_sphere) * s->n_sph);
	s->cyl = (t_cylinder *)malloc(sizeof(t_cylinder) * s->n_cyl);
	s->con = (t_cone *)malloc(sizeof(t_cone) * s->n_con);
	s->pl = (t_plane *)malloc(sizeof(t_plane) * s->n_pl);
	i = -1;
	l = ft_strchr(str, 10);
	while (l != NULL)
	{
		tmp = ft_strsub(str, 0, l - str);
		fill_data(s, tmp, ++i);
		str = cut_str(str, '\n');
		l = ft_strchr(str, 10);
		free(tmp);
	}
	free(l);
	return (s);
}
