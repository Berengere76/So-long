/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 16:42:15 by blebas            #+#    #+#             */
/*   Updated: 2023/12/04 16:46:30 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "minilibx/mlx42.h"

void	init_game(goty_t *goty)
{
	ft_bzero(goty, sizeof(goty_t));
	goty->map.count_y = 0;
	goty->map.count_x = 0;
	goty->wall_count = 0;
	goty->count_tomate = 0;
	goty->nb_p = 0;
	goty->nb_e = 0;
	goty->nb_t = 0;
	goty->map.exit = 0;
	goty->map.item = 0;
	goty->map.path = 0;
	goty->can_exit = 0;
	goty->perso.pos_x = 0;
	goty->perso.pos_y = 0;
	goty->perso.nb_mouv = 0;
}

void	start_game(goty_t *goty)
{
	goty->mlx = mlx_init(goty->width, goty->height, "YakuzAlphonse", false);
	if (!goty->mlx)
		error();
	ft_image(goty);
	if (mlx_image_to_window(goty->mlx, goty->image.background, 0, 0) < 0)
		error();
	fill_map(goty);
	start_player(goty);
}

void	free_map(goty_t *goty)
{
	int		i;

	i = -1;
	while (++i < goty->height / 64)
		free(goty->map.map[i]);
	free(goty->map.map);
}
void	ft_quit(goty_t *goty)
{
	mlx_delete_image(goty->mlx, goty->image.perso);
	mlx_delete_texture(goty->texture.perso_texture);
	mlx_delete_image(goty->mlx, goty->image.background);
	mlx_delete_texture(goty->texture.background_texture);
	mlx_delete_image(goty->mlx, goty->image.mur);
	mlx_delete_texture(goty->texture.mur_texture);
	mlx_delete_image(goty->mlx, goty->image.tomate);
	mlx_delete_texture(goty->texture.tomate_texture);
	mlx_delete_image(goty->mlx, goty->image.sortie);
	mlx_delete_texture(goty->texture.sortie_texture);
	mlx_terminate(goty->mlx);
	free_map(goty);
}
