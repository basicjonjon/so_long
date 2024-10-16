/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:24:14 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/16 20:14:02 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		return (1);
	if (verif_extention_file(argv[1], "ber"))
		return (ft_puterror("incorrect map extention"), 1);
	game.mlx = mlx_init();
	if (init_game(&game, argv[1]))
		return (mlx_destroy_display(game.mlx), free(game.mlx), 1);
	game.win = mlx_new_window(game.mlx, game.map_x * game.h, game.map_y
			* game.h, "so_long");
	display_game(&game);
	mlx_hook(game.win, 2, (1L << 0), &direction_change, &game);
	mlx_hook(game.win, 17, 0, &end_click_cross, &game);
	mlx_loop_hook(game.mlx, &player_loop, &game);
	mlx_loop(game.mlx);
	ft_free_bidimentionnal((void **)game.map);
	return (0);
}
