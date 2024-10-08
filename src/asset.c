/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:45:12 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/08 17:52:30 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_asset_map(t_game *game)
{
	game->asset.w = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm",
			&game->h, &game->h);
	game->asset.f = mlx_xpm_file_to_image(game->mlx, "./assets/floor.xpm",
			&game->h, &game->h);
	game->asset.f2 = mlx_xpm_file_to_image(game->mlx, "./assets/floor_nc.xpm",
			&game->h, &game->h);
	game->asset.c = mlx_xpm_file_to_image(game->mlx, "./assets/collect.xpm",
			&game->h, &game->h);
}

void	init_asset_player(t_game *game)
{
	game->player.asset[0][0][0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/frontr.xpm", &game->h, &game->h);
	game->player.asset[0][1][0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/frontbr.xpm", &game->h, &game->h);
	game->player.asset[0][2][0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/fronttr.xpm", &game->h, &game->h);
	game->player.asset[1][0][0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/frontl.xpm", &game->h, &game->h);
	game->player.asset[1][1][0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/frontbl.xpm", &game->h, &game->h);
	game->player.asset[1][2][0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/fronttl.xpm", &game->h, &game->h);

	game->player.asset[0][0][1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/front1r.xpm", &game->h, &game->h);
	game->player.asset[0][1][1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/front1br.xpm", &game->h, &game->h);
	game->player.asset[0][2][1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/front1tr.xpm", &game->h, &game->h);
	game->player.asset[1][0][1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/front1l.xpm", &game->h, &game->h);
	game->player.asset[1][1][1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/front1bl.xpm", &game->h, &game->h);
	game->player.asset[1][2][1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/front1tl.xpm", &game->h, &game->h);
}
