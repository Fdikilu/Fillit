/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 21:02:04 by fdikilu           #+#    #+#             */
/*   Updated: 2017/02/03 17:56:11 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int test_tetriminos(char *buf, int ret)
{
	int		cpt;

	cpt = 0;
	while (ret--)
	{
		if (buf[ret] == '#')
		{
			cpt = (buf[ret + 1] == '#') ? cpt + 1 : cpt;
			if (ret != 0)
				cpt = (buf[ret - 1] == '#') ? cpt + 1 : cpt;
			if (ret < 20)
				cpt = (buf[ret + 5] == '#') ? cpt + 1 : cpt;
			if (ret >= 5)
				cpt = (buf[ret - 5] == '#') ? cpt + 1 : cpt;
		}
	}
	return (cpt);
}

static int test_buf(char *buf, int ret)
{
	int		cpt1;
	int		cpt2;
	int		cpt3;

	cpt1 = 0;
	cpt2 = 0;
	cpt3 = 0;
	while (ret--)
	{
		if (buf[ret] != '.' && buf[ret] != '#' && buf[ret] != '\n')
			return (0);
		cpt1 = (buf[ret] == '#') ? cpt1 + 1 : cpt1;
		cpt2 = (buf[ret] == '.') ? cpt2 + 1 : cpt2;
		cpt3 = (buf[ret] == '\n') ? cpt3 + 1 : cpt3;
	}
	if (cpt1 != 4 || cpt2 != 12 || cpt3 != 5)
		return (0);
	return (1);
}

int		file_check(char *file)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0);
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		if (!(test_buf(buf, ret)))
				return (0);
		if (test_tetriminos(buf, ret) < 6)
				return (0);
	}
	if (close(fd) == -1)
		return (0);
	return (1);
}
