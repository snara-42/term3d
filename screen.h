/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:42:02 by subaru            #+#    #+#             */
/*   Updated: 2022/02/21 02:54:21 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCREEN_H
# define SCREEN_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <strings.h>
# include <errno.h>

# define SCREEN_X 128
# define SCREEN_Y 64

typedef struct s_screen
{
	size_t		size_x;
	size_t		size_y;
	signed char	scr[SCREEN_Y][SCREEN_X];
}	t_screen;

#endif /* SCREEN_H */
