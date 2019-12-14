/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_rt.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 10:01:14 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/23 10:50:18 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINI_RT_H
# define MINI_RT_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "../mylibft/libft.h"
# include "mlx.h"

/*
** Defining all different object use by miniRT
*/

typedef struct			s_vec3
{
	float				x;
	float				y;
	float				z;
}						t_vec3;

typedef struct			s_ray
{
	t_vec3				o;
	t_vec3				d;
}						t_ray;

typedef struct			s_sphere
{
	t_vec3				position;
	float				radius;
	t_vec3				color;
	struct s_sphere		*next;
}						t_sphere;

typedef struct			s_plane
{
	t_vec3				position;
	t_vec3				orientation;
	t_vec3				color;
	struct s_plane		*next;
}						t_plane;

typedef struct			s_square
{
	t_vec3				position;
	t_vec3				ori;
	float				size;
	t_vec3				color;
	struct s_square		*next;
}						t_square;

typedef struct			s_cylinder
{
	t_vec3				position;
	t_vec3				orientation;
	float				diameter;
	float				height;
	t_vec3				color;
	struct s_cylinder	*next;
}						t_cylinder;

typedef struct			s_triangle
{
	t_vec3				point1;
	t_vec3				point2;
	t_vec3				point3;
	t_vec3				color;
	struct s_triangle	*next;
}						t_triangle;

typedef struct			s_screen
{
	int					x;
	int					y;
}						t_screen;

typedef struct			s_alight
{
	float				ratio;
	t_vec3				color;
}						t_alight;

typedef struct			s_light
{
	t_vec3				position;
	float				ratio;
	t_vec3				color;
	struct s_light		*next;
}						t_light;

typedef struct			s_camera
{
	t_vec3				position;
	t_vec3				orientation;
	int					fov;
	struct s_camera		*next;
	struct s_camera		*prev;
}						t_camera;

typedef struct			s_phong
{
	t_vec3				am;
	t_vec3				sp;
	t_vec3				di;
}						t_phong;

typedef	struct			s_hit
{
	float				t;
	t_vec3				normal;
	t_sphere			*sphere;
	t_plane				*plane;
	t_square			*square;
	t_cylinder			*cylinder;
	t_triangle			*triangle;
	t_vec3				phit;
}						t_hit;

typedef struct			s_scene
{
	t_screen			*screen;
	t_alight			*al;
	t_camera			*camerasfirst;
	t_camera			*cameras;
	t_light				*lightsfirst;
	t_light				*lights;
	t_sphere			*spheres;
	t_plane				*planes;
	t_square			*squares;
	t_cylinder			*cylinders;
	t_triangle			*triangles;
}						t_scene;

t_scene					*parser(int	fd);
int						manage_window(t_scene *scene);
t_camera				*ft_lstlast_cam(t_camera *lst);

/*
** lst last
*/
t_sphere				*ft_lstlast_sphere(t_sphere *lst);
t_plane					*ft_lstlast_plane(t_plane *lst);
t_square				*ft_lstlast_square(t_square *lst);
t_cylinder				*ft_lstlast_cylinder(t_cylinder *lst);
t_triangle				*ft_lstlast_triangle(t_triangle *lst);
t_camera				*ft_lstlast_cam(t_camera *lst);
t_light					*ft_lstlast_light(t_light *lst);

/*
**	error manager
*/
t_vec3					man_er(int ret, char axe, int pl, char *type);

float					ft_atof(char *num);

int						get_each_digi_i(char *ln, int i, int *error);
float					get_each_digi_f(char *ln, int i, int *error);

t_vec3					get_vec3(char *ln, int *i, int pl, char *type);
t_vec3					get_color(char *ln, int *i, int pl, char *type);
t_vec3					manage_camera(t_scene **scene, char *ln, int pl);
int						test_rot(t_vec3 obj);
t_vec3					test_endline(char *ln, int i, int pl);
t_vec3					manage_sphere(t_scene **scene, char *ln, int pl);
t_vec3					manage_screen(t_scene **scene, char *ln, int pl);
t_vec3					manage_alight(t_scene **scene, char *ln, int pl);
t_vec3					manage_light(t_scene **scene, char *ln, int pl);
t_vec3					manage_plane(t_scene **scene, char *ln, int pl);
t_vec3					manage_square(t_scene **scene, char *ln, int pl, int i);
t_vec3					manage_cylinder(t_scene **scene, char *ln, int pl);
t_vec3					manage_triangle(t_scene **scene, char *ln, int pl);
t_vec3					rt_manager(t_scene **scene, char *type, char *ln, \
									int pl);
