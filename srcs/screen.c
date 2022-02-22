/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:16:01 by mfunyu            #+#    #+#             */
/*   Updated: 2022/02/22 13:23:12 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"
#include "term3d.h"

void	set_screen(t_screen *screen)
{
	screen->size_y = (size_t)SCREEN_Y;
	screen->size_x = (size_t)SCREEN_X;
	screen->scr = (signed char *)or_exit(
			malloc((screen->size_y * screen->size_x + 1)
				* sizeof(signed char)));
}
