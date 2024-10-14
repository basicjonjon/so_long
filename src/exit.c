/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 13:15:08 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/14 13:04:45 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	get_exit(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y <= game->map_y)
	{
		x = 0;
		while (x <= game->map_x)
		{
			if (game->map[y][x] == 'E')
			{
				game->exit.x = x;
				game->exit.y = y;
				printf("exit x %i, exit y %i\n", x, y);
				return ;
			}
			x++;
		}
		y++;
	}
}
