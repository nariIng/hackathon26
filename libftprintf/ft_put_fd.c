/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_fd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 07:47:25 by enarindr          #+#    #+#             */
/*   Updated: 2024/05/11 10:47:51 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_putnbr(int n)
{
	if (n == -2147483648)
		ft_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			ft_putchar('-');
			n *= -1;
		}
		if (n > 9)
			ft_putnbr(n / 10);
		ft_putchar((n % 10) + '0');
	}
}

void	ft_putchar(char c)
{
	write (1, &c, 1);
}

void	ft_put_unbr(unsigned int nb)
{
	if (nb < 10)
	{
		ft_putchar(nb + '0');
	}
	else
	{
		ft_put_unbr(nb / 10);
		ft_put_unbr(nb % 10);
	}
}
