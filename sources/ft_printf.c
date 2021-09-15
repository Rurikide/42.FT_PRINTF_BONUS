/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 15:01:19 by tshimoda          #+#    #+#             */
/*   Updated: 2021/08/12 18:05:03 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_scan_init(t_data *box)
{
	ft_flag_scanner(box);
	ft_width_scanner(box);
	ft_precision_scanner(box);
	ft_category_scanner(box);
}

void	ft_parsef(t_data *box)
{
	void	(*category_is[9])(t_data *);

	category_is[0] = &category_is_char;
	category_is[1] = &category_is_string;
	category_is[2] = &category_is_hexa_ptr;
	category_is[3] = &category_is_decint;
	category_is[4] = &category_is_decint;
	category_is[5] = &category_is_unsign;
	category_is[6] = &category_is_hexa;
	category_is[7] = &category_is_hexa_up;
	category_is[8] = &category_is_modulo;
	box->vernier = 0;
	while (box->str[box->pos])
	{
		if (box->str[box->pos] == '%')
		{
			box->pos++;
			ft_scan_init(box);
			category_is[box->vernier](box);
			box->vernier = 0;
		}
		else
			box->sum += ft_putchar(box->str[box->pos]);
		box->pos++;
	}
}

int	ft_printf(const char *str, ...)
{
	t_data	box;

	va_start(box.list, str);
	box.str = str;
	box.pos = 0;
	box.sum = 0;
	ft_parsef(&box);
	va_end(box.list);
	return (box.sum);
}
