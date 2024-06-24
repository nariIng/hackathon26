/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 13:29:08 by enarindr          #+#    #+#             */
/*   Updated: 2024/05/11 09:51:17 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_hex_len(unsigned long long nbr)
{
	int	n;

	n = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 16;
		n ++;
	}
	return (n);
}

void	ft_put_hex(unsigned long long nbr)
{
	if (nbr >= 16)
	{
		ft_put_hex(nbr / 16);
		ft_put_hex(nbr % 16);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar((int)nbr + '0');
		else
			ft_putchar((int)nbr - 10 + 'a');
	}
}

int	ft_print_hex_void(unsigned long long nbr)
{
	int	n;

	n = 0;
	if (nbr == 0)
	{
		n += write(1, "(nil)", 5);
		return (n);
	}
	else
	{
		n += write(1, "0x", 2);
		ft_put_hex(nbr);
		n += ft_hex_len(nbr);
	}
	return (n);
}

int	ft_print_hex(unsigned int nbr, char c)
{
	unsigned long long	nbr2;

	nbr2 = (unsigned long long)nbr;
	if (nbr >= 16)
	{
		ft_print_hex(nbr / 16, c);
		ft_print_hex(nbr % 16, c);
	}
	else
	{
		if (nbr <= 9)
			ft_putchar(nbr + '0');
		else
		{
			if (c == 'x')
				ft_putchar(nbr - 10 + 'a');
			else if (c == 'X')
				ft_putchar(nbr - 10 + 'A');
		}
	}
	return (ft_hex_len((nbr2)));
}
