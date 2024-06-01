/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:31:25 by dongjle2          #+#    #+#             */
/*   Updated: 2024/06/01 23:36:06 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "typedef.h"

t_complex	sum_complex(t_complex x, t_complex y)
{
	t_complex	ret;

	ret.real = x.real + y.real;
	ret.imagine = x.imagine + y.imagine;
	return (ret);
}

t_complex	square_complex(t_complex x)
{
	t_complex	ret;

	ret.real = x.real * x.real - x.imagine * x.imagine;
	ret.imagine = 2 * x.real * x.imagine;
	return (ret);
}

// double map(double unscaled_num, t_fractol *fractol, double old_max)
// {
// 	return ((fractol->x_max - fractol->x_min) * unscaled_num / old_max) + fractol->x_min;
// }

double map(double unscaled_num, \
		double new_min, double new_max, double old_min, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - old_min) / \
						(old_max - old_min) + new_min);
}

void	manipulate_pixels(t_fractol *fractol, t_linear_map *v, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	if (fractol->type == '1')
		config_mandel(fractol, v, &z, &c);
	else if (fractol->type == '2')
		config_julia(fractol, v, &z, &c);
	while (i < fractol->num_iter)
	{
		z = sum_complex(square_complex(z), c);
		if (4 < z.real * z.real + z.imagine * z.imagine)
		{
			mlx_put_pixel(fractol->g_img, x, y, \
						map(i, WHITE, BLACK, 0, fractol->num_iter));
			return ;
		}
		i++;
	}
	mlx_put_pixel(fractol->g_img, x, y, BLACK);
}
