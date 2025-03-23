/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collectiables.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 14:57:54 by mdinc             #+#    #+#             */
/*   Updated: 2025/03/24 00:39:00 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	flood_fill(t_flood *flood)
{
	t_flood	next;

	if (flood->x < 0 || flood->x >= flood->width || flood->y < 0
		|| flood->y >= flood->height || !flood->map || !flood->map[flood->y])
		return ;
	if (flood->map[flood->y][flood->x] == '1' || flood->visited[flood->y
		* flood->width + flood->x])
		return ;
	if (flood->check_collectibles && flood->map[flood->y][flood->x] == 'E')
		return ;
	flood->visited[flood->y * flood->width + flood->x] = 1;
	next = *flood;
	next.x = flood->x + 1;
	flood_fill(&next);
	next.x = flood->x - 1;
	flood_fill(&next);
	next.x = flood->x;
	next.y = flood->y + 1;
	flood_fill(&next);
	next.y = flood->y - 1;
	flood_fill(&next);
}

static void	check_cell_for_player(char cell, int x, int y, t_pos *player)
{
	if (cell == 'P')
	{
		player->x = x;
		player->y = y;
	}
}

static void	check_cell_for_exit(char cell, int *exit_found)
{
	if (cell == 'E')
		*exit_found = 1;
}

void	process_map_row(t_map_row *row_info)
{
	int	j;

	j = 0;
	while (j < row_info->width)
	{
		check_cell_for_player(row_info->row[j], j, row_info->y,
			row_info->player);
		check_cell_for_exit(row_info->row[j], row_info->exit_found);
		j++;
	}
}

int	check_collectibles(char **map, int width, int height)
{
	int		*visited;
	int		*visited_exit;
	int		exit_found;
	t_pos	player;
	t_flood	flood;

	if (!map || width <= 0 || height <= 0)
		return (0);
	visited = NULL;
	visited_exit = NULL;
	exit_found = 0;
	if (!init_visited_arrays(&visited, &visited_exit, width, height))
		return (0);
	player = find_player(map, width, height, &exit_found);
	if (!check_map_validity(player, exit_found))
	{
		cleanup_arrays(visited, visited_exit);
		return (0);
	}
	flood.x = player.x;
	flood.y = player.y;
	flood.height = height;
	ft_flood(&flood, map, width, visited);
	return (handle_flood_and_checks(&flood, map, visited, visited_exit));
}
