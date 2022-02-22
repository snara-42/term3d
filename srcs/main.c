/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:56 by subaru            #+#    #+#             */
/*   Updated: 2022/02/22 18:11:58 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "screen.h"
#include "vec.h"
#include "hook.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int	main(int ac, const char *av[])
{
	static t_vec_array	vecs = {};
	t_screen			screen;

	if (ac < 2)
		str_exit("usage: ./term3d files...", EXIT_FAILURE);
	parse_files(&vecs, &av[1]);
	set_screen(&screen);
	adjust_zoom(&vecs, &screen, 0);
	srand(time(NULL));
	while (1)
	{
		key_hook(&key_handler, &vecs, &screen);
		display(&vecs, &screen);
		vec_rotate(&vecs, M_PI / 42, (t_e_axis)(rand() % N_AXIS));
		usleep(42000);
	}
	return (EXIT_SUCCESS);
}
