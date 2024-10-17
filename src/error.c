/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:16:46 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/17 13:27:45 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	error_map(t_game *game)
{
	if (verif_count_p_e_c(game))
		ft_puterror("no player, exit or collectible");
	if (verif_shape(*game))
		ft_puterror("map is not rectangular");
	if (verif_border(*game))
		ft_puterror("map border have problem");
	if (verif_unauthorized_letter(game))
		ft_puterror("ukown char in map");
	if ((game->map_x < 5 || game->map_y < 3) || game->nb_player != 1
		|| game->nb_exit != 1 || game->nb_collectible == 0 || verif_shape(*game)
		|| verif_border(*game) || verif_unauthorized_letter(game))
		return (ft_free_bidimentionnal((void **)game->map), 1);
	ft_printf("%s[ MAP OK ]%s\n", GREEN, NC);
	return (0);
}

int	error_gameplay(t_game *game)
{
	verif_finishable(game, game->player.x, game->player.y);
	if (game->verif.exit == 0
		|| game->verif.collectible != game->nb_collectible)
	{
		ft_puterror("map is not finishable");
		return (ft_free_bidimentionnal((void **)game->verif.map),
			ft_free_bidimentionnal((void **)game->map), 1);
	}
	return (0);
}

int	error_asset(t_game *game)
{
	if (verif_asset(game))
	{
		ft_puterror("ERROR : asset is invalid");
		ft_free_bidimentionnal((void **)game->map);
		return (1);
	}
	return (0);
}
