/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfun       yu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:56 by subaru            #+#    #+#             */
/*   Updated: 2022/02/22 18:02:02 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"
#include "vec.h"

void	adjust_zoom(t_vec_array *vecs, t_screen *screen, int X)
{
	const double	maxlen = vec_max_min(vecs, fmax, vec_len);
	const double	multiplier =
		fmin(screen->size_x / 2., screen->size_y / 2.) / maxlen * ++X;

	vec_foreach(vecs, vec_mul, multiplier);
}
