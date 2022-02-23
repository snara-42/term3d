/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:56 by subaru            #+#    #+#             */
/*   Updated: 2022/02/24 02:44:51 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "vec.h"
#include "screen.h"

#define CLEAR "\x1b[2H"
#define N_CHARS 8
#define CHARS " .:-~+**###"

static bool	is_in_screen(t_screen *screen, t_vec *vec)
{
	return ((double)screen->size_x / -2 < vec->x * 2
		&& vec->x * 2 < (double)screen->size_x / 2
		&& (double)screen->size_y / -2 < vec->y
		&& vec->y < (double)screen->size_y / 2);
}

/* plot on (x*2, y) so that it looks square */

static void	fill_screen(t_screen *screen, t_vec *vec)
{
	const size_t	x = (screen->size_x / 2.) + vec->x * 2;
	const size_t	y = (screen->size_y / 2.) + vec->y;

	if (is_in_screen(screen, vec)
		&& screen->scr[y * screen->size_x + x] < N_CHARS)
		screen->scr[y * screen->size_x + x]++;
}

void	draw_screen(t_screen *screen)
{
	size_t		x;
	size_t		y;

	printf(CLEAR);
	y = 0;
	while (y < screen->size_y)
	{
		x = 0;
		while (x < screen->size_x)
		{
			printf("%c", CHARS[screen->scr[y * screen->size_x + x]]);
			x++;
		}
		printf("\n");
		y++;
	}
}

void	clear_screen(t_screen *screen)
{
	bzero(screen->scr, screen->size_y * screen->size_x + 1);
}

void	display(t_vec_array *vecs, t_screen *screen)
{
	size_t		i;

	clear_screen(screen);
	i = 0;
	while (i < vecs->len)
	{
		fill_screen(screen, &vecs->ptr[i]);
		i++;
	}
	draw_screen(screen);
}
