/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 13:24:50 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/16 21:41:45 by jle-doua         ###   ########.fr       */
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
	void		*c;
	void		*e;
}				t_asset;

typedef struct s_verif
{
	int			exit;
	int			collectible;
	char		**map;

}				t_verif;

typedef struct s_exit
{
	int			x;
	int			y;
}				t_exit;

typedef struct s_player
{
	int			x;
	int			y;
	int			rot_x;
	int			rot_y;
	void		*asset[2][3][2];
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
	int			move;
	t_player	player;
	t_verif		verif;
	t_asset		asset;
	t_exit		exit;
}				t_game;

int				init_game(t_game *game, char *file);
void			init_game_value(t_game *game);

void			display_info(t_game game);

int				verif_finishable(t_game *game, int x, int y);
int				verif_count_p_e_c(t_game *game);
int				verif_border(t_game game);
int				verif_asset(t_game *game);
int				verif_shape(t_game game);

int				error_map(t_game *game);
int				error_asset(t_game *game);
int				error_gameplay(t_game *game);

int				player_bottom(t_game *game);
int				player_rigth(t_game *game);
int				player_left(t_game *game);
int				player_loop(t_game *game);
int				player_top(t_game *game);

int				verif_extention_file(char *s, char *ext);
char			**ft_bidimentionnal_char_cpy(char **tab);
int				ft_tablen(char **tab);

void			init_asset_player(t_game *game);
void			init_asset_map(t_game *game);

void			display_game(t_game *game);
void			display_map(t_game *game, int x, int y);
void			display_player(t_game *game);

int				direction_verification(int keycode, t_game *game);
int				direction_change(int keycode, t_game *game);

int				get_map_size(t_game *game, int fd);
int				get_map(t_game *game, int fd);
void			get_player_position(t_game *game);
void			get_exit(t_game *game);

int				end_click_cross(t_game *game);
void			end_clean_game(t_game *game);
void			end_game(t_game *game);

void			destroy_asset_animation(t_game *game);
void			destroy_asset_player(t_game *game);
void			destroy_asset_map(t_game *game);
void			destroy_asset(t_game *game);
#endif