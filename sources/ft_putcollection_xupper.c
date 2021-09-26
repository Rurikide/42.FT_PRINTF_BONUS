/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcollectionup_xupper.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 19:29:03 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/26 13:01:46 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_hexa_ul(unsigned int n, t_data *box)
{
	int	nb_digit;
	int	bytes;

	nb_digit = ft_nb_digit_x(((unsigned int) n));
	if (ft_is_uneven(box->flag_combo / POUND) && n != 0)
		box->sum += write (1, "0X", 2);
	if (box->precision == 0 && n == 0)
	{
		ft_put_spaces(box);
		return (0);
	}
	ft_set_bytes(box, nb_digit);
	while (box->precision-- > 0)
		box->sum += (write (1, "0", 1));
	bytes = ft_hexa_up(n);
	while (box->width-- > 0)
		box->sum += (write (1, " ", 1));
	return (bytes);
}

int	ft_hexa_uz(unsigned int n, t_data *box)
{
	int	nb_digit;
	int	bytes;

	nb_digit = ft_nb_digit_x(((unsigned int) n));
	if (box->width > nb_digit)
		box->width -= nb_digit;
	else
		box->width = 0;
	if (ft_is_uneven(box->flag_combo / SPACE))
	{
		box->sum += write (1, " ", 1);
		box->width--;
	}
	if (ft_is_uneven(box->flag_combo / POUND) && n != 0)
		box->sum += write (1, "0X", 2);
	while (box->width > 0)
	{
		box->sum += (write (1, "0", 1));
		box->width--;
	}
	bytes = ft_hexa_up(n);
	return (bytes);
}

int	ft_hexa_ur(unsigned int n, t_data *box)
{
	int	nb_digit;
	int	bytes;

	nb_digit = ft_nb_digit_x(((unsigned int) n));
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
	while (box->width > 0)
	{
		box->sum += (write (1, " ", 1));
		box->width--;
	}
	if (ft_is_uneven(box->flag_combo / POUND) && n != 0)
		box->sum += write (1, "0X", 2);
	while (box->precision--)
		box->sum += (write (1, "0", 1));
	bytes = ft_hexa_up(n);
	return (bytes);
}

int	ft_hexa_up(unsigned long long int nb)
{
	int		bytes;
	char	hexa[100];
	char	*base;
	int		i;

	i = 0;
	if (nb == 0)
		return (i += ft_putchar('0'));
	base = "0123456789ABCDEF";
	while (nb != 0)
	{
		bytes = nb % 16;
		hexa[i] = base[bytes];
		i++;
		nb = nb / 16;
	}
	bytes = 0;
	while (i-- > 0)
		bytes += ft_putchar(hexa[i]);
	return (bytes);
}
