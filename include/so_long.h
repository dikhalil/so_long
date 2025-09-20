/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:42:10 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/20 08:59:32 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

typedef struct s_game
{
    char **map;
    void *mlx;
    void *win;
    void *img[5];
    int img_width;
    int img_height;
    int map_height[5];
    int map_width[5];
    int player_x;
    int player_y;
	int	coins;
}   t_game;

void so_long(t_game *game);

/*---- map ----*/
void    init_mapfile(t_game *game, char *file);
void check_map(t_game *game);

/*---- flood fill ----*/
void flood_fill(t_game *game);

/*---- img ----*/
void loading_image(t_game *game);
void put_image(t_game *game);

/*---- hook ----*/
int close_handler(t_game *game);
int key_handler(int code, t_game *game);

/*---- error ----*/
void free_game(t_game *game);
void exit_error(t_game *game, char *msg);
void free_map(char **map);


#endif
