/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 18:07:28 by fdikilu           #+#    #+#             */
/*   Updated: 2017/02/09 14:38:21 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fillit.h"

static int	print_tetri(t_list *point, char *soluce, char lettre, int s_width, int i)
{
	int		str_index;
	t_list	*tmp;

	tmp = point;
	if (!tmp)
		return (1);
	else
	{
		str_index = ((int * )tmp->content)[1] * (s_width + 1) + ((int *)tmp->content)[0] + i;
		if (str_index < ft_strlen(soluce))
		{
			if (soluce[str_index] == '.' && (print_tetri(tmp->next, soluce, lettre, s_width, i)) == 1)
			{
				soluce[str_index] = lettre;
				return (1);
			}
			else
				return (0);
		}
		else
			return (-1);
	}
}

static int	place_tetri(t_tetri *tetriminos, char *soluce, int s_width, int i)
{
	int		print;
	t_list	*tmp;

	if ((tmp = tetriminos->point))
	{
		print = print_tetri(tmp, soluce, tetriminos->lettre, s_width, i);
		if (print == 1)
			return (1);
		else if (print == -1)
			return (0);
		else
			return (place_tetri(tetriminos, soluce, s_width, i + 1));
	}
	else
		return (0);
}

static int	solve(t_tetri **tab_tetri, char *soluce, int nb_tetri, int s_width, int *index)
{
	if (nb_tetri == 0)
		return (place_tetri(tab_tetri[nb_tetri], soluce, s_width, *index));
	else
	{
		*index = *index + 1;
		if (solve(tab_tetri, soluce, nb_tetri - 1, s_width, index))
		{
			*index = 0;
			return (place_tetri(tab_tetri[nb_tetri], soluce, s_width, *index));
		}
		else
			return (0);
	}
}

char		*create_soluce(t_tetri **tab_tetri, int nb_tetri, int s_width)
{
	int		*index;
	int		length;
	char	*soluce;

	length = s_width * s_width + s_width;
	if (!(soluce = (char *)malloc(sizeof(char) * length)))
		return (NULL);
	ft_memset((void *)soluce, 46, length);
	soluce[length] = '\0';
	while (length--)
	{
		if (length % (s_width + 1) == s_width)
			soluce[length] = '\n';
	}
	if (!(index = (int*)malloc(sizeof(int))))
		return(NULL);
	*index = 0;
	if (solve(tab_tetri, soluce, nb_tetri, s_width, index))
		return (soluce);
	else
	{
		free(index);
		free(soluce);
		return (create_soluce(tab_tetri, nb_tetri, s_width + 1));
	}
}
