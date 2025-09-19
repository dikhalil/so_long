/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dikhalil <dikhalil@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 17:13:18 by dikhalil          #+#    #+#             */
/*   Updated: 2025/09/19 17:14:33 by dikhalil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int isrectangle(char **map)
{
    int len;
    int i;
    int j;

    i = 1;
    j = 0;
    len = ft_strlen(map[0]);
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

static int isenclosed(t_game *game)
{
	int i;
	int j;
	
	i = 1;
	j = 0;
	
	while (game->map[0][j])
		if (game->map[0][j] != '1' || game->map[game->map_height - 1][j++] != '1')
			return (0);
	while (i < game->map_height)
		if (game->map[i][0] != '1' || game->map[i++][game->map_width - 1] != '1')
			return (0);
    return (1);
}

static int isvalidchar(t_game *game)
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
void check_map(t_game *game)
{
	int i;

	i = 0;
    if (!isrectangle(game->map))
		exit_error(game, "Error: Map must be rectangle\n");
	if (!isenclosed(game))
		exit_error(game, "Error: Map must be enclosed/surrounded by walls\n");
	if (!isvalidchar(game))
		exit_error(game, "Error: Map must contain 1 exit, 1 starting position and at least 1 collectible\n");
}