/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:48:30 by fdikilu           #+#    #+#             */
/*   Updated: 2017/02/04 18:56:47 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int			main(int argc, char **argv)
{
	int		nb_tetri;
	char	*soluce;
	t_tetri **tab_tetri;

	if (argc != 2)
	{
		ft_putstr("usage");
		return (0);
	}
	tab_tetri = NULL;
	if (!file_check(argv[1]))
	{
		ft_putstr("error\n");
		return (0);
	}
	nb_tetri = nb_tetriminos(argv[1]);
	tab_tetri = parsing(argv[1]);
	soluce = create_soluce(tab_tetri, nb_tetri - 1, 2);
	ft_putstr(soluce);
	return (0);
}
