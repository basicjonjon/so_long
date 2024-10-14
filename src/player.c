/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:28:46 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/14 13:15:56 by jle-doua         ###   ########.fr       */
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
				game->player.x = x;
				game->player.y = y;
			}
			x++;
		}
		y++;
	}
}

int	move_rigth(t_game *game)
{
	if (game->player.x + 1 > game->map_x)
		return (0);
	if (game->map[game->player.y][game->player.x + 1] == '1')
		return (0);
	game->player.rot_x = 0;
	game->player.rot_y = 0;
	if (game->map[game->player.y][game->player.x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->asset.e,
			game->player.x * game->h, game->player.y * game->h);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->asset.f2,
			game->player.x * game->h, game->player.y * game->h);
	game->player.x++;
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.asset[game->player.rot_x][game->player.rot_y][1],
		game->player.x * game->h, game->player.y * game->h);
	printf("%i %i %c\n", game->player.x, game->player.y,
		game->map[game->player.y][game->player.x]);
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->collected++;
		game->map[game->player.y][game->player.x] = '0';
	}
	return (1);
}

int	move_left(t_game *game)
{
	if (game->player.x - 1 <= 0)
		return (0);
	if (game->map[game->player.y][game->player.x - 1] == '1')
		return (0);
	game->player.rot_x = 1;
	game->player.rot_y = 0;
	if (game->map[game->player.y][game->player.x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->asset.e,
			game->player.x * game->h, game->player.y * game->h);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->asset.f2,
			game->player.x * game->h, game->player.y * game->h);
	game->player.x--;
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.asset[game->player.rot_x][game->player.rot_y][1],
		game->player.x * game->h, game->player.y * game->h);
	printf("%i %i %c\n", game->player.x, game->player.y,
		game->map[game->player.y][game->player.x]);
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->collected++;
		game->map[game->player.y][game->player.x] = '0';
	}
	return (1);
}

int	move_bottom(t_game *game)
{
	if (game->player.y + 1 > game->map_y)
		return (0);
	if (game->map[game->player.y + 1][game->player.x] == '1')
		return (0);
	game->player.rot_y = 1;
	if (game->map[game->player.y][game->player.x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->asset.e,
			game->player.x * game->h, game->player.y * game->h);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->asset.f2,
			game->player.x * game->h, game->player.y * game->h);
	game->player.y++;
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.asset[game->player.rot_x][game->player.rot_y][1],
		game->player.x * game->h, game->player.y * game->h);
	printf("%i %i %c\n", game->player.x, game->player.y,
		game->map[game->player.y][game->player.x]);
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->collected++;
		game->map[game->player.y][game->player.x] = '0';
	}
	return (1);
}

int	move_top(t_game *game)
{
	if (game->player.y - 1 <= 0)
		return (0);
	if (game->map[game->player.y - 1][game->player.x] == '1')
		return (0);
	game->player.rot_y = 2;
	if (game->map[game->player.y][game->player.x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->asset.e,
			game->player.x * game->h, game->player.y * game->h);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->asset.f2,
			game->player.x * game->h, game->player.y * game->h);
	game->player.y--;
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.asset[game->player.rot_x][game->player.rot_y][1],
		game->player.x * game->h, game->player.y * game->h);
	if (game->map[game->player.y][game->player.x] == 'C')
	{
		game->collected++;
		game->map[game->player.y][game->player.x] = '0';
	}
	return (1);
}
