/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 04:27:51 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/04/07 15:30:13 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while(s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return(s1[i] - s2[i]);
}
void error_message()
{
	write(2, "Error: Invalid input or initialization failed.\n", 48);
    write(2, "Usage: ./fractol [fractol_name]\n", 33);
    write(2, "Available fractals: mandelbrot, julia\n", 39);
    exit(1);
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		exit (0);
	}
	return (0);
}

int close_window(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    exit(0);
}

int failed(t_data *data)
{
    mlx_destroy_window(data->mlx, data->win);
    mlx_destroy_image(data->mlx ,data->img);
    mlx_destroy_display(data->mlx);
    free(data->mlx);
    error_message();
    exit(1);
}

double ft_atof(const char *str, t_data *data)
{
    double result = 0.0;
    double sign = 1.0;
    double divisor = 10.0;

    if (*str == '-') {
        sign = -1.0;
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        result = result * 10.0 + (*str - '0');
        str++;
    }

    if (*str == '.') {
        str++;
        while (*str >= '0' && *str <= '9') {
            result = result + (*str - '0') / divisor;
            divisor *= 10.0;
            str++;
        }
    }
    if(*str)
        failed(data);
    return result * sign;
}
