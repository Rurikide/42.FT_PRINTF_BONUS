/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putcollection6.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/22 12:27:53 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/14 08:37:19 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	pexl(unsigned long long int n, t_data *box)
{
	int	nb_digit;
	int	bytes;

	box->sum += write (1, "0x", 2);
	bytes = ft_hexa(n);
	nb_digit = ft_nb_digit_ptr(((unsigned long long int) n)) + 2;
	if (box->width > nb_digit)
		box->width -= nb_digit;
	else
		box->width = 0;
	while (box->width-- > 0)
		box->sum += (write (1, " ", 1));
	return (bytes);
}

int	pexr(unsigned long long int n, t_data *box)
{
	int	nb_digit;
	int	bytes;

	nb_digit = ft_nb_digit_ptr(((unsigned long long int) n)) + 2;
	if (box->width > nb_digit)
		box->width -= nb_digit;
	else
		box->width = 0;
	while (box->width-- > 0)
		box->sum += (write (1, " ", 1));
	box->sum += write (1, "0x", 2);
	bytes = ft_hexa(n);
	return (bytes);
}
