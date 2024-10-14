/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 15:07:37 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/14 16:14:45 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	end_game(t_game *game)
{
	if (game->nb_collectible == game->collected
		&& (game->player.x == game->exit.x && game->player.y == game->exit.y))
	{
		end_clean_game(game);
	}
}

void	end_clean_game(t_game *game)
{
	destroy_asset(game);
	mlx_loop_end(game->mlx);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	ft_free_bidimentionnal((void **)game->map);
	exit(0);
}
