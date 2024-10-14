/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:49:33 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/14 16:19:18 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_game(t_game *game, char *file)
{
	int	fd;

	init_game_value(game);
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (1);
	if (get_map_size(game, fd))
		return (1);
	fd = open(file, O_RDONLY);
	if (get_map(game, fd))
		return (1);
	get_player_position(game);
	game->verif.map = ft_bidimentionnal_char_cpy(game->map);
	if (error_map(*game))
		return (1);
	get_exit(game);
	get_nb_collectible(game);
	init_asset_player(game);
	init_asset_map(game);
	if (error_asset(game))
		return (1);
	return (0);
}

void	init_game_value(t_game *game)
{
	game->h = 56;
	game->nb_collectible = 0;
	game->nb_exit = 0;
	game->nb_player = 0;
	game->keypress = 0;
	game->player.rot_x = 0;
	game->player.rot_y = 0;
	game->exit.x = 0;
	game->exit.y = 0;
	game->verif.collectible = 0;
	game->collected = 0;
	game->verif.exit = 0;
}
