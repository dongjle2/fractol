/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:14:19 by dongjle2          #+#    #+#             */
/*   Updated: 2024/05/27 14:43:36 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
#define FRACTOL_H
#include "typedef.h"

#define WIDTH 800
#define HEIGHT 800
#define X_MAX 2
#define X_MIN -2
#define Y_MAX 2
#define Y_MIN -2
#define SCALING_X X_MAX - X_MIN
#define SCALING_Y Y_MAX - Y_MIN
#define BLACK 0x000000
#define WHITE 0xFFFFFF
#define NUM_ITER 420

t_complex	sum_complex(t_complex x, t_complex y);
t_complex	square_complex(t_complex x);
void		manipulate_pixels(t_fractol *fractol, t_linear_map *v, int x, int y);
void		rendering(t_fractol *fractol);
#endif