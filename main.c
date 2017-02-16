/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:48:30 by fdikilu           #+#    #+#             */
/*   Updated: 2017/02/16 16:37:54 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_tab(t_tetri **tab_tetri, int nb_tetri)
{
	while (nb_tetri--)
	{
		ft_lstclr(&tab_tetri[nb_tetri]->point);
		free(tab_tetri[nb_tetri]);
	}
	free(tab_tetri);
}

int			main(int argc, char **argv)
{
	int		tab_arg[3];
	char	*soluce;
	t_tetri **tab_tetri;

	if (argc != 2)
	{
		ft_putstr("usage: fillit source_file\n");
		return (0);
	}
	soluce = NULL;
	tab_tetri = NULL;
	if (!file_check(argv[1]))
	{
		ft_putstr("error\n");
		return (0);
	}
	tab_arg[0] = nb_tetriminos(argv[1]) - 1;
	tab_arg[1] = 2;
	tab_tetri = parsing(argv[1], 0);
	soluce = create_soluce(tab_tetri, tab_arg);
	ft_putstr(soluce);
	free_tab(tab_tetri, tab_arg[0] + 1);
	free(soluce);
	return (0);
}
