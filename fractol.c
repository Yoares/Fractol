/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:07:13 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/04/07 16:03:56 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_data data;
	double real, imag;


	if (ac == 2)
    {
		if (!ft_strcmp(av[1], "mandelbrot"))
			{
				data = init_mlx_window();
				data.fractal_type = 0;
				mandelbrot(&data);
			}
		else if (!ft_strcmp(av[1], "julia"))
		{
			data = init_mlx_window();
			data.fractal_type = 1;
			julia(&data, DEFAULT_REAL, DEFAULT_IMAG);
		}
		else 
			error_message();
	}
	else if(ac == 4)
	{
		if (!ft_strcmp(av[1], "julia"))
		{
			data = init_mlx_window();
			real = ft_atof(av[2]);
			imag = ft_atof(av[3]);
			printf("Real: %lf, Imag: %lf\n", real, imag);
			julia(&data, real, imag);
		}
		else 
			error_message();
	}
	else 
		error_message();
	mlx_key_hook(data.win, key_hook, &data);
	mlx_hook(data.win, 17, 0, close_window, &data);
	mlx_mouse_hook(data.win, m_zoom, &data);
	mlx_loop(data.mlx);
}
