/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 22:39:27 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/19 23:12:04 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int close_handler(t_game *game)
{
    exit_error(game, "Game closed\n");
    return (0);
}
int key_handler(int code, t_game *game)
{
    if (code == 13 || code == 126)
        move_up(game);
    else if (code == 0 || code == 123)
        move_left(game);
    else if (code == 1 || code == 125)
        move_down(game);
    else if (code == 2 || code == 124)
        move_right(game);
    else if (code == 65307)
        exit_error(game, "Game closed\n");
    return (0);
}