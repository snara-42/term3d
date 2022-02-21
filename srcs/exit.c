/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:56 by subaru            #+#    #+#             */
/*   Updated: 2022/02/20 16:57:33 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

void	str_exit(const char *str, int status)
{
	printf("%s\n", str);
	exit(status);
}

void	*or_exit(void *ptr)
{
	if (!ptr || errno != 0)
	{
		free(ptr);
		perror("");
		exit(EXIT_FAILURE);
	}
	return (ptr);
}
