/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi_f.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dongjle2 <dongjle2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/13 16:22:07 by dongjle2          #+#    #+#             */
/*   Updated: 2024/06/01 23:04:30 by dongjle2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static	int	isspace(const int c);

int	ft_atoi(const char *str)
{
	int	sign;
	int	num;

	sign = 1;
	num = 0;
	while (isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while ('0' <= *str && *str <= '9')
		num = num * 10 + (*str++ - 48);
	return (sign * num);
}

double	ft_atof(const char *str)
{
	int		sign;
	double	integer;
	double	fraction;
	char	point;

	sign = 1;
	integer = 0;
	fraction = 1;
	point = 0;
	while (isspace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while ('0' <= *str && *str <= '9')
		integer = integer * 10 + (*str++ - '0');
	if (*str++ == '.')
	while ('0' <= *str && *str <= '9')
	{
		fraction /= 10;
		integer += fraction * (*str++ - '0');
	}
	return (sign * integer);
}

static	int	isspace(const int c)
{
	const char	*space;

	space = "\t\n\v\f\r ";
	while (*space)
	{
		if (c == *space++)
			return (1);
	}
	return (0);
}