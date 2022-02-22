/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:43:57 by mfunyu            #+#    #+#             */
/*   Updated: 2022/02/22 18:09:07 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "term3d.h"
#include <stdlib.h>

int	key_handler(int key, t_vec_array *vecs, t_screen *screen)
{
	if (key == 'q' || key == ESC)
	{
		printf("term3d exitting ...\n");
		exit(EXIT_SUCCESS);
	}
	return (0);
}
