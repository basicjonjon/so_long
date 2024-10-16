/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 15:23:08 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/16 22:21:22 by jle-doua         ###   ########.fr       */
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
				return ;
			}
			x++;
		}
		y++;
	}
}

void	get_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'P')
			{
				game->player.x = x;
				game->player.y = y;
			}
			x++;
		}
		y++;
	}
}

int	get_map_size(t_game *game, int fd)
{
	char	*line;

	game->map_x = 0;
	game->map_y = 0;
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	if (!line)
		return (ft_puterror("file empty"), 1);
	game->map_x = ft_strlennojl(line);
	while (line)
	{
		game->map_y++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (0);
}

int	get_map(t_game *game, int fd)
{
	int	i;

	i = 0;
	if (fd == -1)
		return (1);
	game->map = malloc(sizeof(char **) * (game->map_y + 1));
	if (!game->map)
		return (1);
	game->map[i] = get_next_line(fd);
	while (game->map[i])
	{
		i++;
		game->map[i] = get_next_line(fd);
	}
	close(fd);
	game->map[i] = get_next_line(fd);
	return (0);
}
