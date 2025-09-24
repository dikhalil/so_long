/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:11:28 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/22 13:40:49 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	player_exit(t_game *game, int new_x, int new_y)
{
	game->map[game->player_y][game->player_x] = '0';
	game->map[new_y][new_x] = 'M';
	game->player_x = new_x;
	game->player_y = new_y;
	put_image(game);
	if (game->coins > 0)
		return ;
	exit_game(game, "You win!", SUCCESS);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map || !map[i])
		return ;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	free_map(game->map);
	while (i < 6)
	{
		if (game->img[i])
			mlx_destroy_image(game->mlx, game->img[i]);
		i++;
	}
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	exit_game(t_game *game, char *msg, int status)
{
	if (status)
		ft_putendl_fd(msg, 2);
	else
		ft_putendl_fd(msg, 1);
	if (game)
		free_game(game);
	exit(status);
}
