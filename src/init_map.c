/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:07:27 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/20 09:14:48 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static void map_height(t_game *game, char *file)
{
    char *line;
    int fd;

    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit_error(game, "Error: Can not open the file\n");    
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
        exit_error(game, "Error: Can not open the file\n");
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        game->map[i++] = ft_strtrim(line, "\n");
        if (!game->map[i - 1])
        {
            close(fd);
            exit_error(game, "Error: malloc failed for map line\n");
        }
        free(line);
    }
    game->map[i] = NULL;
    close(fd);
}

void    init_mapfile(t_game *game, char *file)
{
    if (ft_strlen(file) < 4 || ft_strncmp(file + ft_strlen(file) - 4, ".ber", 4))
        exit_error(game, "Error: map file must have a .ber extension\n");
    map_height(game, file);
    game->map = malloc(sizeof(char *) * (game->map_height + 1));
    if (!game->map)
        exit_error(game, "Error: malloc failed for map\n");
    read_map_lines(game, file);
    if (!game->map[0])
        exit_error(game, "Error: map is empty\n");
    game->map_width = ft_strlen(game->map[0]);
}
