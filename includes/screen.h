/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:42:02 by subaru            #+#    #+#             */
/*   Updated: 2022/02/22 12:39:15 by mfunyu           ###   ########.fr       */
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

# ifndef SCREEN_X
#  define SCREEN_X 128
# endif
# ifndef SCREEN_Y
#  define SCREEN_Y 64
# endif

typedef struct s_screen
{
	size_t		size_x;
	size_t		size_y;
	signed char	scr[SCREEN_Y * SCREEN_X];
}	t_screen;

#endif /* SCREEN_H */
