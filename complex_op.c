/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex_op.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:31:25 by dongjle2          #+#    #+#             */
/*   Updated: 2024/05/19 22:11:58 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "typedef.h"
#include <stdio.h>

t_complex	sum_complex(t_complex x, t_complex y)
{
	t_complex	ret;

	ret.real = x.real + y.real;
	ret.imagine = x.imagine + y.imagine;
	return (ret);
}

t_complex	square_complex(t_complex x)
{
	t_complex ret;
	
	ret.real = x.real * x.real - x.imagine * x.imagine;
	ret.imagine = 2 * x.real * x.imagine;
	return (ret);
}


// double map(double unscaled_num, t_fractol *fractol, double old_max)
// {
// 	return ((fractol->x_max - fractol->x_min) * unscaled_num / old_max) + fractol->x_min;
// }

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
	return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

void	manipulate_pixels(t_fractol *fractol, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	z.real = 0;
	z.imagine = 0;
	c.real = map(x, fractol->x_min, fractol->x_max, 0, WIDTH) * fractol->zoom;
	c.imagine = map(y, fractol->y_min, fractol->y_max, 0, HEIGHT) * fractol->zoom;
	// printf("%d %d\n", x, y);
	while (i < NUM_ITER)
	{
		z = sum_complex(square_complex(z), c);
		if (4 < z.real * z.real + z.imagine * z.imagine)
		{
			mlx_put_pixel(fractol->g_img, x, y, map(i, BLACK, WHITE, 0, NUM_ITER));
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractol->g_img, x, y, WHITE);
}
