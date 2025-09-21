/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:07:27 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/21 14:18:00 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void map_height(t_game *game, char *file)
{
    char *line;
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit_game(game, "Error: Can not open the file", ERROR);    
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        game->map_height++;
        free(line);
    }
    close(fd);
}

static void read_map_lines(t_game *game, char *file)
{
    int i;
    int fd;
    char *line;

    i = 0;
    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit_game(game, "Error: Can not open the file", ERROR);
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        if (!*line || line[0] == '\n')
        {
            free(line);
            close(fd);
            exit_game(game, "Error: map contains empty line", ERROR);
        }
        game->map[i++] = ft_strdup(line);
        free(line);
    }
    game->map[i] = NULL;
    close(fd);
}

void    init_mapfile(t_game *game, char *file)
{
    if (ft_strlen(file) < EXT_LEN || ft_strncmp(file + ft_strlen(file) - EXT_LEN, ".ber", EXT_LEN))
        exit_game(game, "Error: map file must have a .ber extension", ERROR);
    map_height(game, file);
    game->map = malloc(sizeof(char *) * (game->map_height + 1));
    if (!game->map)
        exit_game(game, "Error: malloc failed for map", ERROR);
    read_map_lines(game, file);
    if (!game->map[0])
        exit_game(game, "Error: map is empty", ERROR);
    game->map_width = ft_strlen(game->map[0]);
}
