/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:56 by subaru            #+#    #+#             */
/*   Updated: 2022/02/20 16:59:08 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "vec.h"

bool	is_in_screen(t_screen *screen, t_vec *vec)
{
	return ((double)screen->size_x / -2 < vec->x
		&& vec->x < (double)screen->size_x / 2
		&& (double)screen->size_y / -2 < vec->y
		&& vec->y < (double)screen->size_y / 2);
}

void	fill_screen(t_screen *screen, t_vec *vec)
{
	const size_t	x = (double)(screen->size_x / 2) + vec->x;
	const size_t	y = (double)(screen->size_y / 2) + vec->y;

	if (is_in_screen(screen, vec))
		screen->scr[y][x]++;
}

void	draw_screen(t_screen *screen)
{
	size_t		x;
	size_t		y;

	printf("\x1b[2J");
	y = 0;
	while (y < screen->size_y)
	{
		x = 0;
		while (x < screen->size_x)
		{
			printf("%c", ' ' + screen->scr[y][x]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	display(t_vec_array *vecs)
{
	size_t		i;
	t_screen	screen;

	screen = (t_screen){SCREEN_X, SCREEN_Y, {}};
	i = 0;
	while (i < vecs->len)
	{
		fill_screen(&screen, &vecs->ptr[i]);
		i++;
	}
	draw_screen(&screen);
}
