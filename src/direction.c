/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   direction.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 14:51:44 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/14 16:20:00 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	direction_verification(int keycode, t_game *game)
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

int	direction_change(int keycode, t_game *game)
{
	if (keycode == 65307)
		end_clean_game(game);
	if (direction_verification(keycode, game))
		game->keypress = keycode;
	return (0);
}
