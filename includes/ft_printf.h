/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tshimoda <tshimoda@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/25 14:46:17 by tshimoda          #+#    #+#             */
/*   Updated: 2021/09/26 12:56:51 by tshimoda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	va_list		list;
	const char	*str;
	char		*scan_type;
	int			flag_combo;
	int			precision;
	int			minuspre;
	int			vernier;
	int			width;
	int			sign;
	int			sum;
	int			pos;
}		t_data;

enum e_flags
{
	NONE = 0,
	DASH = 1,
	ZERO = 2,
	SPACE = 4,
	PLUS = 8,
	POUND = 16,
	PRECISION = 32,
};

int		ft_printf(const char *str, ...);
void	ft_parsef(t_data *box);
void	ft_scan_init(t_data *box);
void	ft_flag_scanner(t_data *box);
void	ft_width_scanner(t_data *box);
void	ft_precision_scanner(t_data *box);
void	ft_precision_star(t_data *box);
void	ft_category_scanner(t_data *box);
void	category_is_char(t_data *box);
void	category_is_string(t_data *box);
void	category_is_decint(t_data *box);
void	category_is_unsign(t_data *box);
void	category_is_hexa(t_data *box);
void	category_is_hexa_up(t_data *box);
void	category_is_hexa_ptr(t_data *box);
void	category_is_modulo(t_data *box);
int		ft_strlen(char *str);
int		ft_isalpha(t_data *box);
int		ft_isdigit(t_data *box);
void	ft_is_signed(int n, t_data *box);
int		ft_is_uneven(int nb);
int		ft_nb_digit(int n);
int		ft_nb_digit_u(unsigned int n);
int		ft_nb_digit_x(unsigned int n);
int		ft_nb_digit_ptr(unsigned long long int n);
int		ft_putchar(char c);
int		ft_putstr(char *str, t_data *box);
int		ft_putstr_lp(char *str, t_data *box);
int		ft_putstr_l(char *str, t_data *box);
int		ft_putstr_r(char *str, t_data *box);
int		ft_putnbr(int n);
int		ft_putnbr_dashed(int n);
int		ft_putnbr_left(int n, t_data *box);
int		ft_putnbr_zero(int n, t_data *box);
void	ft_putnbr_firstchar(int n, t_data *box);
int		ft_putnbr_right(int n, t_data *box);
void	ft_putnbr_r_core(int n, t_data *box);
int		ft_putunsign(unsigned int n);
int		ft_unsl(unsigned int n, t_data *box);
int		ft_unsz(unsigned int n, t_data *box);
int		ft_unsr(unsigned int n, t_data *box);
int		ft_hexa(unsigned long long int nb);
int		ft_hexa_up(unsigned long long int nb);
int		ft_hexa_l(unsigned int n, t_data *box);
int		ft_hexa_z(unsigned int n, t_data *box);
int		ft_hexa_r(unsigned int n, t_data *box);
int		ft_hexa_ul(unsigned int n, t_data *box);
int		ft_hexa_uz(unsigned int n, t_data *box);
int		ft_hexa_ur(unsigned int n, t_data *box);
int		pexl(unsigned long long int n, t_data *box);
int		pexr(unsigned long long int n, t_data *box);
void	ft_put_spaces(t_data *box);
void	ft_set_bytes(t_data *box, int nb_digit);
void	ft_set_min_width(t_data *box, int nb_digit);
void	ft_set_min_width2(t_data *box, int nb_digit);
void	ft_set_max_precision(t_data *box, int nb_digit);
#endif