/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 18:35:05 by kmurray           #+#    #+#             */
/*   Updated: 2017/01/23 23:36:08 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa_base(int n, int base)
{
	char			*ascii;
	int				cb;
	unsigned int	o;

	if (2 > base || base > 16)
		return (NULL);
	cb = ft_count_base(n, base);
	if (!(ascii = ft_strnew(cb)))
		return (NULL);
	ascii[cb] = '\0';
	o = n;
	if (n < 0)
	{
		o *= -1;
		if (base == 10)
			ascii[0] = '-';
	}
	while (o / base)
	{
		ascii[--cb] = ft_base_char(o % base);
		o /= base;
	}
	ascii[--cb] = ft_base_char(o % base);
	return (ascii);
}
