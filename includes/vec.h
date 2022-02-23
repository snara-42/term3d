/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:24:24 by subaru            #+#    #+#             */
/*   Updated: 2022/02/23 17:14:12 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_H
# define VEC_H

# include <stdio.h>
# include <math.h>

typedef enum e_axis
{
	AXIS_X = 0,
	AXIS_Y = 1,
	AXIS_Z = 2,
	N_AXIS = 3
}	t_e_axis;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_vec_array
{
	t_vec	*ptr;
	size_t	len;
}	t_vec_array;

typedef double	(*t_func_d)();
typedef t_vec	(*t_func_v)();

void	vec_print(t_vec v);
t_vec	vec_add(t_vec v1, t_vec v2);
t_vec	vec_sub(t_vec v1, t_vec v2);
t_vec	vec_mul(t_vec v, double m);

double	vec_len(t_vec v);
double	vec_dot(t_vec v1, t_vec v2);
t_vec	vec_cross(t_vec v1, t_vec v2);
t_vec	vec_unit(t_vec v);

void	vec_foreach(t_vec_array *vecs, t_func_v f_vec, double arg);
double	vec_max_min(t_vec_array *vecs, t_func_d f_cmp, t_func_d f_vec);

void	vec_rotate(t_vec_array *vecs, double angle, t_e_axis axis);
void	vec_zoom(t_vec_array *vecs, double multiplier);

#endif /* VEC_H */
