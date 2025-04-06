/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:07:13 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/04/06 18:24:03 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main(int ac, char **av)
{
	t_data data;
	double real, imag;

    data = init_mlx_window();
	if (ac == 2)
    {
		if (!ft_strcmp(av[1], "mandelbrot"))
			mandelbrot(&data);
		else if (!ft_strcmp(av[1], "julia"))
			 julia(&data, DEFAULT_REAL, DEFAULT_IMAG);
		else 
			error_message();
	}
	else if(ac == 4)
	{
		if (!ft_strcmp(av[1], "julia"))
		{
			real = ft_atof(av[2]);
			imag = ft_atof(av[3]);
			julia(&data, real, imag);
		}
		else 
			error_message();
	}
	else 
		error_message();
	mlx_loop(data.mlx);
}