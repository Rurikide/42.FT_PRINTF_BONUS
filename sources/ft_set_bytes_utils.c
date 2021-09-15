/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_misc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 14:38:25 by tshimoda          #+#    #+#             */
/*   Updated: 2021/08/26 15:10:30 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_set_bytes(t_data *box, int nb_digit)
{
	if (box->precision > nb_digit)
		box->precision -= nb_digit;
	else
		box->precision = 0;
	if (box->width > box->precision + nb_digit)
		box->width -= box->precision + nb_digit;
	else
		box->width = 0;
}

void	ft_set_min_width(t_data *box, int nb_digit)
{
	if (box->width > nb_digit)
		box->width -= nb_digit;
	else
		box->width = 0;
}

void	ft_set_min_width2(t_data *box, int nb_digit)
{
	if (box->width > box->precision + nb_digit)
		box->width -= box->precision + nb_digit;
	else
		box->width = 0;
}

void	ft_set_max_precision(t_data *box, int nb_digit)
{
	if (box->precision > nb_digit)
		box->precision -= nb_digit;
	else
		box->precision = 0;
}
