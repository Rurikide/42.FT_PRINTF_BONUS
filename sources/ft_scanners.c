/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanners.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 23:06:43 by tshimoda          #+#    #+#             */
/*   Updated: 2021/08/26 14:17:59 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	ft_flag_scanner(t_data *box)
{
	int		i;
	int		*flag_table;
	char	*flag_symbol;

	i = 0;
	box->flag_combo = 0;
	flag_table = (int [6]){NONE, DASH, ZERO, SPACE, PLUS, POUND};
	flag_symbol = (char [7]){0, '-', '0', ' ', '+', '#'};
	while (box->str[box->pos] != '*' && box->str[box->pos] != '.' \
	&& !ft_isalpha(box) && box->str[box->pos] != '%' && box->str[box->pos])
	{
		if ('1' <= box->str[box->pos] && box->str[box->pos] <= '9')
			break ;
		while (box->str[box->pos] == flag_symbol[i])
		{
			box->flag_combo |= flag_table[i];
			box->pos++;
			i = 0;
			break ;
		}		
		i++;
	}
}

void	ft_width_scanner(t_data *box)
{
	box->width = 0;
	if (box->str[box->pos] == '*')
	{
		box->width = va_arg(box->list, int);
		if (box->width < 0)
		{
			if (box->width == -2147483648)
				box->width += 1;
			box->width *= -1;
			box->flag_combo |= DASH;
		}
		box->pos++;
	}
	else if (box->str[box->pos] == '.' || ft_isalpha(box))
		box->width = 0;
	else
	{
		while (ft_isdigit(box) && box->str[box->pos])
		{
			box->width *= 10;
			box->width += (int)box->str[box->pos] - 48;
			box->pos++;
		}
	}
}

void	ft_precision_scanner(t_data *box)
{
	box->precision = -1;
	if (box->str[box->pos] != '.')
		return ;
	box->precision = 0;
	box->minuspre = 0;
	box->flag_combo |= PRECISION;
	box->pos++;
	if (box->str[box->pos] == 0)
		return ;
	if (box->str[box->pos] == '*')
		ft_precision_star(box);
	while (ft_isdigit(box) && box->str[box->pos])
	{
		box->precision *= 10;
		box->precision += (int)box->str[box->pos] - 48;
		box->pos++;
	}
}

void	ft_precision_star(t_data *box)
{
	box->precision = va_arg(box->list, int);
	if (box->precision < 0)
	{
		box->minuspre = 1;
		if (box->precision == -2147483648)
			box->precision += 1;
		box->precision *= -1;
		box->flag_combo |= DASH;
	}
	box->pos++;
}

void	ft_category_scanner(t_data *box)
{
	box->scan_type = "cspdiuxX%";
	while (box->scan_type[box->vernier] != box->str[box->pos])
		box->vernier++;
}
