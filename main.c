/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 17:19:59 by vshpilev          #+#    #+#             */
/*   Updated: 2024/11/26 17:20:01 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include </home/vshpilev/Documents/so_long/MLX42/include/MLX42/MLX42.h>
#include "so_long.h"

void game_loop(void *param)
{
    t_game *game = (t_game *)param;

    move_player(game); // Проверка движения игрока
}

int main(int argc, char **argv)
{
    t_game game;

    if (argc != 2)
        error_exit("Usage: ./so_long <map_file>");

    // Инициализация MLX
    game.mlx = mlx_init(800, 600, "so_long", true);
    if (!game.mlx)
        error_exit("Failed to initialize MLX");

    // Чтение карты
    game.map = read_map(argv[1]);
    validate_map(game.map);

    // Инициализация игры
    game.collectibles = count_collectibles(game.map);
    load_textures(&game);
    render_map(&game);

    // Установка игрового цикла
    mlx_loop_hook(game.mlx, game_loop, &game);

    // Запуск цикла MLX
    mlx_loop(game.mlx);

    // Очистка ресурсов
    mlx_terminate(game.mlx);
    return (0);
}




// #define WIDTH 1080
// #define HEIGHT 920

// int main(int argc, char **argv)
// {
//     if (argc != 2) // Проверка аргументов командной строки
//     {
//         printf("Usage: %s <map_file>\n", argv[0]);
//         return (1);
//     }

//     int rows, cols;
//     char **map = read_map(argv[1], &rows, &cols); // Читаем карту
//     if (!map) // Проверяем, удалось ли загрузить карту
//     {
//         printf("Error: Failed to load map\n");
//         return (1);
//     }

//     // Вывод карты для проверки
//     printf("Loaded map (%dx%d):\n", rows, cols);
//     int i = 0;
//     while (i < rows)
//     {
//         printf("%s", map[i]); // Строки карты уже содержат символы + \n
//         i++;
//     }

//     // Проверка на замкнутость карты
//     if (!is_map_closed(map, rows, cols)) // Функция is_map_closed из предыдущего ответа
//     {
//         printf("Error: Map is not closed by walls\n");
//         free_map(map, rows); // Освобождаем память карты
//         return (1);
//     }

//     // Проверка наличия необходимых элементов (P, E, C)
//     if (!validate_map_elements(map, rows, cols)) // Реализуй эту функцию
//     {
//         printf("Error: Map is missing required elements (P, E, or C)\n");
//         free_map(map, rows);
//         return (1);
//     }

//     // Здесь ты можешь продолжить работать с MiniLibX и отображением карты в окне
//     mlx_t *mlx = mlx_init(WIDTH, HEIGHT, "so_long", false);
//     if (!mlx)
//     {
//         printf("Error initializing MiniLibX\n");
//         free_map(map, rows);
//         return (1);
//     }

//         // Инициализация MiniLibX
//     mlx = mlx_init(WIDTH, HEIGHT, "so_long", false);
//     if (!mlx)
//     {
//         printf("Error initializing MiniLibX");
//         return (1);
//     }

//     // Загрузка текстуры из файла
//     mlx_texture_t *texture = mlx_load_png("/home/vshpilev/Documents/so_long/textures/flash.png");
//     if (!texture)
//     {
//         printf("Error loading texture");
//         mlx_terminate(mlx);
//         return (1);
//     }

//     // Создание изображения и копирование текстуры
//     mlx_image_t *image = mlx_new_image(mlx, texture->width, texture->height);
//     if (!image)
//     {
//         printf("Error creating image");
//         mlx_delete_texture(texture);
//         mlx_terminate(mlx);
//         return (1);
//     }

//     // Копируем пиксели текстуры в изображение
//     image = mlx_texture_to_image(mlx, texture);

//     // Освобождаем память текстуры, так как она больше не нужна
//     mlx_delete_texture(texture);

//     // Отображение изображения в окне
//     if (mlx_image_to_window(mlx, image, 100, 100) == -1)
//     {
//         printf("Error displaying image");
//         mlx_terminate(mlx);
//         return (1);
//     }

//     // Бесконечный цикл, чтобы окно не закрывалось
//     mlx_loop(mlx);

//     // Завершение работы
// 	mlx_terminate(mlx);
//     // Освобождение ресурсов
//     free_map(map, rows);
//     mlx_terminate(mlx);

//     return (0);
// }



// void free_map(char **map)
// {
//     if (!map)
//         return;

//     for (size_t i = 0; map[i]; i++) // Освобождаем каждую строку
//         free(map[i]);

//     free(map); // Освобождаем массив указателей
// }

// Глобальная переменная для изображения
/*
static mlx_image_t* image;

int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a) {
    return (r << 24 | g << 16 | b << 8 | a);
}

void ft_hook(void* param) {
    mlx_t* mlx = param;

    // Проверка клавиш для закрытия окна
    if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
        mlx_close_window(mlx);

    // Управление движением изображения
    if (mlx_is_key_down(mlx, MLX_KEY_UP))
        image->instances[0].y -= 15;
    if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
        image->instances[0].y += 15;
    if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
        image->instances[0].x -= 15;
    if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
        image->instances[0].x += 15;
}

*/
// void *mlx_init();
// void *mlx_new_window(void *mlx_ptr, int size_x, int size_y, char *title);

// int main()
// {
//     mlx_t* mlx;
//    // mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Flash game", true);
//     mlx = mlx_init(WIDTH, HEIGHT, "so_long", true);
//     //mlx_new_image(mlx, width, height);
//     mlx_loop(mlx);
//     return 0;
// }


// -----------------------------------------------------------------------------

// int main(void) {
//     mlx_t* mlx;
//     mlx_texture_t* texture;

//     // Инициализация MLX
//     if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true))) {
//         puts(mlx_strerror(mlx_errno));
//         return (EXIT_FAILURE);
//     }

//     // Загрузка текстуры из файла
//     texture = mlx_load_png("/home/vshpilev/Documents/so_long/textures/flash.png");
//     if (!texture) {
//         mlx_terminate(mlx);
//         puts("Failed to load texture");
//         return (EXIT_FAILURE);
//     }

//     // Преобразование текстуры в изображение
//     image = mlx_texture_to_image(mlx, texture);
//     if (!image) {
//         mlx_delete_texture(texture);
//         mlx_terminate(mlx);
//         puts("Failed to create image from texture");
//         return (EXIT_FAILURE);
//     }

//     // Освобождение текстуры (больше не нужна)
//     mlx_delete_texture(texture);

//     // Добавление изображения в окно
//     if (mlx_image_to_window(mlx, image, 100, 100) == -1) {
//         mlx_terminate(mlx);
//         puts(mlx_strerror(mlx_errno));
//         return (EXIT_FAILURE);
//     }

//     // Привязка обработчика событий для движения
//     mlx_loop_hook(mlx, ft_hook, mlx);

//     // Запуск цикла обработки событий
//     mlx_loop(mlx);
//     mlx_terminate(mlx);
//     return (EXIT_SUCCESS);
// }

