/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:26:46 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/17 16:05:20 by jle-doua         ###   ########.fr       */
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

char	**ft_bidimentionnal_char_cpy(char **tab, int x_size, int y_size)
{
	char	**res;
	int		y;
	int		x;

	y = 0;
	res = malloc(sizeof(char *) * (y_size + 1));
	if (!res)
		return (NULL);
	while (y < y_size && tab[y])
	{
		x = 0;
		res[y] = malloc(sizeof(char) * (x_size + 1));
		if (!res[y])
			return (ft_free_bidimentionnal((void **)res), NULL);
		while (x < x_size && tab[y][x])
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

int	verif_extention_file(char *s, char *ext)
{
	int	ext_size;
	int	s_size;
	int	i;

	i = 0;
	if (!s || !ext)
		return (1);
	ext_size = ft_strlen(ext);
	s_size = ft_strlen(s);
	while (i < ext_size)
	{
		if (s[s_size - i] != ext[ext_size - i])
			return (1);
		i++;
	}
	return (0);
}

int	verif_unauthorized_letter(t_game *game)
{
	int	y;
	int	x;
	int	check;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			check = game->map[y][x];
			if (check != '1' && check != '0' && check != 'P' && check != 'C'
				&& check != 'E' && check != '\n')
				return (1);
			x++;
		}
		y++;
	}
	return (0);
}
