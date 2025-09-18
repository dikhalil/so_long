/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:42:10 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/18 19:49:07 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include "./minilibx-linux/mlx.h"

typedef struct s_game
{
    char **map;
    void *mlx;
    void *win;
    int map_height;
    int map_width;
    int x;
    int y;
	int	collect;
}   t_game;

#endif
