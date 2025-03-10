/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:07:13 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/10 02:42:27 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <math.h>

// void my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
//     if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT) {
//         char *dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//         *(unsigned int *)dst = color;
//     }
// }

// void draw_square(t_data *data, int x, int y, int size)
// {
//     int i;
//     int j;

//     i = 0;
//     while (i < size) // Loop over rows
//     {
//         j = 0; // Reset `j` for each new row
//         while (j < size) // Loop over columns
//         {
//             my_mlx_pixel_put(data, x + j, y + i, COLOR); // Draw pixel
//             j++; // Move to next column
//         }
//         i++; // Move to next row
//     }
// }


// int main(void)
// {
//     t_data img;

//     img.mlx = mlx_init();
//     img.win = mlx_new_window(img.mlx, WIDTH, HEIGHT, "Square");
//     img.img = mlx_new_image(img.mlx, WIDTH, HEIGHT);
//     img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

//     draw_square(&img, START_X, START_Y, SQUARE_SIZE);

//     mlx_put_image_to_window(img.mlx, img.win, img.img, 0, 0);
//     mlx_loop(img.mlx);

//     return 0;
// }