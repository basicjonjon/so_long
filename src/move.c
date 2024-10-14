/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:51:44 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/14 13:16:37 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	verif_direction(int keycode, t_game *game)
{
	if (keycode == 100 && game->map[game->player.y][game->player.x + 1] != '1')
		return (1);
	if (keycode == 97 && game->map[game->player.y][game->player.x - 1] != '1')
		return (1);
	if (keycode == 119 && game->map[game->player.y - 1][game->player.x] != '1')
		return (1);
	if (keycode == 115 && game->map[game->player.y + 1][game->player.x] != '1')
		return (1);
	return (0);
}

int	get_change_direction(int keycode, t_game *game)
{
	if (keycode == 65307)
		clean_game(game);
	if (verif_direction(keycode, game))
		game->keypress = keycode;
	return (0);
}

int	move_loop(t_game *game)
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
		move_rigth(game);
	if (game->keypress == 97 || game->keypress == 65361)
		move_left(game);
	if (game->keypress == 119 || game->keypress == 65362)
		move_top(game);
	if (game->keypress == 115 || game->keypress == 65364)
		move_bottom(game);
	printf("\033[H\033[J");
	printf("collected %i | collectible %i\n", game->collected,
		game->nb_collectible);
	exit_game(game);
	return (0);
}
