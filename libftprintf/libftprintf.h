/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 08:44:59 by enarindr          #+#    #+#             */
/*   Updated: 2024/05/11 10:36:59 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./libft/libft.h"

void	ft_put_hex(unsigned long long nbr);
void	ft_put_unbr(unsigned int nb);
void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);

int		ft_print_char(int c);
int		ft_print_str(char *str);
int		ft_print_hex_void(unsigned long long nbr);
int		ft_hex_len(unsigned long long nbr);

int		ft_print_num(int n);
int		ft_count_num(int nbr);

int		ft_print_unint(unsigned int n);
int		ft_print_hex(unsigned int n, const char c);
int		ft_print_perc(void);

int		ft_setformat(va_list args, char c);
int		ft_printf(const char *str, ...);

#endif
