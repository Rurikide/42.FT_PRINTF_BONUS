/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_category_is2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 22:56:35 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/18 08:22:45 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	category_is_unsign(t_data *box)
{
	if (ft_is_uneven(box->flag_combo / DASH))
		box->sum += ft_unsl((unsigned int)va_arg(box->list, unsigned int), box);
	else if (ft_is_uneven(box->flag_combo / ZERO) && \
			!ft_is_uneven(box->flag_combo / PRECISION))
		box->sum += ft_unsz((unsigned int)va_arg(box->list, unsigned int), box);
	else
		box->sum += ft_unsr((unsigned int)va_arg(box->list, unsigned int), box);
}

void	category_is_hexa(t_data *box)
{
	if (ft_is_uneven(box->flag_combo / DASH))
		box->sum += ft_hexa_l((unsigned int)va_arg(box->list, int), box);
	else if (ft_is_uneven(box->flag_combo / ZERO) && \
			!ft_is_uneven(box->flag_combo / PRECISION))
		box->sum += ft_hexa_z((unsigned int)va_arg(box->list, int), box);
	else
		box->sum += ft_hexa_r((unsigned int)va_arg(box->list, int), box);
}

void	category_is_hexa_up(t_data *box)
{
	if (ft_is_uneven(box->flag_combo / DASH))
		box->sum += ft_hexa_ul((unsigned int)va_arg(box->list, int), box);
	else if (ft_is_uneven(box->flag_combo / ZERO) && \
			!ft_is_uneven(box->flag_combo / PRECISION))
		box->sum += ft_hexa_uz((unsigned int)va_arg(box->list, int), box);
	else
		box->sum += ft_hexa_ur((unsigned int)va_arg(box->list, int), box);
}

void	category_is_hexa_ptr(t_data *box)
{
	int	i;

	i = 0;
	if (ft_is_uneven(box->flag_combo / DASH))
		i = pexl((unsigned long long int)va_arg(box->list, long long int), box);
	else
		i = pexr((unsigned long long int)va_arg(box->list, long long int), box);
	box->sum += i;
}
