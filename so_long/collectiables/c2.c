/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c2.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 20:56:22 by mdinc             #+#    #+#             */
/*   Updated: 2025/03/11 20:56:22 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../ft_printf/ft_printf.h"

t_pos	find_player(char **map, int width, int height, int *exit_found)
{
	t_pos		player;
	int			i;
	t_map_row	row_info;

	player.x = -1;
	player.y = -1;
	i = 0;
	while (i < height)
	{
		if (!map[i])
		{
			i++;
			continue ;
		}
		row_info.row = map[i];
		row_info.y = i;
		row_info.width = width;
		row_info.player = &player;
		row_info.exit_found = exit_found;
		process_map_row(&row_info);
		i++;
	}
	return (player);
}

int	check_map_validity(t_pos player, int exit_found)
{
	if (player.x == -1)
	{
		ft_printf("Error: Invalid map\n");
		return (0);
	}
	if (!exit_found)
	{
		ft_printf("Error: Invalid map\n");
		return (0);
	}
	return (1);
}

static int	check_collectible_access(char cell, int visited_status)
{
	if (cell == 'C' && !visited_status)
	{
		ft_printf("Error: Invalid map\n");
		return (0);
	}
	return (1);
}

static int	check_exit_access(char cell, int visited_status)
{
	if (cell == 'E' && !visited_status)
	{
		ft_printf("Error: Invalid map\n");
		return (0);
	}
	return (1);
}

int	check_cell(char cell, int *visited, int *visited_exit, int index)
{
	if (!check_collectible_access(cell, visited[index]))
		return (0);
	if (!check_exit_access(cell, visited_exit[index]))
		return (0);
	return (1);
}
