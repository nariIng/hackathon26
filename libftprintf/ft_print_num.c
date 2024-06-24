/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_num.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: enarindr <enarindr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 14:16:23 by enarindr          #+#    #+#             */
/*   Updated: 2024/05/11 09:51:25 by enarindr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_count_unum(unsigned int nbr)
{
	int	n;

	n = 0;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		n++;
	}
	return (n);
}

int	ft_print_unint(unsigned int nbr)
{
	unsigned int	nbr2;
	int				len;

	nbr2 = nbr;
	len = 0;
	if (nbr == 0)
		write(1, "0", 1);
	else
		ft_put_unbr(nbr);
	len += ft_count_unum(nbr2);
	return (len);
}

int	ft_count_num(int nbr)
{
	int	n;

	n = 0;
	if (nbr < 0)
		n++;
	if (nbr == 0)
		return (1);
	while (nbr != 0)
	{
		nbr /= 10;
		n++;
	}
	return (n);
}

int	ft_print_num(int nbr)
{
	int	nbr2;
	int	n;

	nbr2 = nbr;
	n = 0;
	ft_putnbr(nbr);
	n = ft_count_num(nbr2);
	return (n);
}
