/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:29:43 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/19 22:07:56 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void loading_image(t_game *game)
{
    int i;
    char *image[5];

    i = 0;
    image[0] = "textures/burger.xpm";
    image[1] = "textures/spong.xpm";
    image[2] = "textures/wall.xpm";
    image[3] = "textures/floor.xpm";
    image[4] = "textures/exit.xpm";
    while (i < 5)
    {
        game->img[i] = mlx_xpm_file_to_image(game->mlx, image[i], &(game->img_width), &(game->img_height));
        if (!game->img[i])
            exit_error(game, "Error: failed loading image\n");
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
            mlx_put_image_to_window(game->mlx, game->win, img, x * game->img_width, y * game->img_height);
            x++;
        }
        y++;
    }
}
