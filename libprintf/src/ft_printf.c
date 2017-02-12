/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:31:54 by kmurray           #+#    #+#             */
/*   Updated: 2017/02/11 23:10:09 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	flag(char c)
{
	if (c == '%')
		return (1);
	return (0);
}

int	ft_flag(char *str)
{
	return (ft_putlchar(*str));
}

int	ft_printf(const char *fmt_str, ...)
{
	int	ftpf;

	ftpf = 0;
	while (*fmt_str)
	{
		if (!flag(*fmt_str))
			ftpf += ft_putlchar(*fmt_str);
		else
			ftpf += ft_flag((char *)(++fmt_str));
		++fmt_str;
	}
	return (ftpf);
}
