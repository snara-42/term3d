/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:56 by subaru            #+#    #+#             */
/*   Updated: 2022/02/21 23:12:40 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "vec.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int	main(int ac, const char *av[])
{
	static t_vec_array	vecs = {};

	if (ac < 2)
		str_exit("usage: ./term3d files...", EXIT_FAILURE);
	parse_files(&vecs, &av[1]);
	adjust_zoom(&vecs);
	srand(time(NULL));
	while (1)
	{
		display(&vecs);
		vec_rotate(&vecs, M_PI / 42, (t_e_axis)(rand() % N_AXIS));
		usleep(42000);
	}
	return (EXIT_SUCCESS);
}