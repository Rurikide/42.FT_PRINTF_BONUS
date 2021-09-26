/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcollection_u.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:50:26 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/26 12:59:25 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putnbr_dashed(int n)
{
	static int	bytes;

	bytes = 0;
	if (n / 10 != 0)
		ft_putnbr_dashed(n / 10);
	if (n % 10 < 0)
		bytes += ft_putchar(-(n % 10) + '0');
	else
		bytes += ft_putchar((n % 10) + '0');
	return (bytes);
}

int	ft_putunsign(unsigned int n)
{
	static int	bytes;
	int			i;
	char		deci[25];
	long		nb;

	i = 0;
	bytes = 0;
	nb = n;
	if (nb == 0)
		bytes += ft_putchar('0');
	while (nb > 0)
	{
		deci[i] = nb % 10 + 48;
		nb = nb / 10;
		i++;
	}
	i--;
	while (i >= 0)
		bytes += ft_putchar(deci[i--]);
	return (bytes);
}

int	ft_unsl(unsigned int n, t_data *box)
{
	int	nb_digit;
	int	bytes;

	nb_digit = ft_nb_digit_u(((unsigned int) n));
	if (box->precision == 0 && n == 0)
	{
		ft_put_spaces(box);
		return (0);
	}
	ft_set_bytes(box, nb_digit);
	while (box->precision-- > 0)
		box->sum += (write (1, "0", 1));
	bytes = ft_putunsign(n);
	while (box->width-- > 0)
		box->sum += (write (1, " ", 1));
	return (bytes);
}

int	ft_unsz(unsigned int n, t_data *box)
{
	int	nb_digit;
	int	bytes;

	nb_digit = ft_nb_digit_u(((unsigned int) n));
	ft_set_bytes(box, nb_digit);
	if (ft_is_uneven(box->flag_combo / SPACE))
	{
		box->sum += write (1, " ", 1);
		box->width--;
	}
	while (box->width > 0)
	{
		box->sum += (write (1, "0", 1));
		box->width--;
	}
	bytes = ft_putunsign(n);
	return (bytes);
}

int	ft_unsr(unsigned int n, t_data *box)
{
	int	nb_digit;
	int	bytes;

	nb_digit = ft_nb_digit_u(((unsigned int) n));
	if (box->precision == 0 && n == 0)
	{
		ft_put_spaces(box);
		return (0);
	}
	if (n < 0)
	{
		box->width = 0;
	}
	ft_set_bytes(box, nb_digit);
	ft_put_spaces(box);
	while (box->precision--)
		box->sum += (write (1, "0", 1));
	bytes = ft_putunsign(n);
	return (bytes);
}
