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

// Удаление символа '\n' из строки
static char *remove_newline(char *line)
{
    int len;

    if (!line)
        return (NULL);
    len = strlen(line);
    if (line[len - 1] == '\n')
        line[len - 1] = '\0';
    return (line);
}

static int count_lines(const char *file_path)
{
    int fd;
    int count = 0;
    char *line;

    fd = open(file_path, O_RDONLY);
    if (fd < 0)
        error_exit("Error: Failed to open map file.");
    while ((line = get_next_line(fd)))
    {
        count++;
        free(line);
    }
    close(fd);
    return (count);
}

char **read_map(const char *file_path)
{
    int fd;
    int line_count;
    char **map;
    int i;

    line_count = count_lines(file_path);
    if (line_count == 0)
        error_exit("Error: Empty map file.");

    map = (char **)malloc(sizeof(char *) * (line_count + 1));
    if (!map)
        error_exit("Error: Memory allocation failed for map.");

    fd = open(file_path, O_RDONLY);
    if (fd < 0)
        error_exit("Error: Failed to reopen map file.");

    i = 0;
    while (i < line_count)
    {
        map[i] = remove_newline(get_next_line(fd));
        if (!map[i])
            error_exit("Error: Failed to read line from map file.");
        i++;
    }
    map[i] = NULL; // Завершаем массив NULL
    close(fd);
    return (map);
}
