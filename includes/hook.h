/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:44:25 by mfunyu            #+#    #+#             */
/*   Updated: 2022/02/22 18:11:19 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
#define HOOK_H

# include "term3d.h"

# define ESC 27
# define ERASE_LINE "\e[2K"

# define ZOOM_LIMIT 42
# define ZOOM_SPEED 0.1

void	key_hook(int (*funct_ptr)(), void *param1, void *param2);
int		key_handler(int key, t_vec_array *vecs, t_screen *screen);

#endif /* HOOK_H */