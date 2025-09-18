/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/18 12:42:07 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/18 14:24:44 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void exit_error(char *msg)
{
    write(1, msg, ft_strlen(msg));
    exit(1);
}
void so_long(t_game *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
        return ;
    game->win = mlx_new_window(game->mlx, , , "so_long");
    if (!game->win)
        return ;
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

void    read_mapfile(t_game *game, char *file)
{
    int fd;
    int i;
    char *line;
    
    i = 0;
    if (ft_strlen(file) < 4 && ft_strncmp(file + ft_strlen - 4, ".ber", 4))
        exit_error("Error: map file must have a .ber extension\n");
    fd = open(file, O_RDONLY);
    if (fd == -1)
        exit_error("Can not open the file");
    game->height = map_height(fd);
    game->map = malloc(sizeof(char *) *game->height + 1);
    if (!game->map)
        exit_error("malloc faild for char **map");
    while (1)
    {
        line = get_next_line(fd);
        if (!line)
            break;
        map[i++] = ft_strtrim(line, "\n");
    }
    map[i] = NULL;
    close(fd);
}
int isrectangle (char **map)
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
            return (1);
        i++;
    }
    return (0);
}
int check_map(t_game *game)
{
    
}

int main(int argc, char **argv)
{
    t_game game;
    if  (argc != 2)
        exit_error("Invalid Input");
    game->map = read_mapfile(&game, argv[1]);
    if (!game->map)
        return ;
    if (check_map(&game))
        exit_error("Invalid map");
    so_long(&game);
}
