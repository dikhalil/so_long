/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:42:10 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/21 14:31:24 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include "../minilibx-linux/mlx.h"

#define TILE_SIZE 60
#define EXT_LEN 4
#define KEY_W 119      
#define KEY_A 97       
#define KEY_S 115      
#define KEY_D 100      
#define KEY_UP 65362
#define KEY_LEFT 65361
#define KEY_DOWN 65364
#define KEY_RIGHT 65363
#define KEY_ESC 65307
#define SUCCESS 0
#define ERROR 1

typedef struct s_game
{
    char **map;
    void *mlx;
    void *win;
    void *img[5];
    int img_width;
    int img_height;
    int map_height;
    int map_width;
    int player_x;
    int player_y;
	int	coins;
}   t_game;

/*---- main ----*/
void    so_long(t_game *game);

/*---- map ----*/
void    init_mapfile(t_game *game, char *file);
void    check_map(t_game *game);

/*---- flood fill ----*/
void flood_fill(t_game *game);

/*---- img ----*/
void    loading_image(t_game *game);
void    put_image(t_game *game);

/*---- hook ----*/
int close_handler(t_game *game);
int key_handler(int code, t_game *game);

/*---- move ----*/
void move_up(t_game *game);
void move_down(t_game *game);
void move_left(t_game *game);
void move_right(t_game *game);

/*---- error ----*/
void    free_map(char **map);
void    free_game(t_game *game);
void    exit_game(t_game *game, char *msg);

#endif
