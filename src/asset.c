/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:45:12 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/07 16:45:24 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_asset(t_game *game)
{
	game->asset.w = mlx_xpm_file_to_image(game->mlx, "./assets/wall.xpm",
			&game->h, &game->h);
	game->asset.f = mlx_xpm_file_to_image(game->mlx, "./assets/floor.xpm",
			&game->h, &game->h);
	game->asset.f2 = mlx_xpm_file_to_image(game->mlx, "./assets/floor_nc.xpm",
			&game->h, &game->h);
	game->asset.c = mlx_xpm_file_to_image(game->mlx, "./assets/collect.xpm",
			&game->h, &game->h);
	game->asset.player[0] = mlx_xpm_file_to_image(game->mlx,
			"./assets/front.xpm", &game->h, &game->h);
	game->asset.player[1] = mlx_xpm_file_to_image(game->mlx,
			"./assets/front.xpm", &game->h, &game->h);
}