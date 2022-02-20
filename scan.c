/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:56 by subaru            #+#    #+#             */
/*   Updated: 2022/02/20 17:00:29 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "vec.h"

#define N_FIELD 3

void	scan_file(const char *filename, t_vec_array	*vecs)
{
	t_vec		*next;
	FILE		*ifs;

	errno = 0;
	ifs = or_exit(fopen(filename, "r"));
	while (!feof(ifs))
	{
		vecs->len += 1;
		vecs->ptr = (t_vec *)or_exit(realloc(vecs->ptr, sizeof(t_vec) * vecs->len));
		next = &vecs->ptr[vecs->len - 1];
		if (fscanf(ifs, "%lf,%lf,%lf\n", &next->x, &next->y, &next->z) != N_FIELD
			|| ferror(ifs))
			str_exit("scanf() failed\n", EXIT_FAILURE);
	}
	printf("len %zu,error %d,eof %d\n", vecs->len, ferror(ifs), feof(ifs));
	fclose(ifs);
}
