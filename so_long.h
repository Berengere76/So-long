/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blebas <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 12:29:41 by blebas            #+#    #+#             */
/*   Updated: 2023/11/24 12:37:39 by blebas           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <memory.h>
# include <fcntl.h>
# include "minilibx/mlx42.h"
# include "Libft/libft.h"

typedef struct image
{
	mlx_image_t	*perso;
	mlx_image_t	*perso2;
	mlx_image_t	*background;
	mlx_image_t	*mur;
	mlx_image_t	*tomate;
	mlx_image_t	*sortie;
} 							image_t;

typedef struct texture
{
	mlx_texture_t	*perso_texture;
	mlx_texture_t	*perso_texture2;
	mlx_texture_t	*background_texture;
	mlx_texture_t	*mur_texture;
	mlx_texture_t	*tomate_texture;
	mlx_texture_t	*sortie_texture;
} 							texture_t;

typedef struct map
{
	char	**map;
	char	**path;
	char	*file_map;
	int		item;
	int		exit;
	int		fd;
	int		count_y;
	int		count_x;
} 							map_t;

typedef struct perso
{
	int		pos_y;
	int		pos_x;
	int		nb_mouv;
} 							perso_t;

typedef struct goty
{
	mlx_t		*mlx;
	image_t		image;
	texture_t	texture;
	map_t		map;
	perso_t		perso;
	int			wall_count;
	int			width;
	int			height;
	int			count_tomate;
	int			can_exit;
	int			nb_p;
	int			nb_t;
	int			nb_e;
	int			posx;
	int			posy;
	int			countx;
	int			county;
	int			jpp;
	char		*error_file;
} 							goty_t;

//texture.c
void	ft_loadpng(goty_t *goty);
void	ft_texture_image(goty_t *goty);
void	ft_resize(goty_t *goty);
void	ft_image(goty_t *goty);

//game.c
void	init_game(goty_t *goty);
void	start_game(goty_t *goty);
void	free_map(goty_t *goty);
void	ft_quit(goty_t *goty);

//map.c
void	lenght_map(goty_t *goty);
void	init_map(goty_t *goty, int i, char *str);
void	fill_item(goty_t *goty, int x, int y);
void	fill_map(goty_t *goty);

//perso.c
void	init_player(goty_t *goty);
void    fill_player(goty_t *goty, int x, int y);
void    start_player(goty_t *goty);
void    eat_tomato(goty_t *goty, int x, int y);
void    ft_can_exit (goty_t *goty);

//movement.c
void	ft_hook(mlx_key_data_t keydata, void *param);
void    move_up(goty_t *goty);
void    move_down(goty_t *goty);
void    move_left(goty_t *goty);
void    move_right(goty_t *goty);

//error.c
int		map_rectangle(goty_t *goty);
int		is_wall(goty_t *goty);
char	*check_error(goty_t *goty);

//check_path.c
void	free_mapcheck(goty_t *goty);
void	init_mapcheck(goty_t *goty);
int		map_checked(goty_t *goty, int y, int x);
void	count_items(goty_t *games, int y, int x);
int		check_path(goty_t *goty, int y, int x);

//so_long.c
void	error(void);
int		free_error(goty_t *goty, char *error);
char	*file_is_ber(goty_t *goty, int ac);
int		check_file(goty_t *goty, int ac, char **av);
int32_t		main(int ac, char **av);
	
#endif
