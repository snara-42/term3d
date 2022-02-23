/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   term3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:42:02 by subaru            #+#    #+#             */
/*   Updated: 2022/02/23 16:51:23 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TERM3D_H
# define TERM3D_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <strings.h>
# include <errno.h>

typedef struct s_screen		t_screen;
typedef struct s_vec		t_vec;
typedef struct s_vec_array	t_vec_array;

void	str_exit(const char *str, int status);
void	*or_exit(void *ptr);

void	parse_files(t_vec_array *vecs, const char **filename);
void	adjust_zoom_to_screen(t_vec_array *vecs, t_screen *screen);
void	display(t_vec_array *vecs, t_screen *screen);

#endif /* TERM3D_H */
