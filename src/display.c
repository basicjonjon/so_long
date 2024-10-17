/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:34:37 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/17 11:05:43 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
				display_player(game);
			display_map(game, x, y);
			x++;
		}
		y++;
	}
}

void	display_map(t_game *game, int x, int y)
{
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->asset.w, x
			* game->h, y * game->h);
	else if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->asset.c, x
			* game->h, y * game->h);
	else if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->asset.e, x
			* game->h, y * game->h);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->asset.f2, x
			* game->h, y * game->h);
}

void	display_player(t_game *game)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.asset[game->player.rot_x][game->player.rot_y][1],
		game->player.x * game->h, game->player.y * game->h);
}
