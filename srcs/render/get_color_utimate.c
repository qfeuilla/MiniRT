/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_color_utimate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qfeuilla <qfeuilla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 21:03:59 by qfeuilla          #+#    #+#             */
/*   Updated: 2019/11/23 10:55:59 by qfeuilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/mini_rt.h"

float	calc_diff(t_scene *sc, t_hit hit, t_vec3 *l)
{
	t_vec3		tm;

	tm = sub_vecs(sc->lights->position, hit.phit);
	*l = normalize(tm);
	return (maxi(0.0, dot(hit.normal, *l)) * 0.7);
}

void	do_calc(t_scene *sc, t_hit hit, t_phong **ph, t_ray ray)
{
	t_vec3		l;
	t_vec3		p;
	float		diff;
	float		spec;
	t_vec3		tmp;

	diff = calc_diff(sc, hit, &l);
	tmp = mult_vec_n(hit.normal, 2 * (dot(l, hit.normal)));
	l = sub_vecs(tmp, l);
	p = normalize(l);
	l = invert(ray.d);
	tmp = normalize(l);
	spec = 0.1 * pow(maxi(0.0, dot(p, tmp)), 32);
	tmp = c_to_vec(sc->lights->color);
	l = mult_vec_n(tmp, sc->lights->ratio);
	tmp = mult_vec_n(l, diff);
	l = mult_vec_n(l, spec);
	(*ph)->di = add_vecs((*ph)->di, tmp);
	(*ph)->sp = add_vecs((*ph)->sp, l);
}

void	get_color_loop(t_scene *sc, t_hit hit, t_phong **ph, t_ray ray)
{
	t_ray		shadow;
	t_hit		hit_shad;
	t_vec3		tmp;
	t_vec3		tmp2;
	float		dst;

	shadow.o = sc->lights->position;
	tmp = sub_vecs(hit.phit, sc->lights->position);
	shadow.d = normalize(tmp);
	hit_shad = get_hit(sc, shadow);
	tmp = mult_vec_n(shadow.d, hit_shad.t);
	tmp2 = add_vecs(shadow.o, tmp);
	dst = dist(tmp2, hit.phit);
	if (obj_cmp(hit, hit_shad) || dst >= dist(hit.phit, \
		sc->lights->position))
		do_calc(sc, hit, ph, ray);
}

t_vec3	rgb_to_sepia(t_vec3 color)
{
	color.x = 0.393 * color.x + 0.769 * color.y + 0.189 * color.y;
	color.y = 0.349 * color.x + 0.686 * color.y + 0.168 * color.y;
	color.z = 0.272 * color.x + 0.534 * color.y + 0.131 * color.y;
	return (color);
}

t_vec3	get_color_w(t_scene *sc, t_ray ray, int sep)
{
	t_hit		hit;
	t_vec3		hc;
	t_vec3		color;
	t_phong		*ph;

	sc->lights = sc->lightsfirst;
	hit = get_hit(sc, ray);
	if (hit.t == INFINITY)
		return (font_color(sc));
	ph = (t_phong *)malloc(sizeof(t_phong));
	hit.phit = add_vecs(ray.o, mult_vec_n(ray.d, hit.t));
	hc = get_hit_color(hit);
	ph->am = mult_vec_n(c_to_vec(sc->al->color), sc->al->ratio);
	ph->di = vector(0, 0, 0);
	ph->sp = vector(0, 0, 0);
	while (sc->lights)
	{
		get_color_loop(sc, hit, &ph, ray);
		sc->lights = sc->lights->next;
	}
	color = add_vecs(mult_vecs(add_vecs(ph->am, ph->di), c_to_vec(hc)), ph->sp);
	if (sep)
		color = rgb_to_sepia(color);
	free(ph);
	return (clamp(color));
}
