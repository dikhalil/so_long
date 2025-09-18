/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:42:07 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/18 21:12:24 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void free_game(t_game *game)
{
	int i;

	i = 0;
	if (game->mlx)
		free(game->mlx);
	if (game->win)
		free(game->win);
	if (game->map)
	{
		while (game->map[i])
			free(game->map[i++]);
		free(game->map);
	}
}

void exit_error(t_game *game, char *msg)
{
    write(1, msg, ft_strlen(msg));
	free_game(game);
    exit(1);
}

void so_long(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return ;
    game->win = mlx_new_window(game->mlx, game->map_width, game->map_height, "so_long");
    if (!game->win)
        return ;
	//image loop
    mlx_loop(game->mlx);
}

int map_height(int fd)
{
    int count;
    char *line;
    
    count = 0;
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        count++;
        free(line);
    }
    return (count);
}

int map_width(t_game *game)
{
    int count;

    count = ft_strlen(game->map[0]);
    return (count);
}

void    read_mapfile(t_game *game, char *file)
{
    int fd;
    int i;
    char *line;

    i = 0;
    if (ft_strlen(file) < 4 && ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4))
        exit_error(game, "Error: map file must have a .ber extension\n");
    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit_error(game, "Error: Can not open the file\n");
    game->map_height = map_height(fd);
    game->map = malloc(sizeof(char *) * game->map_height + 1);
    if (!game->map)
        exit_error(game, "Error: malloc faild for map\n");
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        game->map[i++] = ft_strtrim(line, "\n");
    }
    game->map[i] = NULL;
    close(fd);
}

int isrectangle(char **map)
{
    int len;
    int i;
    int j;

    i = 1;
    j = 0;
    len = ft_strlen(map[0][0]);
    while (map[i])
    {
        j = 0;
        while(map[i][j])
            j++;
        if (j != len)
            return (0);
        i++;
    }
    return (1);
}

int enclosed(t_game *game)
{
	int i;
	int j;
	
	i = 1;
	j = 0;
	
	while (game->map[0][j])
		if (game->map[0][j] != '1' || game->map[game->map_height - 1][j++] != '1')
			return (0);
	while (i < game->map_height)
		if (game->map[i][0] != '1' && game->map[i++][game->map_width - 1] != '1')
			return (0);
}

int isvalidchar(t_game *game)
{
	int i;
	int j;
	int e;
	int p;

	i = -1;
	j = -1;
	e = 0;
	p = 0;
	while (game->map[++i])
	{
		j = -1;
		while (game->map[i][++j])
		{
			if (game->map[i][j] == 'P')
				p++;
			else if (game->map[i][j] == 'E')
				e++;
			else if (game->map[i][j] == 'C')
				game->collect++;
			else if (game->map[i][j] != '1' && game->map[i][j] != '0' )
				return (0);
		}
	}
	return (e == 1 && p == 1 && game->collect >= 1);
}

int check_map(t_game *game)
{
	int i;

	i = 0;
    if (!isrectangle(game->map))
		exit_error(game, "Error: Map must be rectangle\n");
	if (!enclosed(game))
		exit_error(game, "Error: Map must be enclosed/surrounded by walls\n");
	if (!isvalidchar(game))
		exit_error(game, "Error: Map must contain 1 exit, 1 starting position and at least 1 collectible\n");
}
void flood_fill(t_game *game)
{
	
}
int main(int argc, char **argv)
{
    t_game game;

    if  (argc != 2)
        exit_error(&game, "Error: Invalid Input\n");
	ft_bzero(&game, sizeof(game));
    read_mapfile(&game, argv[1]);
    if (!game.map)
        return ;
	game.map_width = map_width(&game);
    if (check_map(&game))
        exit_error(&game, "Error: Invalid map\n");
	flood_fill(&game);
    so_long(&game);
	return (0);
}

