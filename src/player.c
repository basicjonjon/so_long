/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:28:46 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/07 17:55:06 by jle-doua         ###   ########.fr       */
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
	else
		mlx_put_image_to_window(game->mlx, game->win, game->asset.f2,
			game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	game->player.plyr_x++;
	mlx_put_image_to_window(game->mlx, game->win, game->asset.player[0],
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	return (1);
}

int	move_left(t_game *game)
{
	if (game->player.plyr_x - 1 <= 0)
		return (0);
	if (game->map[game->player.plyr_y][game->player.plyr_x - 1] == '1')
		return (0);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->asset.f2,
			game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	game->player.plyr_x--;
	mlx_put_image_to_window(game->mlx, game->win, game->asset.player[0],
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	return (1);
}
int	move_bottom(t_game *game)
{
	if (game->player.plyr_y + 1 > game->map_y)
		return (0);
	if (game->map[game->player.plyr_y + 1][game->player.plyr_x] == '1')
		return (0);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->asset.f2,
			game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	game->player.plyr_y++;
	mlx_put_image_to_window(game->mlx, game->win, game->asset.player[0],
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	return (1);
}

int	move_top(t_game *game)
{
	if (game->player.plyr_y - 1 <= 0)
		return (0);
	if (game->map[game->player.plyr_y - 1][game->player.plyr_x] == '1')
		return (0);
	else
		mlx_put_image_to_window(game->mlx, game->win, game->asset.f2,
			game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	game->player.plyr_y--;
	mlx_put_image_to_window(game->mlx, game->win, game->asset.player[0],
		game->player.plyr_x * game->h, game->player.plyr_y * game->h);
	return (1);
}

// int	move_top(t_maps *map)
// {
// 	if (map->plyr.y - 1 < 0)
// 		return (0);
// 	if (map->map[map->plyr.y - 1][map->plyr.x] == '1')
// 		return (0);
// 	// if (map->map[map->plyr.y][map->plyr.x] == 'E')
// 	// 	ft_put_exit(map->info, map->asset, map->plyr.x, map->plyr.y);
// 	else
// 		put_floor(map->plyr.x, map->plyr.y, *map);
// 	map->plyr.y--;
// 	display_player(map);
// 	return (1);
// }

// int	move_bottom(t_maps *map)
// {
// 	if (map->plyr.y + 1 > map->y)
// 		return (0);
// 	if (map->map[map->plyr.y + 1][map->plyr.x] == '1')
// 		return (0);
// 	else
// 		put_floor(map->plyr.x, map->plyr.y, *map);
// 	map->plyr.y++;
// 	display_player(map);
// 	return (1);
// }

int	key_hook(int keycode, t_game *game)
{
	printf("%i\n", keycode);
	if (keycode == 100 || keycode == 65363)
	{
		game->keypress = 100;

		move_rigth(game);
	}

	// if (keycode == 97 || keycode == 65361)
	// 	move_left(map);
	// if (keycode == 119 || keycode == 65362)
	// 	move_top(map);
	// if (keycode == 115 || keycode == 65364)
	// 	move_bottom(map);
	// if (map->map[map->plyr.y][map->plyr.x] == 'C')
	// {
	// 	set_collected(map->plyr.x, map->plyr.y, map);
	// 	// if (map->nb_collect == 0)
	// 	// {
	// 	// 	ft_put_exit(map->info, map->asset, map->info->exit_x,
	// 	// 		map->info->exit_y);
	// 	// }
	// }
	return (0);
}