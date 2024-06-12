/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 00:14:19 by dongjle2          #+#    #+#             */
/*   Updated: 2024/06/12 19:10:26 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "typedef.h"
# include <stdlib.h>
# define WIDTH 900
# define HEIGHT 600
# define X_MAX 2
# define X_MIN -2
# define Y_MAX 2
# define Y_MIN -2
# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define YELLOW 0xFFFF40
# define PINK 0xFFC0C00
# define NUM_ITER 500
# define RESET "\033[0m"
# define RED "\033[31m"
# define GREEN "\033[32m"

t_complex	sum_complex(t_complex x, t_complex y);
t_complex	square_complex(t_complex x, const char type);
void		init_fractol(t_fractol *fractol);
void		manipulate_pixels(t_fractol *f, t_linear_map *v, int x, int y);
int			handle_input(t_fractol *fractol, int argc, char *argv[]);
void		rendering(void *param);
size_t		ft_strlen(const char *s);
int			ft_atoi(const char *str);
double		ft_atof(const char *str);
int			is_valid_str(const char *str);
void		display_error(void);
void		init_mandelbrot(t_fractol *fractol);
void		init_linear_map(t_linear_map *v);
void		config_julia(t_fractol *f, t_linear_map *v, t_complex *z, \
							t_complex *c);
void		config_mandel(t_fractol *f, t_linear_map *v, t_complex *z, \
							t_complex *c);
#endif
