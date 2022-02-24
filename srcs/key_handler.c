/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:43:57 by mfunyu            #+#    #+#             */
/*   Updated: 2022/02/24 23:54:44 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"
#include "key_hook.h"
#include "vec.h"

static void	event_zoom(t_vec_array *vecs, t_screen *screen, int zoom)
{
	static int	zoom_level = 0;

	(void)screen;
	zoom_level += zoom;
	if (zoom_level > ZOOM_LIMIT)
		zoom_level = ZOOM_LIMIT;
	else if (zoom_level < -ZOOM_LIMIT)
		zoom_level = -ZOOM_LIMIT;
	else
		vec_zoom(vecs, pow(ZOOM_SPEED, zoom));
}

static void	event_move(t_vec_array *vecs, t_screen *screen, int key)
{
	const double	speed = fmin(screen->size_x, screen->size_y) * MOVE_SPEED;

	if (key == 'l')
		vec_foreach_vec(vecs, vec_add, (t_vec){speed, 0, 0});
	if (key == 'h')
		vec_foreach_vec(vecs, vec_add, (t_vec){-speed, 0, 0});
	if (key == 'j')
		vec_foreach_vec(vecs, vec_add, (t_vec){0, speed, 0});
	if (key == 'k')
		vec_foreach_vec(vecs, vec_add, (t_vec){0, -speed, 0});
	if (key == 'u')
		vec_foreach_vec(vecs, vec_add, (t_vec){0, 0, speed});
	if (key == 'i')
		vec_foreach_vec(vecs, vec_add, (t_vec){0, 0, -speed});
}

void	vec_keep_rotate(t_vec_array *vecs, t_e_axis axis, double direction)
{
	static t_vec	angle = {0, 0, ROTATE_SPEED};

	if (AXIS_X == axis)
		angle = (t_vec){direction * ROTATE_SPEED, 0, 0};
	else if (AXIS_Y == axis)
		angle = (t_vec){0, direction * ROTATE_SPEED, 0};
	else if (AXIS_Z == axis)
		angle = (t_vec){0, 0, direction * ROTATE_SPEED};
	else
		vec_rotate(vecs, (t_vec)
		{angle.x * direction, angle.y * direction, angle.z * direction});
}

int	key_handler(int key, t_vec_array *vecs, t_screen *screen)
{
	if (key == 'q' || key == ESC)
		str_exit("term3d exiting ...\n", EXIT_SUCCESS);
	if (strchr("+-", key))
		event_zoom(vecs, screen, 44 - key);
	if (strchr("hljkui", key))
		event_move(vecs, screen, key);
	if (strchr("xyz", key))
		vec_keep_rotate(vecs, (t_e_axis)(key - 'x'), 1);
	if (strchr("XYZ", key))
		vec_keep_rotate(vecs, (t_e_axis)(key - 'X'), -1);
	if (strchr(" .", key))
		vec_keep_rotate(vecs, AXIS_Z, 0);
	return (0);
}
