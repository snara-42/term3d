/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfunyu <mfunyu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:00:49 by mfunyu            #+#    #+#             */
/*   Updated: 2022/02/22 18:23:51 by mfunyu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_hook.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <stdbool.h>

static int	getch(void)
{
	struct termios	oldt;
	struct termios	newt;
	int				ch;
	int				oldf;

	tcgetattr(STDIN_FILENO, &oldt);
	newt = oldt;
	newt.c_lflag &= ~(ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &newt);
	oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
	fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);
	ch = getchar();
	tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
	fcntl(STDIN_FILENO, F_SETFL, oldf);
	if (ch != EOF)
		return (ch);
	return (-1);
}

void	key_hook(int (*funct_ptr)(), void *param1, void *param2)
{
	int	key;

	key = getch();
	if (key > 0)
	{
		key = getchar();
		printf(ERASE_LINE);
		funct_ptr(key, param1, param2);
	}
}
