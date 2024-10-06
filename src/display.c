/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:34:37 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/06 17:07:34 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// void	display_map(t_maps map)
// {
// 	int x;
// 	int y;

// 	y = 0;
// 	while (map.map[y])
// 	{
// 		x = 0;
// 		while (map.map[y][x])
// 		{
// 			if (map.map[y][x] == '1')
// 				display_1(x, y, map);
// 			else if (map.map[y][x] == '0')
// 				put_floor(x, y, map);
// 			else if (map.map[y][x] == 'E')
// 				display_exit(map);
// 			x++;
// 		}
// 		y++;
// 	}
// 	display_collectible(&map);
// 	display_player(&map);
// }