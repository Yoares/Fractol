/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 06:40:58 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/04/07 14:43:36 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	julia_iter(double z_real, double z_img, double c_real, double c_img, int max_iter)
{
	int	iter;
	double tmp;

	iter = 0;
	while ((z_real * z_real + z_img * z_img < 4) && iter < max_iter)
	{
		tmp = z_real * z_real - z_img * z_img + c_real;
		z_img = 2 * z_real * z_img + c_img;
        z_real = tmp;
        iter++;
	}
	return (iter);
}

void julia(t_data *data, double real, double imag)
{
	int x, y, iter, color;
    double z_real, z_imag;	
    
	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < WIDTH)
		{
			pixel_to_complex(x, y, &z_real, &z_imag, data);
			iter = julia_iter(z_real, z_imag, real, imag, data->max_iter);
            if (iter == data->max_iter)
                color = 0x000000;
            else
                color = iter * 0x0F0F0F;

            my_mlx_pixel_put(data, x, y, color);				
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(data->mlx, data->win, data->img, 0, 0);
}