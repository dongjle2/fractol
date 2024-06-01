/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 23:39:41 by dongjle2          #+#    #+#             */
/*   Updated: 2024/06/01 23:10:41 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MLX42/MLX42.h"
#include "fractol.h"
#include "typedef.h"
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_fractol	*fractol;

	if (!param)
		keydata.key = 0;
	fractol = (t_fractol *)param;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fractol->mlx);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_P))
		mlx_delete_image(fractol->mlx, fractol->g_img);
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_RIGHT))
		fractol->left_right += fractol->zoom * 0.25;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_LEFT))
		fractol->left_right -= fractol->zoom * 0.25;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_UP))
		fractol->up_down -= fractol->zoom * 0.25;
	if (mlx_is_key_down(fractol->mlx, MLX_KEY_DOWN))
		fractol->up_down += fractol->zoom * 0.25;
	fractol->update = 1;
	rendering(fractol);
}

void	my_scrollhook(double xdelta, double ydelta, void *param)
{
	t_fractol	*fractol;

	fractol = (t_fractol *)param;
	if (0 < ydelta || 0 < xdelta)
		fractol->zoom *= 0.9;
	else if (ydelta < 0)
		fractol->zoom *= 1.1;
	fractol->update = 1;
	rendering(fractol);
}

void	rendering(void *param)
{
	t_linear_map	v;
	t_fractol		*fractol;
	int				x;
	int				y;

	fractol = (t_fractol *)param;
	if (fractol->update == 0)
		return ;
	x = -1;
	while (++x < (int)fractol->g_img->width)
	{
		v.normalized_x = (double)x / WIDTH;
		v.shifed_x = fractol->x_min + \
					(fractol->x_max - fractol->x_min) * v.normalized_x;
		y = -1;
		while (++y < (int)fractol->g_img->height)
		{
			v.normalized_y = (double)y / HEIGHT;
			v.shifed_y = fractol->y_min + \
						(fractol->y_max - fractol->y_min) * v.normalized_y;
			manipulate_pixels(fractol, &v, x, y);
		}
	}
	fractol->update = 0;
}

int		handle_input(t_fractol *fractol, int argc, char *argv[])
{
	int	argv1_atoi;

	argv1_atoi = ft_atoi(argv[1]);
	if (argv1_atoi != 1 && argv1_atoi != 2)
		return (1);
	if (!((argv1_atoi == 1 && argc == 2) || (argv1_atoi == 2 && argc == 4)))
		return (1);
	if (argv1_atoi == 2)
	{
		if (!(is_valid_str(argv[2]) == 0 || is_valid_str(argv[3]) == 0))
			return (1);
	}
	if (argv1_atoi == 1)
		fractol->type = '1';
	else if (argv1_atoi == 2)
	{
		fractol->type = '2';
		fractol->julia.c.real = ft_atof(argv[2]);
		fractol->julia.c.imagine = ft_atof(argv[3]);
	}
	return (0);
}

int32_t	main(int argc, char *argv[])
{
	t_fractol	*fractol;
	t_fractol	fractal;

	if (!(argc == 2 || argc == 4))
	{
		display_error();
		return (0);
	}
	fractol = &fractal;
	if (handle_input(fractol, argc, argv) == 1)
	{
		display_error();
		return (1);
	}
	init_fractol(fractol);
	mlx_loop_hook(fractol->mlx, rendering, (void *)fractol);
	mlx_image_to_window(fractol->mlx, fractol->g_img, 0, 0);
	mlx_scroll_hook(fractol->mlx, &my_scrollhook, (void *)fractol);
	mlx_key_hook(fractol->mlx, &my_keyhook, (void *)fractol);
	mlx_loop(fractol->mlx);
	mlx_terminate(fractol->mlx);
	return (EXIT_SUCCESS);
}
