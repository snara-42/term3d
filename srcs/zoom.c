/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:56 by subaru            #+#    #+#             */
/*   Updated: 2022/02/22 13:32:45 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"
#include "vec.h"

void	adjust_zoom(t_vec_array *vecs, t_screen *screen)
{
	const double	maxlen = vec_max_min(vecs, fmax, vec_len);
	const double	multiplier =
		fmin(screen->size_x / 2., screen->size_y / 2.) / maxlen;

	vec_foreach(vecs, vec_mul, multiplier);
}
