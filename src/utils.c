/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:26:46 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/07 13:41:42 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_tablen(char **tab)
{
	int	y;

	y = 0;
	while (tab[y])
		y++;
	return (y);
}

char	**ft_bidimentionnal_char_cpy(char **tab)
{
	char	**res;
	int		y_size;
	int		y;
	int		x_size;
	int		x;

	y_size = ft_tablen(tab);
	y = 0;
	x_size = ft_strlen(tab[0]);
	res = malloc(sizeof(char **) * (y_size + 1));
	while (tab[y])
	{
		x = 0;
		res[y] = malloc(sizeof(char) * (x_size + 1));
		while (tab[y][x])
		{
			res[y][x] = tab[y][x];
			x++;
		}
		res[y][x] = '\0';
		y++;
	}
	res[y] = NULL;
	return (res);
}
