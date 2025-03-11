/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:17:34 by mdinc             #+#    #+#             */
/*   Updated: 2025/03/11 14:17:34 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include <fcntl.h>
#include <unistd.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

static int	count_lines(char *filename)
{
	int		fd;
	char	*line;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (-1);
	count = 0;
	line = get_next_line(fd);
	while ((line))
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

int	get_line_len(char *line)
{
	int	len;

	len = 0;
	while (line[len] && line[len] != '\n' && line[len] != '\r')
		len++;
	return (len);
}

void	init_map_info(t_map_info *info, char *map)
{
	info->red = 1;
	info->counter1 = 0;
	info->counter2 = 0;
	info->counter3 = 0;
	info->j = 0;
	info->line_count = count_lines(map);
	info->first_line_len = 0;
	info->line = NULL;
	info->rest = NULL;
	info->fd = -1;
}
