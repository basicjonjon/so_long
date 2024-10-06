/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:24:14 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/04 16:11:39 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	t_game game;

	if (argc != 2)
		return (1);

	if (init_game(&game, argv[1]))
		return (ft_free_bidimentionnal((void **)game.map), 1);
	display_info(game);
	ft_free_bidimentionnal((void **)game.map);
	return (0);
}