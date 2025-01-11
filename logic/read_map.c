/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 14:30:27 by vshpilev          #+#    #+#             */
/*   Updated: 2024/12/18 14:30:29 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

static char	*remove_newline(char *line)
{
	int	len;

	if (!line)
		return (NULL);
	len = strlen(line);
	if (line[len - 1] == '\n')
		line[len - 1] = '\0';
	return (line);
}

int	count_lines(const char *file_path)
{
	int		fd;
	int		count;
	char	*line;

	count = 0;
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_exit(NULL, "Error: Failed to open map file.");
	line = get_next_line(fd);
	while (line)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	return (count);
}

static char	**read_file_lines(int fd, int line_count)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		error_exit(NULL, "Error: Memory allocation failed for map.");
	i = 0;
	while (i < line_count)
	{
		map[i] = remove_newline(get_next_line(fd));
		if (!map[i])
		{
			free_map(map);
			error_exit(NULL, "Error: Failed to read line from map file.");
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

char	**read_map(const char *file_path)
{
	int		fd;
	int		line_count;
	char	**map;

	line_count = count_lines(file_path);
	if (line_count == 0)
		error_exit(NULL, "Error: Empty map file.");
	fd = open(file_path, O_RDONLY);
	if (fd < 0)
		error_exit(NULL, "Error: Failed to open map file.");
	map = read_file_lines(fd, line_count);
	close(fd);
	return (map);
}
