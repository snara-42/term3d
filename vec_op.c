/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_op.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:50:09 by subaru            #+#    #+#             */
/*   Updated: 2022/02/20 23:51:37 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vec.h"

void	vec_print(t_vec v)
{
	printf("%lf,%lf,%lf\n", v.x, v.y, v.z);
}

t_vec	vec_add(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.x + v2.x, v1.y + v2.y, v1.z + v2.z});
}

t_vec	vec_sub(t_vec v1, t_vec v2)
{
	return ((t_vec){v1.x - v2.x, v1.y - v2.y, v1.z - v2.z});
}

t_vec	vec_mul(t_vec v, double m)
{
	return ((t_vec){v.x * m, v.y * m, v.z * m});
}

double	vec_len(t_vec v)
{
	return (sqrt(vec_dot(v, v)));
}
