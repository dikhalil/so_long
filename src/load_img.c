/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 20:29:43 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/20 09:14:42 by dikhalil         ###   ########.fr       */
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
        game->img[i] = mlx_xpm_file_to_image(game->mlx, image[i], game->img_width + i, game->img_height + i);
        if (!game->img[i])
            exit_error(game, "Error: failed loading image\n");
        i++;
    }
}

static void *get_image(char map, void **img, int *width, int *height)
{
    if (map == '1')
    {
        width = game->img_width[2];
        height = game->img_height[2];
        return (img[2]);
    }
    else if (map == '0')
    {
        width = game->img_width[3];
        height = game->img_height[3];
        return (img[3]);
    }
    else if (map == 'C')
    {
        width = game->img_width[0];
        height = game->img_height[0];
        return (img[0]);
    }
    else if(map == 'P')
    {
        width = game->img_width[1];
        height = game->img_height[1];
        return (img[1]);
    }
    else
    {
        width = game->img_width[4];
        height = game->img_height[4];
        return (img[4]);
    }
}

void put_image(t_game *game)
{
    int x;
    int y;
    int width;
    int height;
    void *img;
    
    x = 0;
    y = 0;
    while (game->map[y])
    {
        x = 0;
        while (game->map[y][x], &width, &height)
        {
            img = get_image(game->map[y][x], game->img);
            mlx_put_image_to_window(game->mlx, game->win, img, x * width, y * height);
            x++;
        }
        y++;
    }
}
