/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:56 by subaru            #+#    #+#             */
/*   Updated: 2022/02/20 17:03:02 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "vec.h"
#include <stdio.h>
#include <stdlib.h>

#define N_FIELD 3

int	main(int ac, char *av[])
{
	static t_vec_array	vecs = {};

	if (ac < 2)
		exit(1);
	scan_file(av[1], &vecs);
	display(&vecs);
	return (EXIT_SUCCESS);
}
