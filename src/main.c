/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:24:14 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/14 16:17:31 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_mouse(t_game *game)
{
	end_clean_game(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	game.mlx = mlx_init();
	if (init_game(&game, argv[1]))
		return (mlx_destroy_display(game.mlx), free(game.mlx), 1);
	game.win = mlx_new_window(game.mlx, game.map_x * game.h, game.map_y
			* game.h, "so_long");
	display_map(&game);
	mlx_hook(game.win, 2, (1L << 0), &direction_change, &game);
	mlx_hook(game.win, 17, 0, &ft_mouse, &game);
	mlx_loop_hook(game.mlx, &player_loop, &game);
	mlx_loop(game.mlx);
	ft_free_bidimentionnal((void **)game.map);
	return (0);
}
