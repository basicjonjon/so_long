/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:53:34 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/04 15:23:55 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_info(t_game game)
{
	int	y;

	y = 0;
	printf("size :\n|  x : %i  |  y : %i  |\n", game.map_x, game.map_y);
	printf("\nmap :\n");
	while (y < game.map_y)
	{
		printf("%s", game.map[y]);
		y++;
	}
}
