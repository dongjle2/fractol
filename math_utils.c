/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:31:25 by dongjle2          #+#    #+#             */
/*   Updated: 2024/06/11 17:29:09 by dongjle2         ###   ########.fr       */
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

t_complex	square_conju_complex(t_complex x)
{
	t_complex	ret;

	ret.real = x.real * x.real - x.imagine * x.imagine;
	ret.imagine = -2 * x.real * x.imagine;
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

void	manipulate_pixels(t_fractol *f, t_linear_map *v, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = 0;
	if (f->type == '1' || f->type == '3')
		config_mandel(f, v, &z, &c);
	else if (f->type == '2')
		config_julia(f, v, &z, &c);
	while (i < f->num_iter)
	{
		if (f->type == '3')
			z = sum_complex(square_conju_complex(z), c);
		else
			z = sum_complex(square_complex(z), c);
		if (4 < z.real * z.real + z.imagine * z.imagine)
		{
			if (f->color == 1)
				mlx_put_pixel(f->g_img, x, y, map(i, WHITE, BLACK, WHITE, f->num_iter));
			else
				mlx_put_pixel(f->g_img, x, y, map(i, BLACK, WHITE, BLACK, f->num_iter));
			return ;
		}
		i++;
	}
	if (f->color == 1)
		mlx_put_pixel(f->g_img, x, y, BLACK);
	else
		mlx_put_pixel(f->g_img, x, y, WHITE);

}
