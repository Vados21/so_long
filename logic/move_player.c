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
    if (game->map[new_y][new_x] == '1') // Стена
        return;

    if (game->map[new_y][new_x] == 'C') // Собираем пиццу
    {
        game->collectibles--;
        game->map[new_y][new_x] = '0'; // Убираем пиццу с карты
        mlx_image_to_window(game->mlx, game->floor, new_x * 64, new_y * 64); // Перерисовываем пол
    }

    if (game->map[new_y][new_x] == 'E') // Если игрок наступает на выход
    {
        if (game->collectibles == 0) // Все пиццы собраны
        {
            // Устанавливаем флаг победы
            game->game_won = 1;

            // Отображаем изображение победы
            mlx_image_to_window(game->mlx, game->victory, 400, 300); // Центр окна
            return;
        }
        else
        {
            return; // Выход остаётся видимым
        }
    }

    // Перерисовываем текущую клетку пола перед перемещением игрока
    mlx_image_to_window(game->mlx, game->floor, game->player_x * 64, game->player_y * 64);

    // Обновляем позицию игрока
    game->player_x = new_x;
    game->player_y = new_y;
    mlx_image_to_window(game->mlx, game->player, new_x * 64, new_y * 64);

    // Увеличиваем счётчик движений
    game->moves++;
    printf("Moves: %d\n", game->moves);
}







void move_player(t_game *game)
{
    if (game->key_pressed == 0) // Разрешаем движение только один раз за нажатие
    {
        if (mlx_is_key_down(game->mlx, MLX_KEY_W)) // Вверх
        {
            check_and_move(game, game->player_x, game->player_y - 1);
            game->key_pressed = 1;
        }
        else if (mlx_is_key_down(game->mlx, MLX_KEY_S)) // Вниз
        {
            check_and_move(game, game->player_x, game->player_y + 1);
            game->key_pressed = 1;
        }
        else if (mlx_is_key_down(game->mlx, MLX_KEY_A)) // Влево
        {
            check_and_move(game, game->player_x - 1, game->player_y);
            game->key_pressed = 1;
        }
        else if (mlx_is_key_down(game->mlx, MLX_KEY_D)) // Вправо
        {
            check_and_move(game, game->player_x + 1, game->player_y);
            game->key_pressed = 1;
        }
    }
    else if (!mlx_is_key_down(game->mlx, MLX_KEY_W) &&
             !mlx_is_key_down(game->mlx, MLX_KEY_S) &&
             !mlx_is_key_down(game->mlx, MLX_KEY_A) &&
             !mlx_is_key_down(game->mlx, MLX_KEY_D))
    {
        game->key_pressed = 0; // Сбрасываем флаг, если клавиша отпущена
    }
}


