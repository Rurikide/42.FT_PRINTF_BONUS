/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcollection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 23:31:00 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/14 08:29:10 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_putchar(char c)
{
	return (write (1, &c, 1));
}

int	ft_putstr(char *str, t_data *box)
{
	int	len;

	if (str == NULL)
	{
		box->width -= 6;
		while (box->width-- > 0)
			box->sum += (write (1, " ", 1));
		return (write (1, "(null)", 6));
	}
	len = ft_strlen(str);
	if (box->width > len)
	{
		box->width -= len;
		while (box->width)
		{
			box->sum += (write (1, " ", 1));
			box->width--;
		}
	}
	return (write (1, str, len));
}

int	ft_putstr_lp(char *str, t_data *box)
{
	int	len;
	int	bytes;

	bytes = 0;
	if (str == NULL)
		str = "(null)";
	if (box->precision <= 0 && !str)
		return (bytes);
	len = ft_strlen(str);
	if (box->minuspre == 1)
		box->precision = len;
	if (box->precision < len)
		len = box->precision;
	if (box->width > len)
		box->width -= len;
	else
		box->width = 0;
	bytes += write (1, str, len);
	while (box->width-- > 0)
		box->sum += (write (1, " ", 1));
	return (bytes);
}

int	ft_putstr_l(char *str, t_data *box)
{
	int	len;
	int	bytes;

	bytes = 0;
	if (str == NULL)
		str = "(null)";
	if (box->precision <= 0 && !str)
		return (bytes);
	len = ft_strlen(str);
	if (box->width > len)
		box->width -= len;
	else
		box->width = 0;
	bytes += write (1, str, len);
	while (box->width-- > 0)
		box->sum += (write (1, " ", 1));
	return (bytes);
}

int	ft_putstr_r(char *str, t_data *box)
{
	int	len;
	int	bytes;

	bytes = 0;
	if (str == NULL)
		str = "(null)";
	len = ft_strlen(str);
	if (box->precision <= 0 || !str)
	{
		while (box->width-- > 0)
			bytes += write (1, " ", 1);
		return (bytes);
	}
	if (box->precision < len)
		len = box->precision;
	if (box->width > len)
		box->width -= len;
	else
		box->width = 0;
	while (box->width--)
		bytes += write (1, " ", 1);
	bytes += write (1, str, len);
	return (bytes);
}
