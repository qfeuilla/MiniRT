/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:29:44 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/22 17:21:50 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

int			test_rot(t_vec3 obj)
{
	if (obj.x < -1 || obj.x > 1 || obj.y < -1 || obj.y > 1 \
		|| obj.z < -1 || obj.z > 1)
		return (0);
	if (obj.x == 0 && obj.y == 0 && obj.z == 0)
		return (0);
	return (1);
}

t_vec3		test_endline(char *ln, int i, int pl)
{
	while (ln[i] == ' ')
		i++;
	if (ln[i])
		return (man_er(-8, '1', pl, NULL));
	return (V_TRUE);
}

void		init_scene(t_scene **scene)
{
	(*scene)->screen = NULL;
	(*scene)->al = NULL;
	(*scene)->lights = NULL;
	(*scene)->cameras = NULL;
	(*scene)->triangles = NULL;
	(*scene)->squares = NULL;
	(*scene)->cylinders = NULL;
	(*scene)->spheres = NULL;
	(*scene)->planes = NULL;
}

void		*free_exit(t_scene **scene, char **type, char **ln)
{
	free(*scene);
	free(*ln);
	free(*type);
	return (NULL);
}

t_scene		*parser(int fd)
{
	t_scene		*scene;
	char		*ln;
	char		*type;
	int			ret;
	int			i;

	i = 0;
	scene = (t_scene *)malloc(sizeof(t_scene));
	init_scene(&scene);
	while ((ret = get_next_line(fd, &ln)) >= 0)
	{
		if (!(ln[0] == '\0'))
		{
			if (!(type = detach_type(ln, i)) || \
				vector_cmp(rt_manager(&scene, type, ln, i + 1), V_FALSE))
				return (free_exit(&scene, &type, &ln));
			free(type);
		}
		free(ln);
		if (++i && !ret)
			break ;
	}
	scene->screen->x = scene->screen->x >= 2560 ? 2560 : scene->screen->x;
	scene->screen->y = scene->screen->y >= 1440 ? 1440 : scene->screen->y;
	return (scene);
}
