/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_category_is.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 22:19:24 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/14 08:33:12 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	category_is_char(t_data *box)
{
	if (ft_is_uneven(box->flag_combo / DASH))
	{
		box->sum += ft_putchar((char)va_arg(box->list, int));
		box->width--;
		while (box->width-- > 0)
			box->sum += (write (1, " ", 1));
	}
	else if (box->width == 1)
		box->sum += ft_putchar((char)va_arg(box->list, int));
	else
	{
		while (box->width-- > 1)
			box->sum += (write (1, " ", 1));
		box->sum += ft_putchar((char)va_arg(box->list, int));
		box->width = 0;
	}
}

void	category_is_string(t_data *box)
{
	if (ft_is_uneven(box->flag_combo / DASH) && \
		ft_is_uneven(box->flag_combo / PRECISION))
	{
		box->sum += ft_putstr_lp((char *)va_arg(box->list, char *), box);
		while (box->width-- > 0)
			box->sum += (write (1, " ", 1));
	}
	else if (ft_is_uneven(box->flag_combo / DASH))
	{
		box->sum += ft_putstr_l((char *)va_arg(box->list, char *), box);
		while (box->width-- > 0)
			box->sum += (write (1, " ", 1));
	}
	else if (ft_is_uneven(box->flag_combo / PRECISION))
		box->sum += ft_putstr_r((char *)va_arg(box->list, char *), box);
	else
		box->sum += ft_putstr((char *)va_arg(box->list, char *), box);
}

void	category_is_decint(t_data *box)
{
	if (ft_is_uneven(box->flag_combo / DASH))
		box->sum += ft_putnbr_left(va_arg(box->list, int), box);
	else if (ft_is_uneven(box->flag_combo / ZERO) && \
			!ft_is_uneven(box->flag_combo / PRECISION))
		box->sum += ft_putnbr_zero(va_arg(box->list, int), box);
	else
		box->sum += ft_putnbr_right(va_arg(box->list, int), box);
}

void	category_is_modulo(t_data *box)
{
	if (ft_is_uneven(box->flag_combo / DASH))
	{
		box->sum += (write(1, "%", 1));
		box->width--;
		while (box->width-- > 0)
			box->sum += (write (1, " ", 1));
	}
	else if (ft_is_uneven(box->flag_combo / ZERO))
	{
		while (box->width-- > 1)
			box->sum += (write (1, "0", 1));
		box->sum += (write(1, "%", 1));
	}
	else
	{
		while (box->width-- > 1)
			box->sum += (write (1, " ", 1));
		box->sum += (write(1, "%", 1));
	}
}
