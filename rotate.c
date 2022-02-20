/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:56 by subaru            #+#    #+#             */
/*   Updated: 2022/02/21 01:01:28 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "vec.h"

void	rotate(t_vec_array *vecs, double angle, t_e_axis axis)
{
	size_t	i;
	t_vec	*v;

	i = 0;
	while (i < vecs->len)
	{
		v = &vecs->ptr[i];
		*v = vec_rot(*v, angle, axis);
		i++;
	}
}
