/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:24:14 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/07 18:17:08 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_hook(int keycode, t_game *game)
{
	game->keypress = keycode;
	return (0);
}

int	move_loop(t_game *game)
{
	static int	counter = 0;

	int speed_limit = 22000; // Ajuste cette valeur pour modifier la vitesse
	if (counter < speed_limit)
	{
		counter++;
		return (0); // Attendre avant de déplacer le joueur
	}
	counter = 0; // Réinitialiser le compteur après avoir atteint la limite
	// Déplacement selon la touche pressée
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