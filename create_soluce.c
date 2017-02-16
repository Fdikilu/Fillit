/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_soluce.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:14:49 by fdikilu           #+#    #+#             */
/*   Updated: 2017/02/16 16:23:04 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	init_soluce(char *soluce, int s_width)
{
	int		length;

	length = s_width * s_width + s_width;
	ft_memset((void *)soluce, 46, length);
	soluce[s_width * s_width + s_width] = '\0';
	while (length--)
	{
		if (length % (s_width + 1) == s_width)
			soluce[length] = '\n';
	}
}

char		*create_soluce(t_tetri **tab_tetri, int *tab_arg)
{
	char	*soluce;

	if (!(soluce = (char *)malloc(sizeof(char) *
		(tab_arg[1] * tab_arg[1] + tab_arg[1]) + 1)))
		return (NULL);
	init_soluce(soluce, tab_arg[1]);
	if (solve(tab_tetri, soluce, 0, tab_arg))
	{
		return (soluce);
	}
	else
	{
		free(soluce);
		tab_arg[1] += 1;
		return (create_soluce(tab_tetri, tab_arg));
	}
}
