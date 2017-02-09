/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdikilu <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/23 20:11:28 by fdikilu           #+#    #+#             */
/*   Updated: 2016/12/02 18:42:26 by fdikilu          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	str = (char *)malloc(sizeof(*str) * (size + 1));
	if (str != NULL)
		ft_bzero((void *)str, size + 1);
	return (str);
}