char					*detach_type(char	*ln, int pl);

/*
**	vector operations
*/

float					magnitude(t_vec3 a);
t_vec3					invert(t_vec3 vec);
t_vec3					cross(t_vec3 v1, t_vec3 v2);
float					dot(t_vec3 v1, t_vec3 v2);
t_vec3					normalize(t_vec3 vec);
t_vec3					mult_vec_n(t_vec3 vec, float n);
t_vec3					sub_vec_n(t_vec3 vec, float n);
t_vec3					sub_vecs(t_vec3 vec, t_vec3 vec2);
t_vec3					div_vec_n(t_vec3 vec, float n);
t_vec3					mult_vecs(t_vec3 vec, t_vec3 vec2);
t_vec3					add_vecs(t_vec3 vec, t_vec3 vec2);
t_vec3					vector(float x, float y, float z);
float					dist(t_vec3 a, t_vec3 b);
t_vec3					cpy_vec3(t_vec3 src);
int						vector_cmp(t_vec3 v1, t_vec3 v2);
t_vec3					calculate_rot(t_vec3 *c2, t_vec3 *c3, t_vec3 rot, \
										t_vec3 to);
t_vec3					apply_rot(t_vec3 pos, t_vec3 dir, t_vec3 rot);
int						compute_ray(t_ray *ray, int x, int y, t_scene *s);
void					intersect_sphere(t_sphere *sphere, t_ray ray, \
															t_hit *hit);
t_hit					get_hit_sphere(t_scene *scene, t_ray ray, \
															t_hit min_h);
void					init_hit(t_hit *hit);
t_vec3					process_normal(t_ray ray, t_vec3 normal);
void					intersect_plane(t_plane *plane, t_ray ray, t_hit *hit);
t_hit					get_hit_plane(t_scene *scene, t_ray ray, t_hit min_h);
t_vec3					clamp(t_vec3 vec);
void					intersect_square(t_square *square, t_ray ray, \
															t_hit *hit);
void					intersect_triangle(t_triangle *triangle, t_ray ray, \
															t_hit *hit);
t_hit					get_hit_square(t_scene *scene, t_ray ray, t_hit min_h);
t_hit					get_hit_triangle(t_scene *scene, t_ray ray, \
														t_hit min_h);
void					intersect_cylinder(t_cylinder *cy, t_ray ra, \
														t_hit *hit);
t_hit					get_hit_cylinder(t_scene *scene, t_ray ray, \
														t_hit min_h);
t_hit					get_hit(t_scene *scene, t_ray ray);
t_vec3					get_hit_color(t_hit hit);
t_vec3					font_color();
int						t_vec3_to_int(t_vec3 color, float intensitie);
void					init_vec3(t_vec3 *vec);
float					maxi(float a, float b);
int						obj_cmp(t_hit obj, t_hit hit);
t_vec3					get_color_w(t_scene *sc, t_ray ray, int sep);
void					free_3(t_vec3 *a, t_vec3 *b, t_vec3 *c);
void					free_2(t_vec3 *a, t_vec3 *b);
void					free_4(t_vec3 *a, t_vec3 *b, t_vec3 *c, t_vec3 *d);
int						destroy_n_exit(void	*g_mlx, void *g_win, \
													t_scene **scene);
int						writebmp(int w, int h, char *img_data);
void					free_lis(t_scene **s);
void					free_cams(t_scene **s);
void					free_trs(t_scene **s);
void					free_sqs(t_scene **s);
void					free_cys(t_scene **s);
void					free_sps(t_scene **s);
t_vec3					c_to_vec(t_vec3 color);

# define V_FALSE vector(-INFINITY,-INFINITY,-INFINITY)
# define V_TRUE vector(INFINITY,INFINITY,INFINITY)

#endif
