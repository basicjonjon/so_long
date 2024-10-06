/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:42:27 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/04 17:00:43 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	get_map_size(t_game *game, char *file)
{
	int		fd;
	char	*line;

	game->map_x = 0;
	game->map_y = 0;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
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

int	get_map(t_game *game, char *file)
{
	int	i;
	int	fd;

	i = 0;
	get_map_size(game, file);
	game->map = malloc(sizeof(char **) * (game->map_y + 1));
	fd = open(file, O_RDONLY);
	game->map[i] = get_next_line(fd);
	while (game->map[i])
	{
		i++;
		game->map[i] = get_next_line(fd);
	}
	game->map[i] = NULL;
	return (0);
}

