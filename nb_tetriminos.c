/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nb_tetriminos.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/04 18:46:33 by fdikilu           #+#    #+#             */
/*   Updated: 2017/02/04 18:47:02 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		nb_tetriminos(char *file)
{
	int		fd;
	int		ret;
	int		nb_tetri;
	char	buf[BUF_SIZE + 1];

	nb_tetri = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		nb_tetri++;
	}
	if (close(fd) == -1)
		return (0);
	return (nb_tetri);
}
