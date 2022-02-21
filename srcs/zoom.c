/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:56 by subaru            #+#    #+#             */
/*   Updated: 2022/02/21 04:20:13 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"
#include "vec.h"

void	adjust_zoom(t_vec_array *vecs)
{
	const double	maxlen = vec_max_min(vecs, fmax, vec_len);
	const double	multiplier = fmin(SCREEN_X / 2., SCREEN_Y / 2.) / maxlen;

	vec_foreach(vecs, vec_mul, multiplier);
}
