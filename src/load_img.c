/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:29:43 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/22 11:51:38 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	loading_image(t_game *game)
{
	int		i;
	int		width;
	int		height;
	char	*image[6];

	i = 0;
	image[0] = "textures/coin.xpm";
	image[1] = "textures/player.xpm";
	image[2] = "textures/wall.xpm";
	image[3] = "textures/floor.xpm";
	image[4] = "textures/exit.xpm";
	image[5] = "textures/player_exit.xpm";
	while (i < 6)
	{
		game->img[i] = mlx_xpm_file_to_image(game->mlx, image[i], &width,
				&height);
		if (!game->img[i])
			exit_game(game, "Error: failed loading image", ERROR);
		i++;
	}
}

static void	*get_image(char map, void **img)
{
	if (map == '1')
		return (img[2]);
	else if (map == '0')
		return (img[3]);
	else if (map == 'C')
		return (img[0]);
	else if (map == 'P')
		return (img[1]);
	else if (map == 'E')
		return (img[4]);
	else if (map == 'M')
		return (img[5]);
	else
		return (NULL);
}

void	put_image(t_game *game)
{
	int		x;
	int		y;
	void	*img;

	x = 0;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			img = get_image(game->map[y][x], game->img);
			mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y
				* TILE_SIZE);
			x++;
		}
		y++;
	}
}
