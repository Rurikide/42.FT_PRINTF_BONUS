/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_norm_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 15:18:52 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/14 08:20:14 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_put_spaces(t_data *box)
{
	while (box->width--)
		box->sum += write (1, " ", 1);
}

void	ft_putnbr_firstchar(int n, t_data *box)
{
	if (ft_is_uneven(box->flag_combo / PLUS) && n > 0)
	{
		box->sum += write (1, "+", 1);
		box->width--;
	}
	else if (n < 0)
	{
		box->sum += write (1, "-", 1);
		box->width--;
	}
	else if (ft_is_uneven(box->flag_combo / SPACE))
	{
		box->sum += write (1, " ", 1);
		box->width--;
	}
}

void	ft_putnbr_r_core(int n, t_data *box)
{
	while (box->width > 0)
	{
		if (box->width == 1 && box->sign == 1)
		{
			ft_is_signed(n, box);
			box->width = 0;
		}
		else
			box->sum += (write (1, " ", 1));
		box->width--;
	}
}
