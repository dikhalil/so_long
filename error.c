/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:11:28 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/19 22:02:29 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_game(t_game *game)
{
	int i;

	i = 0;
	if (!game)
		return ;
	if (game->img)
		while (i < 5)
			if (game->img[i])
		    	mlx_destroy_image(game->mlx, game->img[i++]);
	i = 0;
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	
}

void exit_error(t_game *game, char *msg)
{
    write(1, msg, ft_strlen(msg));
	free_game(game);
    exit(1);
}
