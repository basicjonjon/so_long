/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:49:33 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/06 16:57:02 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	init_game(t_game *game, char *file)
{
	game->nb_collectible = 0;
	game->nb_exit = 0;
	game->nb_player = 0;
	get_map_size(game, file);
	get_map(game, file);
	get_player_position(game);
	game->verif.map = ft_bidimentionnal_char_cpy(game->map);
	game->verif.collectible = 0;
	game->verif.exit = 0;
	if (verif_validity_map(*game))
		return (1);
	return (0);
}
