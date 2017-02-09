/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:53:17 by fdikilu           #+#    #+#             */
/*   Updated: 2017/02/04 20:09:29 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

static t_tetri	*stock(char *buf, int ret)
{
	int		tab[2];
	t_tetri	*tmp;
	t_tetri	*tetriminos;

	tmp = NULL;
	tetriminos = NULL;
	if (!(tetriminos = (t_tetri *)malloc(sizeof(*tetriminos))))
		return (NULL);
	tmp = tetriminos;
	while (ret--)
	{
		if (buf[ret] == '#')
		{
			tab[0] = ret % 5;
			tab[1] = ret / 5;
			ft_lstadd(&tmp->point, ft_lstnew((int *)&tab, sizeof(tab)));
		}
	}
	return (tetriminos);
}

static void	init_tetri(t_tetri *tetriminos)
{
	int		i;
	int		x;
	int		y;
	t_list	*tmp;

	i = 0;
	x = 4;
	y = 4;
	tmp = tetriminos->point;
	while (i < 4)
	{
		x = (((int *)tmp->content)[0] < x) ? ((int *)tmp->content)[0] : x;
		y = (((int *)tmp->content)[1] < y) ? ((int *)tmp->content)[1] : y;
		tmp = tmp->next;
		i++;
	}
	tmp = tetriminos->point;
	i = 0;
	while (i < 4)
	{
		((int *)tmp->content)[0] = ((int *)tmp->content)[0] - x;
		((int *)tmp->content)[1] = ((int *)tmp->content)[1] - y;
		tmp = tmp->next;
		i++;
	}
}

t_tetri			**parsing(char *file)
{
	int		i;
	char	c;
	int		fd;
	int		ret;
	char	buf[BUF_SIZE + 1];
	t_tetri	**tab_tetri;

	if(!(tab_tetri = malloc(sizeof(t_tetri *) * nb_tetriminos(file))))
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	i = 0;
	c = 'A';
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		tab_tetri[i] = stock(buf, ret);
		tab_tetri[i]->lettre = c;
		init_tetri(tab_tetri[i]);
		c++;
		i++;
	}
	if (close(fd) == -1)
		return (NULL);
	return (tab_tetri);
}/*

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	int nb_tetri = nb_tetriminos(argv[1]);
	t_tetri **tab_tetri = parsing(argv[1]);

	while (i < nb_tetri)
	{
		printf("%c\n", tab_tetri[i]->lettre);
		while (j < 4)
		{
			printf("|%d :", ((int *)tab_tetri[i]->point->content)[0]);
			printf(" %d|\n", ((int *)tab_tetri[i]->point->content)[1]);
			tab_tetri[i]->point = tab_tetri[i]->point->next;
			j++;
		}
		j = 0;
		i++;
	}
}*/
