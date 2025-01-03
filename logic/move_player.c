/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vshpilev <vshpilev@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 17:06:31 by vshpilev          #+#    #+#             */
/*   Updated: 2024/12/18 17:06:33 by vshpilev         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static void check_and_move(t_game *game, int new_x, int new_y)
{
    // Игрок не может двигаться на стену
    if (game->map[new_y][new_x] == '1')
        return;

    // Если игрок собирает монету
    if (game->map[new_y][new_x] == 'C')
    {
        game->collectibles--;
        printf("%d coins \n", game->collectibles);
        game->map[new_y][new_x] = '0'; // Обновляем карту
        mlx_image_to_window(game->mlx, game->floor, new_x * 64, new_y * 64);
    }

    // Если игрок наступает на выход
    if (game->map[new_y][new_x] == 'E')
    {
        if (game->collectibles == 0)
        {
            game->game_won = 1;
            mlx_image_to_window(game->mlx, game->victory, 400, 300); // Отображаем экран победы
            printf("Game won in %d moves!\n", game->moves);
            return;
        }
        else
        {
            printf("You need to collect all collectibles first!\n");
            return; // Не позволяем игроку двигаться в выход
        }
    }

    // Обновляем старую позицию игрока
    mlx_image_to_window(game->mlx, game->floor, game->player_x * 64, game->player_y * 64);

    // Обновляем позицию игрока
    game->player_x = new_x;
    game->player_y = new_y;

    // Рисуем игрока на новой позиции
    mlx_image_to_window(game->mlx, game->player, new_x * 64, new_y * 64);

    // Увеличиваем счётчик ходов
    game->moves++;
    printf("Moves: %d\n", game->moves);
}



// Основная функция управления движением игрока
void move_player(t_game *game)
{
    if (game->key_pressed == 0) // Проверка нажатия клавиш
    {
        if (mlx_is_key_down(game->mlx, MLX_KEY_W))
        {
            check_and_move(game, game->player_x, game->player_y - 1); // Движение вверх
            game->key_pressed = 1;
        }
        else if (mlx_is_key_down(game->mlx, MLX_KEY_S))
        {
            check_and_move(game, game->player_x, game->player_y + 1); // Движение вниз
            game->key_pressed = 1;
        }
        else if (mlx_is_key_down(game->mlx, MLX_KEY_A))
        {
            check_and_move(game, game->player_x - 1, game->player_y); // Движение влево
            game->key_pressed = 1;
        }
        else if (mlx_is_key_down(game->mlx, MLX_KEY_D))
        {
            check_and_move(game, game->player_x + 1, game->player_y); // Движение вправо
            game->key_pressed = 1;
        }
    }
    else if (!mlx_is_key_down(game->mlx, MLX_KEY_W) &&
             !mlx_is_key_down(game->mlx, MLX_KEY_S) &&
             !mlx_is_key_down(game->mlx, MLX_KEY_A) &&
             !mlx_is_key_down(game->mlx, MLX_KEY_D))
    {
        game->key_pressed = 0; // Сбрасываем состояние клавиши
    }
}



