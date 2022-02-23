/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 12:16:01 by mfunyu            #+#    #+#             */
/*   Updated: 2022/02/22 21:02:32 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"
#include "term3d.h"

static void	set_screen_size(t_screen *screen)
{
	struct winsize	ws;
	int				ret;

	ret = ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws);
	if (ret == -1)
		str_exit(strerror(errno), EXIT_FAILURE);
	screen->size_y = (size_t)ws.ws_row;
	screen->size_x = (size_t)ws.ws_col;
}

void	set_screen(t_screen *screen)
{
	set_screen_size(screen);
	screen->scr = (typeof(screen->scr))or_exit(
			realloc(screen->scr,
				sizeof(*screen->scr) * (screen->size_y * screen->size_x + 1)));
}
