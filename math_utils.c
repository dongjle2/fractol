/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:31:25 by dongjle2          #+#    #+#             */
/*   Updated: 2024/06/12 19:11:03 by dongjle2         ###   ########.fr       */
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

t_complex	square_complex(t_complex x, const char type)
{
	t_complex	ret;

	ret.real = x.real * x.real - x.imagine * x.imagine;
	if (type == '3')
		ret.imagine = -2 * x.real * x.imagine;
	else
		ret.imagine = 2 * x.real * x.imagine;
	return (ret);
}

double	map(double unscaled_num, double old_min, double old_max)
{
	return ((BLACK - YELLOW) * (unscaled_num - old_min) / \
						(old_max - old_min) + YELLOW);
}

double	map2(double unscaled_num, double old_min, double old_max)
{
	return ((YELLOW - PINK) * (unscaled_num - old_min) / \
						(old_max - old_min) + PINK);
}

void	manipulate_pixels(t_fractol *f, t_linear_map *v, int x, int y)
{
	t_complex	z;
	t_complex	c;
	int			i;

	i = -1;
	if (f->type == '1' || f->type == '3')
		config_mandel(f, v, &z, &c);
	else if (f->type == '2')
		config_julia(f, v, &z, &c);
	while (++i < f->num_iter)
	{
		z = sum_complex(square_complex(z, f->type), c);
		if (4 < z.real * z.real + z.imagine * z.imagine)
		{
			if (f->color == 1)
				mlx_put_pixel(f->g_img, x, y, map(i, WHITE, f->num_iter));
			else
				mlx_put_pixel(f->g_img, x, y, map2(i, BLACK, f->num_iter));
			return ;
		}
	}
	if (f->color == 1)
		mlx_put_pixel(f->g_img, x, y, BLACK);
	else
		mlx_put_pixel(f->g_img, x, y, WHITE);
}
