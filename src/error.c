/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:11:28 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/21 14:05:02 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void free_map(char **map)
{
	int i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

void free_game(t_game *game)
{
	int i;

	i = 0;
	while (i < 5)
		if (game->img[i])
		{
		    mlx_destroy_image(game->mlx, game->img[i]);
			i++;
		}
	free_map(game->map);
	if (game->mlx && game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void exit_game(t_game *game, char *msg, int status)
{
	if (status)
		ft_putendl_fd(msg, 2);
	else
		ft_putendl_fd(msg, 1);
	if (game)
		free_game(game);
    exit(status);
}
