/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 00:08:12 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/04/11 14:46:57 by ykhoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL
# define FRACTOL

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include "minilibx-linux/mlx.h"

# define DEFAULT_REAL -0.7
# define DEFAULT_IMAG 0.27015
# define WIDTH 800
# define HEIGHT 600

typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	double	zoom;
	double	offset_x; // Horizontal shift
	double	offset_y; // Vertical shift
	int		max_iter;
	double	min_real;
	double	max_real;
	double	min_imag;
	double	max_imag;
	double	c_real;
	double	c_img;
	int		fractal_type;
}	t_data;

int		ft_strcmp(char *s1, char *s2);
t_data	init_mlx_window(void);
double	ft_atof(const char *str, t_data *data);
void	julia(t_data *data, double real, double imag);
void	mandelbrot(t_data *data);
int		key_hook(int keycode, t_data *data);
int		close_window(t_data *data);
void	error_message(void);
int		m_zoom(int button, int x, int y, t_data *data);
int		failed(t_data *data);
int		get_color(int iter, int max_iter);
void	my_pixel_put(t_data *data, int x, int y, int color);

#endif