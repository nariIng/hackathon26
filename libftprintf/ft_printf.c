/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 07:18:38 by enarindr          #+#    #+#             */
/*   Updated: 2024/03/11 07:30:24 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_setformat(va_list args, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_print_char(va_arg(args, int));
	else if (c == 's')
		len += ft_print_str(va_arg(args, char *));
	else if (c == 'p')
		len += ft_print_hex_void(va_arg(args, unsigned long long));
	else if (c == 'd' || c == 'i')
		len += ft_print_num(va_arg(args, int));
	else if (c == 'u')
		len += ft_print_unint(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_print_hex(va_arg(args, unsigned int), c);
	else if (c == '%')
		len += ft_print_perc();
	else
		len += write(1, &c, 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start (args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_setformat(args, str[i + 1]);
			i++;
		}
		else
			len += ft_print_char(str[i]);
		i++;
	}
	va_end(args);
	return (len);
}
