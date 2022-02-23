/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:50:09 by subaru            #+#    #+#             */
/*   Updated: 2022/02/23 21:56:43 by subaru           ###   ########.fr       */
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

t_vec	vec_rot_axes(t_vec v, t_vec angle)
{
	if (angle.x)
		v = vec_rot_x(v, angle.x);
	if (angle.y)
		v = vec_rot_y(v, angle.y);
	if (angle.z)
		v = vec_rot_z(v, angle.z);
	return (v);
}

void	vec_rotate(t_vec_array *vecs, t_vec angle)
{
	vec_foreach_vec(vecs, vec_rot_axes, angle);
}
