/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:28:46 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/08 18:04:48 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player.plyr_x = x;
				game->player.plyr_y = y;
			}
			x++;
		}
		y++;
	}
}

int	move_rigth(t_game *game)
{
	if (game->player.plyr_x + 1 > game->map_x)
		return (0);
	if (game->map[game->player.plyr_y][game->player.plyr_x + 1] == '1')
		return (0);
	game->player.position_x = 0;
	game->player.position_y = 0;
	mlx_put_image_to_window(game->mlx, game->win, game->asset.f2,
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	game->player.plyr_x++;
	usleep(2000000);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.asset[game->player.position_x][game->player.position_y][1],
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	usleep(2000000);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.asset[game->player.position_x][game->player.position_y][0],
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	return (1);
}

int	move_left(t_game *game)
{
	if (game->player.plyr_x - 1 <= 0)
		return (0);
	if (game->map[game->player.plyr_y][game->player.plyr_x - 1] == '1')
		return (0);
	game->player.position_x = 1;
	game->player.position_y = 0;
	mlx_put_image_to_window(game->mlx, game->win, game->asset.f2,
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	game->player.plyr_x--;
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.asset[game->player.position_x][game->player.position_y][1],
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	usleep(2000000);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.asset[game->player.position_x][game->player.position_y][0],
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	return (1);
}
int	move_bottom(t_game *game)
{
	if (game->player.plyr_y + 1 > game->map_y)
		return (0);
	if (game->map[game->player.plyr_y + 1][game->player.plyr_x] == '1')
		return (0);
	game->player.position_y = 1;
	mlx_put_image_to_window(game->mlx, game->win, game->asset.f2,
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	game->player.plyr_y++;
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.asset[game->player.position_x][game->player.position_y][1],
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	usleep(2000000);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.asset[game->player.position_x][game->player.position_y][0],
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	return (1);
}

int	move_top(t_game *game)
{
	if (game->player.plyr_y - 1 <= 0)
		return (0);
	if (game->map[game->player.plyr_y - 1][game->player.plyr_x] == '1')
		return (0);
	game->player.position_y = 2;
	mlx_put_image_to_window(game->mlx, game->win, game->asset.f2,
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	game->player.plyr_y--;
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.asset[game->player.position_x][game->player.position_y][1],
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	usleep(2000000);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.asset[game->player.position_x][game->player.position_y][0],
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	return (1);
}
