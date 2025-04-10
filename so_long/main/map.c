/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdinc <mdinc@student.42kocaeli.com.tr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/11 14:07:17 by mdinc             #+#    #+#             */
/*   Updated: 2025/03/11 14:07:17 by mdinc            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "ft_printf.h"

int	handle_collectible(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'C')
	{
		data->collectibles--;
		ft_printf("collectible: %d\n", data->collectibles);
		return (1);
	}
	return (0);
}

int	setup_map(t_data *data, char *map_path)
{
	data->map = read_map(map_path);
	if (!data->map)
		return (0);
	if (!check_collectibles(data->map, get_map_width(data->map),
			get_map_height(data->map)))
	{
		free_map(data->map);
		data->map = NULL;
		return (0);
	}
	check_valid_chars(data, get_map_height(data->map),
		get_map_width(data->map));
	data->collectibles = count_collectibles(data);
	return (1);
}

int	is_hidden_file(const char *ptr)
{
	char	*filename;
	int		len;

	filename = ft_strrchr(ptr, '/');
	if (filename)
		filename++;
	else
		filename = (char *)ptr;
	len = 0;
	while (filename[len])
		len++;
	if (len < 5)
		return (1);
	return (0);
}
