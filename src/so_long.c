/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:42:07 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/22 10:37:20 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	so_long(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit_game(game, "Error: mlx init failed", ERROR); ;
	loading_image(game);
	game->win = mlx_new_window(game->mlx, game->map_width * TILE_SIZE,
			game->map_height * TILE_SIZE, "so_long");
	if (!game->win)
		exit_game(game, "Error: mlx new window failed", ERROR);
	put_image(game);
	mlx_key_hook(game->win, key_handler, game);
	mlx_hook(game->win, 17, 0, close_handler, game);
	mlx_loop(game->mlx);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (argc != 2)
		exit_game(NULL, "Error: Invalid Input", ERROR);
	ft_bzero(&game, sizeof(game));
	init_mapfile(&game, argv[1]);
	check_map(&game);
	flood_fill(&game);
	so_long(&game);
	return (SUCCESS);
}
