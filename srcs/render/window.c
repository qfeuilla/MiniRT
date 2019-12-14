/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 15:40:07 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/23 10:57:46 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"
#define PI 3.1415926

void		*g_mlx;
void		*g_win;
void		*g_image_ptr;
int			g_i;
int			g_h;
int			g_bpp;
int			g_size_line;
int			g_endian;
char		*g_m;
int			g_d;
int			g_s;

int			render_scene(t_scene *scene)
{
	int			x;
	int			y;
	t_ray		ray;
	t_vec3		c;

	if (g_i-- <= 0)
		return (1);
	ray.d = vector(0, 0, 0);
	mlx_clear_window(g_mlx, g_win);
	g_m = mlx_get_data_addr(g_image_ptr, &g_bpp, &g_size_line, &g_endian);
	y = 0;
	while (y++ < scene->screen->y && (x = 0) == 0)
	{
		while (x++ < scene->screen->x)
		{
			compute_ray(&ray, x, y, scene);
			c = get_color_w(scene, ray, g_s);
			*g_m++ = (int)c.z;
			*g_m++ = (int)c.y;
			*g_m++ = (int)c.x;
			*g_m++ = 0;
		}
	}
	mlx_put_image_to_window(g_mlx, g_win, g_image_ptr, 0, 0);
	return (1);
}

void		key_utils(int key, t_scene **s)
{
	if (key == 49 && (g_i = 1))
		(*s)->cameras->position.y += 20;
	if (key == 256 && (g_i = 1))
		(*s)->cameras->position.y -= 20;
	if (key == 126 && (g_i = 1))
		(*s)->cameras->position.z += 20;
	if (key == 125 && (g_i = 1))
		(*s)->cameras->position.z -= 20;
	if (key == 123 && (g_i = 1))
		(*s)->cameras->position.x -= 20;
	if (key == 124 && (g_i = 1))
		(*s)->cameras->position.x += 20;
	if (key == 36 && (g_i = 1))
	{
		mlx_clear_window(g_mlx, g_win);
		mlx_string_put(g_mlx, g_win, 20, 20, 100000, "loading");
	}
	if (key == 6)
	{
		if (!(*s)->cameras->prev)
			(*s)->cameras = ft_lstlast_cam((*s)->cameras);
		else
			(*s)->cameras = (*s)->cameras->prev;
		ft_printf("prev %g_i\n", (*s)->cameras->fov);
	}
}

int			manage_key(int key, t_scene **s)
{
	ft_printf("Key in Win : %d\n", key);
	if (key == 53 || g_d)
	{
		ft_printf("End of mini_RT\n");
		free(g_image_ptr);
		destroy_n_exit(g_mlx, g_win, s);
	}
	if (key == 1 && g_m)
		writebmp((*s)->screen->x, (*s)->screen->y, \
		g_m);
	if (key == 8)
	{
		if (!(*s)->cameras->next)
			(*s)->cameras = (*s)->camerasfirst;
		else
			(*s)->cameras = (*s)->cameras->next;
		ft_printf("next %g_i\n", (*s)->cameras->fov);
	}
	if (key == 35)
		g_s = g_s == 0 ? 1 : 0;
	key_utils(key, s);
	return (0);
}

int			end(t_scene **scene)
{
	g_d = 1;
	manage_key(1, scene);
	return (0);
}

int			manage_window(t_scene *scene)
{
	g_h = 0;
	g_i = 0;
	g_d = 0;
	g_s = 0;
	scene->camerasfirst = scene->cameras;
	scene->lightsfirst = scene->lights;
	g_mlx = mlx_init();
	g_win = mlx_new_window(g_mlx, scene->screen->x, \
							scene->screen->y, "MiniRT");
	mlx_string_put(g_mlx, g_win, 20, 20, 100000, "enter to render");
	mlx_string_put(g_mlx, g_win, 20, 40, 100000, "z c to change cam");
	mlx_string_put(g_mlx, g_win, 20, 60, 100000, "ESC to quit");
	mlx_string_put(g_mlx, g_win, 20, 80, 100000, "s to save image in bmp");
	mlx_string_put(g_mlx, g_win, 20, 100, 100000, "^><v to move the camera");
	mlx_string_put(g_mlx, g_win, 20, 120, 100000, "p to sepia filter");
	mlx_string_put(g_mlx, g_win, 20, 140, 100000, "load long for big screen");
	g_image_ptr = mlx_new_image(g_mlx, scene->screen->x, \
				scene->screen->y);
	mlx_key_hook(g_win, manage_key, &scene);
	mlx_loop_hook(g_mlx, render_scene, scene);
	mlx_hook(g_win, 17, 1L << 0, end, &scene);
	mlx_loop(g_mlx);
	return (1);
}
