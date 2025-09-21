/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:29:43 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/21 18:50:08 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void loading_image(t_game *game)
{
    int i;
    char *image[5];

    i = 0;
    image[0] = "textures/coins.xpm";
    image[1] = "textures/player.xpm";
    image[2] = "textures/wall.xpm";
    image[3] = "textures/floor.xpm";
    image[4] = "textures/exit.xpm";
    while (i < 5)
    {
        game->img[i] = mlx_xpm_file_to_image(game->mlx, image[i], NULL, NULL);
        if (!game->img[i])
            exit_game(game, "Error: failed loading image", ERROR);
        i++;
    }
}

static void *get_image(char map, void **img)
{
    if (map == '1')
        return (img[2]);
    else if (map == '0')
        return (img[3]);
    else if (map == 'C')
        return (img[0]);
    else if(map == 'P')
        return (img[1]);
    else
        return (img[4]);
}

void put_image(t_game *game)
{
    int x;
    int y;
    void *img;
    
    x = 0;
    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x])
        {
            img = get_image(game->map[y][x], game->img);
            mlx_put_image_to_window(game->mlx, game->win, img, x * TILE_SIZE, y * TILE_SIZE);
            x++;
        }
        y++;
    }
}
