/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:44:25 by mfunyu            #+#    #+#             */
/*   Updated: 2022/02/23 18:38:45 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_HOOK_H
# define KEY_HOOK_H

# include "term3d.h"

# define ESC '\x1b'
# define ERASE_LINE "\e[2K"

# define ZOOM_LIMIT 42
# define ZOOM_SPEED 1.414213562
# define ROTATE_SPEED M_PI / 42

void	key_hook(int (*funct_ptr)(), void *param1, void *param2);
int		key_handler(int key, t_vec_array *vecs, t_screen *screen);

#endif /* KEY_HOOK_H */
