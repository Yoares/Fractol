/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utile.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykhoussi <ykhoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 04:27:51 by ykhoussi          #+#    #+#             */
/*   Updated: 2025/03/20 07:13:05 by ykhoussi         ###   ########.fr       */
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
{}
double ft_atof(const char *str)
{
    double	(r),(f);
	int	s;

	r = 0.0;
	f = 0.0;
	s = 1;

	while(*str >= ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+') 
	{
        if (*str == '-')
            s = -1;
        str++;
    }
	while(*str >= '0' && *str <= '9')
	{
		r = r * 10 + (*str - 48);
		str++;
	}
	if (*str == '.')
	{
		while (*str >= ' ' || (*str >= 9 && *str <= 13))
			str++;
		while(*str >= '0' && *str <= '9')
		{
			r += (*str - 48) * f;
			f *= 0.1;
			str++; 
		}
	}
	return r * s;
}
