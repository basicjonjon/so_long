/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:16:46 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/14 12:54:17 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	verif_validity_map(t_game game)
{
	int	verif;

	verif = 0;
	if (game.map_x < 5 || game.map_y < 3)
		printf("%sERROR : map is to small\n%s", RED, NC);
	if (verif_count_p_e_c(&game))
		printf("%sERROR : no player, exit or collectible\n%s", RED, NC);
	if (verif_shape(game))
		printf("%sERROR : map is not rectangular\n%s", RED, NC);
	if (verif_border(game))
		printf("%sERROR : map border have problem\n%s", RED, NC);
	verif_finishable(&game, game.player.plyr_x, game.player.plyr_y);
	if (game.verif.exit == 0 || game.verif.collectible != game.nb_collectible)
		printf("%sERROR : map is not finishable\n%s", RED, NC);
	if ((game.map_x < 5 || game.map_y < 3) || verif_count_p_e_c(&game)
		|| verif_shape(game) || verif_border(game) || game.verif.exit == 0
		|| game.verif.collectible != game.nb_collectible)
		return (ft_free_bidimentionnal((void **)game.verif.map), 1);
	ft_free_bidimentionnal((void **)game.verif.map);
	printf("%s[ MAP OK ]%s\n", GREEN, NC);
	return (0);
}
