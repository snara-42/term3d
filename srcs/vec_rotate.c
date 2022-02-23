/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:50:09 by subaru            #+#    #+#             */
/*   Updated: 2022/02/23 16:28:29 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "vec.h"

t_vec	vec_rot_x(t_vec v, double angle)
{
	return ((t_vec){
		v.x,
		v.y * cos(angle) - v.z * sin(angle),
		v.y * sin(angle) + v.z * cos(angle),
	});
}

t_vec	vec_rot_y(t_vec v, double angle)
{
	return ((t_vec){
		v.z * sin(angle) + v.x * cos(angle),
		v.y,
		v.z * cos(angle) - v.x * sin(angle),
	});
}

t_vec	vec_rot_z(t_vec v, double angle)
{
	return ((t_vec){
		v.x * cos(angle) - v.y * sin(angle),
		v.x * sin(angle) + v.y * cos(angle),
		v.z
	});
}

static t_func_v	vec_rot(enum e_axis axis)
{
	const t_func_v	fp_rotate[N_AXIS] = {vec_rot_x, vec_rot_y, vec_rot_z};

	return (fp_rotate[axis]);
}

void	vec_rotate(t_vec_array *vecs, double angle, t_e_axis axis)
{
	vec_foreach(vecs, vec_rot(axis), angle);
}
