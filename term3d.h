/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:42:02 by subaru            #+#    #+#             */
/*   Updated: 2022/02/20 17:04:41 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM3D_H
# define TERM3D_H

#include "vec.h"
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <strings.h>
# include <errno.h>

# define SCREEN_X 64
# define SCREEN_Y 32

typedef struct s_screen
{
	size_t		size_x;
	size_t		size_y;
	signed char	scr[SCREEN_Y][SCREEN_X];
}	t_screen;

typedef struct s_vec_array	t_vec_array;

void	str_exit(const char *str, int status);
void	*or_exit(void *ptr);

void	scan_file(const char *filename, t_vec_array	*vecs);
void	display(t_vec_array *vecs);

#endif /* TERM3D_H */
