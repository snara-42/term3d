/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:56 by subaru            #+#    #+#             */
/*   Updated: 2022/02/23 18:11:54 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"
#include "vec.h"

void	vec_zoom(t_vec_array *vecs, double multiplier)
{
	if (isfinite(multiplier))
		vec_foreach(vecs, vec_mul, multiplier);
}

/* adjust to min(width/2, height) */
void	adjust_zoom_to_screen(t_vec_array *vecs, t_screen *screen)
{
	const double	maxlen = vec_max_min(vecs, fmax, vec_len);
	const double	multiplier =
		fmin(screen->size_x / 4., screen->size_y / 2.) / maxlen;

	vec_zoom(vecs, multiplier);
}
