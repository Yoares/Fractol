/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelboard.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 02:29:56 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/23 01:36:09 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mlx_init_mande(t_data *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "mandelbrot");
	data->img = mlx_new_image(data->mlx, WIDTH, HEIGHT);
	data->addr = mlx_get_data_addr(data->mlx, &data->bits_per_pixel, &data->line_length, &data->endian);	
	data->zoom = 1.0;
    data->offset_x = 0.0;
    data->offset_y = 0.0;
    data->max_iter = 50;
}
void pixel_to_complex(int x, int y, double *real, double *imag, t_data *data)
{
	*real = (data->min_real) + ((double)x / 800) * (data->max_real - data->min_real);
	*imag = (data->min_imag) + ((double)x / 800) * (data->max_imag - data->min_imag);
}

void mandelbrot(t_data *data)
{
    
}


