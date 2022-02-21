/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_iter.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:56 by subaru            #+#    #+#             */
/*   Updated: 2022/02/21 04:09:03 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

typedef double	(*t_func_d)();
typedef t_vec	(*t_func_v)();

double	vec_max_min(t_vec_array *vecs, t_func_d f_cmp, t_func_d f_vec)
{
	size_t	i;
	t_vec	*v;
	double	max;

	max = f_vec(vecs->ptr[0]);
	i = 0;
	while (i < vecs->len)
	{
		v = &vecs->ptr[i];
		max = f_cmp(max, f_vec(*v));
		i++;
	}
	return (max);
}

void	vec_foreach(t_vec_array *vecs, t_func_v f_vec, double arg)
{
	size_t			i;
	t_vec			*v;

	i = 0;
	while (i < vecs->len)
	{
		v = &vecs->ptr[i];
		*v = f_vec(*v, arg);
		i++;
	}
}
