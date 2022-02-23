/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:43:57 by mfunyu            #+#    #+#             */
/*   Updated: 2022/02/22 18:21:52 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hook.h"
#include "term3d.h"
#include <stdlib.h>

static void	event_zoom(t_vec_array *vecs, t_screen *screen, int zoom)
{
	static int	X;

	X = X + zoom;
	if (X > ZOOM_LIMIT)
		X = ZOOM_LIMIT;
	if (X < 0)
		X = 0;
	adjust_zoom(vecs, screen, X * ZOOM_SPEED);
}

int	key_handler(int key, t_vec_array *vecs, t_screen *screen)
{
	if (key == 'q' || key == ESC)
	{
		printf("term3d exitting ...\n");
		exit(EXIT_SUCCESS);
	}
	if (key == '+' || key == '-')
	{
		event_zoom(vecs, screen, 44 - key);
	}
	return (0);
}