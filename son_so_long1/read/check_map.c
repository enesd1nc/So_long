/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 18:12:15 by mdinc             #+#    #+#             */
/*   Updated: 2025/03/11 18:12:15 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../ft_printf/ft_printf.h"
#include <unistd.h>

int	check_map_validity_read(t_map_info info, char **map)
{
	if (info.j != info.line_count || info.counter1 != 1 || info.counter2 != 1
		|| info.counter3 < 1 || info.red < 0)
	{
		free_map(map);
		close(info.fd);
		ft_printf("Error: Invalid map\n");
		return (0);
	}
	return (1);
}

void	count_map_chars(char c, t_map_info *info)
{
	if (c == 'E')
		info->counter1++;
	if (c == 'P')
		info->counter2++;
	if (c == 'C')
		info->counter3++;
}

char	**allocate_map(int line_count)
{
	char	**map;

	map = (char **)ft_calloc((line_count + 1), sizeof(char *));
	if (!map)
		return (NULL);
	return (map);
}

char	*allocate_line(int line_len)
{
	char	*line;

	line = (char *)ft_calloc(line_len + 1, sizeof(char));
	return (line);
}
