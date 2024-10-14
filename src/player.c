/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/06 14:28:46 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/14 16:16:05 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	player_loop(t_game *game)
{
	static int	counter = 0;
	int			speed_limit;

	speed_limit = 28000;
	if (counter == 14000)
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.asset[game->player.rot_x][game->player.rot_y][0],
			game->player.x * game->h, game->player.y * game->h);
	if (counter < speed_limit)
		return (counter++, 0);
	counter = 0;
	if (game->keypress == 100 || game->keypress == 65363)
		player_rigth(game);
	if (game->keypress == 97 || game->keypress == 65361)
		player_left(game);
	if (game->keypress == 119 || game->keypress == 65362)
		player_top(game);
	if (game->keypress == 115 || game->keypress == 65364)
		player_bottom(game);
	printf("\033[H\033[J");
	printf("collected %i | collectible %i\n", game->collected,
		game->nb_collectible);
	end_game(game);
	return (0);
}

int	player_rigth(t_game *game)
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

int	player_left(t_game *game)
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

int	player_bottom(t_game *game)
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

int	player_top(t_game *game)
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
