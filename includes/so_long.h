/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:24:50 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/07 17:55:57 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/include/libft.h"
# include "../lib/minilibx-linux/mlx.h"

typedef struct s_asset
{
	void		*w;
	void		*f;
	void		*f2;
	void		*player[2];
	void		*c;
}				t_asset;

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
	void		*mlx;
	void		*win;
	int			h;
	char		**map;
	int			map_x;
	int			map_y;
	int			nb_collectible;
	int			collected;
	int			nb_player;
	int			nb_exit;
	int			keypress;
	t_player	player;
	t_verif		verif;
	t_asset		asset;
}				t_game;

int				init_game(t_game *game, char *file);

int				get_map_size(t_game *game, char *file);
int				get_map(t_game *game, char *file);

void			display_info(t_game game);

int				verif_validity_map(t_game game);
int				verif_border(t_game game);
int				verif_count_p_e_c(t_game *game);
int				verif_shape(t_game game);
int				verif_finishable(t_game *game, int x, int y);
char			**ft_bidimentionnal_char_cpy(char **tab);

void			get_player_position(t_game *game);

int				ft_tablen(char **tab);
char			**ft_bidimentionnal_char_cpy(char **tab);

void			init_asset(t_game *game);

void			display_map(t_game *game);

int				key_hook(int keycode, t_game *game);
int				move_rigth(t_game *game);
int				move_left(t_game *game);
int				move_bottom(t_game *game);
int				move_top(t_game *game);
#endif