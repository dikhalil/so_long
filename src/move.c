/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 23:12:20 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/21 18:44:47 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void try_move(t_game *game, int new_x, int new_y)
{
    if (game->map[new_y][new_x] == '1')
        return ;
    if (game->map[new_y][new_x] == 'C')
        game->coins--;
    if (game->map[new_y][new_x] == 'E')
    {
        if (game->coins > 0)
            return ;
        exit_game(game, "You win!", SUCCESS);
    }
    game->map[game->player_y][game->player_x] = '0';
    game->map[new_y][new_x] = 'P';
    game->player_x = new_x;
    game->player_y = new_y;    
    put_image(game);
    return ;
}

void move_up(t_game *game)
{
    try_move(game, game->player_x, game->player_y - 1);
}

void move_down(t_game *game)
{
    try_move(game, game->player_x, game->player_y + 1);
}

void move_left(t_game *game)
{
    try_move(game, game->player_x - 1, game->player_y);
}

void move_right(t_game *game)
{
    try_move(game, game->player_x + 1, game->player_y);
}

