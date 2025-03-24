/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 05:56:56 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/23 00:22:06 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_data	init_mlx_window(void)
{
    t_data data;

    // Initialize MLX
    data.mlx = mlx_init();
    if (!data.mlx)
    {
        write (2, "MLX initialization failed", 26);
        exit(EXIT_FAILURE);
    }

    // Create a new window
    data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "Fractol");
    if (!data.win)
    {
        write(2, "Window creation failed", 23);
        exit(EXIT_FAILURE);
    }

    // Create an image
    data.img = mlx_new_image(data.mlx, WIDTH, HEIGHT);
    if (!data.img)
    {
        write(2, "Image creation failed", 22);
        exit(EXIT_FAILURE);
    }

    // Get the image address for pixel manipulation
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

    // Set fractal parameters
    data.min_real = -2.0;
    data.max_real = 2.0;
    data.min_imag = -2.0;
    data.max_imag = 2.0;
    data.zoom = 1.0;
    data.max_iter = 50;  // Set a default number of iterations for Mandelbrot

    return data;
}

