/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:34:37 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/14 12:55:30 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_map(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->asset.w, x
					* game->h, y * game->h);
			else if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->asset.c, x
					* game->h, y * game->h);
			else if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win,
					game->player.asset[0][0][0], x * game->h, y * game->h);
			else if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->asset.e, x
					* game->h, y * game->h);
			x++;
		}
		y++;
	}
}
