/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:53:34 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/21 14:31:18 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_info(t_game game)
{
	ft_printf("\033[H\033[J");
	ft_printf("collectible : %i/%i\n", game.collected, game.nb_collectible);
	ft_printf("mouvement : %i\n", game.move);
}
