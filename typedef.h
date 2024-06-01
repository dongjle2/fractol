/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   typedef.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 18:32:34 by dongjle2          #+#    #+#             */
/*   Updated: 2024/06/01 23:32:48 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPEDEF_H
# define TYPEDEF_H
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_complex
{
	double real;
	double imagine;
}	t_complex;

typedef struct s_julia
{
	t_complex c;
}	t_julia;

typedef struct s_fractol
{
	mlx_t		*mlx;
	mlx_image_t	*g_img;
	t_julia		julia;
	char		type;
	char		update;
	int			num_iter;
	double		x_max;
	double		x_min;
	double		y_max;
	double		y_min;
	double		zoom;
	double		left_right;
	double		up_down;
}	t_fractol;

typedef struct s_linear_map
{
	double normalized_x;
	double normalized_y;
	double scaled_x;
	double scaled_y;
	double shifed_x;
	double shifed_y;
}	t_linear_map;

#endif