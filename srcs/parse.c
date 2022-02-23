/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: subaru <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:40:56 by subaru            #+#    #+#             */
/*   Updated: 2022/02/23 18:25:40 by subaru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "term3d.h"
#include "vec.h"

#define N_FIELD 3

static void	expand_alloc(t_vec_array *vecs, ssize_t size)
{
	vecs->len += size;
	if (vecs->len < 0)
		vecs->len = 0;
	vecs->ptr = (t_vec *)or_exit(
			realloc(vecs->ptr, sizeof(*vecs->ptr) * vecs->len));
}

void	parse_file(t_vec_array *vecs, const char *filename)
{
	t_vec		*next;
	FILE		*ifs;

	errno = 0;
	ifs = or_exit(fopen(filename, "r"));
	while (!feof(ifs))
	{
		expand_alloc(vecs, 1);
		next = &vecs->ptr[vecs->len - 1];
		if (fscanf(ifs, "%lf,%lf,%lf\n", &next->x, &next->y, &next->z)
			!= N_FIELD || ferror(ifs))
			str_exit("file format error\n", EXIT_FAILURE);
	}
	fclose(ifs);
}

void	parse_files(t_vec_array *vecs, const char **filenames)
{
	size_t	i;

	i = 0;
	while (filenames[i])
	{
		parse_file(vecs, filenames[i]);
		i++;
	}
}
