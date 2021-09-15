/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 23:38:06 by tshimoda          #+#    #+#             */
/*   Updated: 2021/08/26 15:17:24 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_isalpha(t_data *box)
{
	if (65 <= box->str[box->pos] && box->str[box->pos] <= 90)
		return (1);
	if (97 <= box->str[box->pos] && box->str[box->pos] <= 122)
		return (1);
	return (0);
}

int	ft_isdigit(t_data *box)
{
	return (48 <= box->str[box->pos] && box->str[box->pos] <= 57);
}

int	ft_is_uneven(int nb)
{
	if (nb % 2 != 0)
		return (1);
	return (0);
}

void	ft_is_signed(int n, t_data *box)
{
	if (ft_is_uneven(box->flag_combo / PLUS) && n >= 0)
		box->sum += write (1, "+", 1);
	else if (n < 0)
		box->sum += write (1, "-", 1);
	else if (ft_is_uneven(box->flag_combo / SPACE))
		box->sum += write (1, " ", 1);
	box->sign = 0;
}
