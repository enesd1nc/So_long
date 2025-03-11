/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/08 11:14:06 by mdinc             #+#    #+#             */
/*   Updated: 2025/03/11 22:56:08 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../get_next_line/get_next_line.h"
#include "../so_long.h"
#include <fcntl.h>
#include "../ft_printf/ft_printf.h"
#include <stdlib.h>
#include <unistd.h>

static int	initialize_map_reading(t_map_info *info, char *map)
{
	init_map_info(info, map);
	if (info->line_count <= 0)
	{
		ft_printf("Invalid Map\n");
		return (0);
	}
	info->fd = open(map, O_RDONLY);
	if (info->fd < 0)
		return (0);
	info->rest = allocate_map(info->line_count);
	if (!info->rest)
	{
		close(info->fd);
		return (0);
	}
	info->line = get_next_line(info->fd);
	if (!info->line)
	{
		free(info->rest);
		close(info->fd);
		ft_printf("Invalid Map\n");
		return (0);
	}
	info->first_line_len = get_line_len(info->line);
	return (1);
}

static int	handle_line_allocation_error(char *line_ptr, char *line, int fd)
{
	if (!line_ptr)
	{
		free(line);
		close(fd);
		return (1);
	}
	return (0);
}

static void	process_line_cleanup(t_map_info *info, int k)
{
	info->rest[info->j][k] = '\0';
	free(info->line);
	info->line = get_next_line(info->fd);
	info->j++;
}

static void	process_line(t_map_info *info, int k)
{
	while (k < info->first_line_len)
	{
		if ((info->j == 0 || info->j == info->line_count - 1)
			&& info->line[k] != '1')
		{
			info->red = -1;
			break ;
		}
		if ((k == 0 || k == info->first_line_len - 1) && info->line[k] != '1')
		{
			info->red = -1;
			break ;
		}
		info->rest[info->j][k] = info->line[k];
		count_map_chars(info->line[k], info);
		k++;
	}
	process_line_cleanup(info, k);
}

char	**read_map(char *map)
{
	t_map_info	info;
	int			current_len;

	if (!initialize_map_reading(&info, map))
		return (NULL);
	while (info.line && info.j < info.line_count)
	{
		current_len = get_line_len(info.line);
		if (current_len != info.first_line_len)
			info.red = -1;
		info.rest[info.j] = allocate_line(info.first_line_len);
		if (handle_line_allocation_error(info.rest[info.j], info.line, info.fd))
		{
			free_map(info.rest);
			return (NULL);
		}
		process_line(&info, 0);
	}
	info.rest[info.j] = NULL;
	if (!check_map_validity_read(info, info.rest))
		return (NULL);
	close(info.fd);
	return (info.rest);
}
