/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:24:14 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/08 17:04:14 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_hook(int keycode, t_game *game)
{
	if (keycode == 100 || keycode == 65363 || keycode == 97 || keycode == 65361
		|| keycode == 119 || keycode == 65362 || keycode == 115
		|| keycode == 65364)
	{
		game->keypress = keycode;
	}
	return (0);
}

int	move_loop(t_game *game)
{
	static int	counter = 0;
	int			speed_limit;

	speed_limit = 22000;
	if (counter < speed_limit)
	{
		counter++;
		return (0);
	}
	counter = 0;
	if (game->keypress == 100 || game->keypress == 65363)
		move_rigth(game);
	if (game->keypress == 97 || game->keypress == 65361)
		move_left(game);
	if (game->keypress == 119 || game->keypress == 65362)
		move_top(game);
	if (game->keypress == 115 || game->keypress == 65364)
		move_bottom(game);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		return (1);
	game.mlx = mlx_init();
	if (init_game(&game, argv[1]))
		return (ft_free_bidimentionnal((void **)game.map), 1);
	game.win = mlx_new_window(game.mlx, game.map_x * game.h, game.map_y
			* game.h, "so_long");
	display_map(&game);
	mlx_hook(game.win, 2, (1L << 0), &get_hook, &game);
	mlx_loop_hook(game.mlx, &move_loop, &game);
	mlx_loop(game.mlx);
	ft_free_bidimentionnal((void **)game.map);
	return (0);
}