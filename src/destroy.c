/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:07:49 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/14 16:19:36 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_asset(t_game *game)
{
	destroy_asset_map(game);
	destroy_asset_player(game);
	destroy_asset_animation(game);
}

void	destroy_asset_map(t_game *game)
{
	if (game->asset.c)
		mlx_destroy_image(game->mlx, game->asset.c);
	if (game->asset.e)
		mlx_destroy_image(game->mlx, game->asset.e);
	if (game->asset.f2)
		mlx_destroy_image(game->mlx, game->asset.f2);
	if (game->asset.f)
		mlx_destroy_image(game->mlx, game->asset.f);
	if (game->asset.w)
		mlx_destroy_image(game->mlx, game->asset.w);
}

void	destroy_asset_player(t_game *game)
{
	if (game->player.asset[0][0][0])
		mlx_destroy_image(game->mlx, game->player.asset[0][0][0]);
	if (game->player.asset[0][1][0])
		mlx_destroy_image(game->mlx, game->player.asset[0][1][0]);
	if (game->player.asset[0][2][0])
		mlx_destroy_image(game->mlx, game->player.asset[0][2][0]);
	if (game->player.asset[1][0][0])
		mlx_destroy_image(game->mlx, game->player.asset[1][0][0]);
	if (game->player.asset[1][1][0])
		mlx_destroy_image(game->mlx, game->player.asset[1][1][0]);
	if (game->player.asset[1][2][0])
		mlx_destroy_image(game->mlx, game->player.asset[1][2][0]);
}

void	destroy_asset_animation(t_game *game)
{
	if (game->player.asset[0][0][1])
		mlx_destroy_image(game->mlx, game->player.asset[0][0][1]);
	if (game->player.asset[0][1][1])
		mlx_destroy_image(game->mlx, game->player.asset[0][1][1]);
	if (game->player.asset[0][2][1])
		mlx_destroy_image(game->mlx, game->player.asset[0][2][1]);
	if (game->player.asset[1][0][1])
		mlx_destroy_image(game->mlx, game->player.asset[1][0][1]);
	if (game->player.asset[1][1][1])
		mlx_destroy_image(game->mlx, game->player.asset[1][1][1]);
	if (game->player.asset[1][2][1])
		mlx_destroy_image(game->mlx, game->player.asset[1][2][1]);
}
