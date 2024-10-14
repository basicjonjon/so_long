/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:34:14 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/14 13:05:32 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_nb_collectible(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			if (game->map[y][x] == 'C')
			{
				game->nb_collectible++;
			}
			x++;
		}
		y++;
	}
}
