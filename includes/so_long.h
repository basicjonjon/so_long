/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:24:50 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/06 16:57:00 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/include/libft.h"
# include "../lib/minilibx-linux/mlx.h"

typedef struct s_verif
{
	int			exit;
	int			collectible;
	char		**map;

}				t_verif;

typedef struct s_player
{
	int			plyr_x;
	int			plyr_y;
}				t_player;

typedef struct s_game
{
	char		**map;
	int			map_x;
	int			map_y;
	int			nb_collectible;
	int			collected;
	int			nb_player;
	int			nb_exit;
	t_player	player;
	t_verif		verif;
}				t_game;

int				init_game(t_game *game, char *file);

int				get_map_size(t_game *game, char *file);
int				get_map(t_game *game, char *file);

void			display_info(t_game game);

int				verif_validity_map(t_game game);
int				verif_border(t_game game);
int				verif_count_p_e_c(t_game game);
int				verif_shape(t_game game);
int				verif_finishable(t_game *game, int x, int y);
char			**ft_bidimentionnal_char_cpy(char **tab);

void			get_player_position(t_game *game);

#endif