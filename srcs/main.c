/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:10:50 by subaru            #+#    #+#             */
/*   Updated: 2022/02/23 23:05:04 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "screen.h"
#include "vec.h"
#include "key_hook.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int	main(int ac, const char *av[])
{
	static t_vec_array	vecs;
	static t_screen		screen;

	if (ac < 2)
		str_exit("usage: ./term3d files...", EXIT_FAILURE);
	parse_files(&vecs, &av[1]);
	set_screen(&screen);
	adjust_zoom_to_screen(&vecs, &screen);
	while (1)
	{
		display(&vecs, &screen);
		key_hook(&key_handler, &vecs, &screen);
		vec_keep_rotate(&vecs, N_AXIS, 1);
		usleep(42000);
	}
	return (EXIT_SUCCESS);
}
