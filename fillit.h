/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/18 16:27:55 by fdikilu           #+#    #+#             */
/*   Updated: 2017/02/16 16:22:28 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include "libft/libft.h"

# define BUF_SIZE 21

typedef struct		s_tetri
{
	char			lettre;
	struct s_list	*point;
}					t_tetri;

int					file_check(char *file);
int					nb_tetriminos(char *file);
t_tetri				**parsing(char *file, int i);
int					solve(t_tetri **tab_tetri, char *soluce, \
	int index, int *tab_arg);
char				*create_soluce(t_tetri **tab_tetri, int *tab_arg);
int					main(int argc, char **argv);

#endif
