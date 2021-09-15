/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_digit_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/26 14:38:28 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/14 08:16:29 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	ft_nb_digit(int n)
{	
	int	count;

	count = 1;
	if (n == -2147483648)
		return (10);
	if (n < 0)
		n *= -1;
	while (n / 10 != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_nb_digit_u(unsigned int n)
{	
	int	count;

	count = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_nb_digit_x(unsigned int n)
{	
	int	count;

	count = 1;
	while (n / 16 != 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}

int	ft_nb_digit_ptr(unsigned long long int n)
{	
	int	count;

	count = 1;
	while (n / 16 != 0)
	{
		n = n / 16;
		count++;
	}
	return (count);
}
