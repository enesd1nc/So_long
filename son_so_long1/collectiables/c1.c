/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c1.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:51:51 by mdinc             #+#    #+#             */
/*   Updated: 2025/03/11 18:51:51 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	perform_checks(t_check_info *check)
{
	int	i;
	int	j;

	i = 0;
	while (i < check->height)
	{
		if (!check->map[i])
		{
			i++;
			continue ;
		}
		j = 0;
		while (j < check->width)
		{
			if (!check_cell(check->map[i][j], check->visited,
				check->visited_exit, i * check->width + j))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	init_visited_arrays(int **visited, int **visited_exit, int width,
		int height)
{
	*visited = ft_calloc(width * height, sizeof(int));
	*visited_exit = ft_calloc(width * height, sizeof(int));
	if (!(*visited) || !(*visited_exit))
	{
		free(*visited);
		free(*visited_exit);
		*visited = NULL;
		*visited_exit = NULL;
		return (0);
	}
	return (1);
}

static void	perform_flood_fills(t_flood *flood, int *visited_exit)
{
	flood_fill(flood);
	flood->visited = visited_exit;
	flood->check_collectibles = 0;
	flood_fill(flood);
}

void	cleanup_arrays(int *visited, int *visited_exit)
{
	free(visited);
	free(visited_exit);
}

int	handle_flood_and_checks(t_flood *flood, char **map, int *visited,
		int *visited_exit)
{
	t_check_info	check;
	int				result;

	perform_flood_fills(flood, visited_exit);
	check.map = map;
	check.visited = visited;
	check.visited_exit = visited_exit;
	check.width = flood->width;
	check.height = flood->height;
	result = perform_checks(&check);
	cleanup_arrays(visited, visited_exit);
	return (result);
}
