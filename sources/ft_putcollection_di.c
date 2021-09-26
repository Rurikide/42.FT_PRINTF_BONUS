/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcollection_di.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 22:50:19 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/26 13:00:59 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr(int n)
{
	static int	bytes;

	bytes = 0;
	if (n < 0 && n / 10 == 0)
		bytes += ft_putchar('-');
	if (n / 10 != 0)
		ft_putnbr(n / 10);
	if (n % 10 < 0)
		bytes += ft_putchar(-(n % 10) + '0');
	else
		bytes += ft_putchar((n % 10) + '0');
	return (bytes);
}

int	ft_putnbr_left(int n, t_data *box)
{
	int	nb_digit;
	int	bytes;

	nb_digit = ft_nb_digit(n);
	if (box->precision == 0 && n == 0)
	{
		ft_put_spaces(box);
		return (0);
	}
	if (box->minuspre == 1)
		box->precision = 0;
	ft_set_bytes(box, nb_digit);
	if (n < 0)
		box->width--;
	ft_is_signed(n, box);
	while (box->precision-- > 0)
		box->sum += (write (1, "0", 1));
	bytes = ft_putnbr_dashed(n);
	while (box->width-- > 0)
		box->sum += (write (1, " ", 1));
	return (bytes);
}

int	ft_putnbr_zero(int n, t_data *box)
{
	int	nb_digit;
	int	bytes;

	nb_digit = ft_nb_digit(n);
	if (n < 0 || (n > 0 && ft_is_uneven(box->flag_combo / PLUS)))
		box->sign = 1;
	ft_set_min_width(box, nb_digit);
	ft_putnbr_firstchar(n, box);
	while (box->width > 0)
	{
		box->sum += (write (1, "0", 1));
		box->width--;
	}
	bytes = ft_putnbr_dashed(n);
	return (bytes);
}

int	ft_putnbr_right(int n, t_data *box)
{
	int	nb_digit;
	int	bytes;

	box->sign = 0;
	nb_digit = ft_nb_digit(n);
	if (n < 0 || (n > 0 && ft_is_uneven(box->flag_combo / PLUS)))
		box->sign = 1;
	if (box->precision == 0 && n == 0)
	{
		ft_put_spaces(box);
		return (0);
	}
	ft_set_max_precision(box, nb_digit);
	if (box->width <= box->precision + nb_digit)
		ft_is_signed(n, box);
	ft_set_min_width2(box, nb_digit);
	ft_putnbr_r_core(n, box);
	while (box->precision--)
		box->sum += (write (1, "0", 1));
	bytes = ft_putnbr_dashed(n);
	return (bytes);
}
