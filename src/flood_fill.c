/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:07:59 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/20 09:15:01 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

static int isallreached(char **original, char **visited)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (original[i])
    {
        j = 0;
        while (original[i][j])
        {
            if (original[i][j] == 'C' || original[i][j] == 'E')
                if (visited[i][j] != 'V')
                    return (0);
            j++;
        }
        i++;
    }
    return (1);
}
static char **copy_map(char **map, int height)
{
    int i;
    char **tmp;

    i = 0;
    tmp = malloc(sizeof(char *) * (height + 1));
    if (!tmp)
        return (NULL);
    while (map[i])
    {
        tmp[i] = ft_strdup(map[i]);
        if (!tmp[i])
        {
            while(--i >= 0)
                free(tmp[i]);
            free(tmp);
            return (NULL);
        }
        i++;
    }
    tmp[i] = NULL;
    return (tmp);
}

static void find_player(t_game *game)
{
    int i;
    int j;
    
    i = 0;
    j = 0;
    while (game->map[i])
    {
        j = 0;
        while(game->map[i][j])
        {
            if (game->map[i][j] == 'P')
            {
                game->player_x = j;
                game->player_y = i;
            }
            j++;
        }
        i++;
    }
}

static void fill(t_game game, int x, int y, int height, int width)
{
    if (x == -1 || y == -1 || x >= width || y >= height)
        return ;
    if (game.map[y][x] == '1' || game.map[y][x] == 'V')
        return ;
    game.map[y][x] = 'V';
    fill(game, x + 1, y, height, width);
    fill(game, x - 1, y, height, width);
    fill(game, x, y + 1, height, width);
    fill(game, x, y - 1, height, width);
}

void flood_fill(t_game *game)
{
    t_game tmp;
    
    tmp.map_height = game->map_height;
    tmp.map_width = game->map_width;
    tmp.map = copy_map(game->map, game->map_height);
    if (!tmp.map)
        exit_error(game, "Error: malloc failed in flood fill\n"); 
    find_player(&tmp);
    fill(tmp, tmp.player_x, tmp.player_y, tmp.map_height, tmp.map_width);
    if (!isallreached(game->map, tmp.map))
    {
        free_map(tmp.map);
        exit_error(game, "Error: Map has unreachable areas\n");        
    }
    free_map(tmp.map);
}
