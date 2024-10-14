/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:07:37 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/14 13:12:00 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	destroy_asset(t_game *game)
{
	mlx_destroy_image(game->mlx, game->asset.c);
	mlx_destroy_image(game->mlx, game->asset.e);
	mlx_destroy_image(game->mlx, game->asset.f2);
	mlx_destroy_image(game->mlx, game->asset.f);
	mlx_destroy_image(game->mlx, game->asset.w);
	mlx_destroy_image(game->mlx, game->player.asset[0][0][0]);
	mlx_destroy_image(game->mlx, game->player.asset[0][1][0]);
	mlx_destroy_image(game->mlx, game->player.asset[0][2][0]);
	mlx_destroy_image(game->mlx, game->player.asset[1][0][0]);
	mlx_destroy_image(game->mlx, game->player.asset[1][1][0]);
	mlx_destroy_image(game->mlx, game->player.asset[1][2][0]);
	mlx_destroy_image(game->mlx, game->player.asset[0][0][1]);
	mlx_destroy_image(game->mlx, game->player.asset[0][1][1]);
	mlx_destroy_image(game->mlx, game->player.asset[0][2][1]);
	mlx_destroy_image(game->mlx, game->player.asset[1][0][1]);
	mlx_destroy_image(game->mlx, game->player.asset[1][1][1]);
	mlx_destroy_image(game->mlx, game->player.asset[1][2][1]);
}

void	exit_game(t_game *game)
{
	if (game->nb_collectible == game->collected
		&& (game->player.x == game->exit.x && game->player.y == game->exit.y))
	{
		clean_game(game);
	}
}

void	clean_game(t_game *game)
{
	destroy_asset(game);
	mlx_loop_end(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_bidimentionnal((void **)game->map);
	exit(0);
}
