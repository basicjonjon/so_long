/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jle-doua <jle-doua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:53:34 by jle-doua          #+#    #+#             */
/*   Updated: 2024/10/17 16:02:19 by jle-doua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	display_info(t_game game)
{
	ft_printf("collectible : %i/%i\n", game.collected, game.nb_collectible);
	ft_printf("mouvement : %i\n", game.move);
}
