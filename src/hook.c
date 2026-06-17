/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 22:39:27 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/24 18:00:24 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

int	close_handler(t_game *game)
{
	exit_game(game, "Game closed", SUCCESS);
	return (0);
}

int	key_handler(int code, t_game *game)
{
	if (code == KEY_W || code == KEY_UP)
		move_up(game);
	if (code == KEY_A || code == KEY_LEFT)
		move_left(game);
	if (code == KEY_S || code == KEY_DOWN)
		move_down(game);
	if (code == KEY_D || code == KEY_RIGHT)
		move_right(game);
	if (code == KEY_ESC)
		exit_game(game, "Game closed", SUCCESS);
	return (0);
}
