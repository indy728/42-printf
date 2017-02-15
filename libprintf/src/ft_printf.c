/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:31:54 by kmurray           #+#    #+#             */
/*   Updated: 2017/02/15 00:00:59 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	flag(char c)
{
	if (c == '%')
		return (1);
	return (0);
}

/*int	ft_flag(char str, void *arg)
{
	int	n;

	n = 0;
	if (is_num(*str))
	//field width handler
	if (*str == '.')
		//precision handler
	if (*str = 'd')
		n = ft_putlnbr(ft_atoi((char *)arg));
	else if (*str = 'c')
		n = ft_putlchar(*(char *)arg);
	else if (*str = 's')
		n = ft_putlstr((char *)arg);
	return (n);
}*/

int	ft_printf(const char *fmt_str, ...)
{
	int		ftpf;
	va_list	ap;

	ftpf = 0;
	va_start(ap, fmt_str);
	while (*fmt_str)
	{
		if (*fmt_str != '%')
			ftpf += ft_putlchar(*fmt_str);
		else
		{
			++fmt_str;
			if (*fmt_str == 'd')
				ftpf += ft_putlnbr(va_arg(ap, long));
			if (*fmt_str == 'c')
				ftpf += ft_putlchar(va_arg(ap, int));
			else if (*fmt_str == 's')
				ftpf += ft_putlstr(va_arg(ap, char *));
		}
		++fmt_str;
	}
	va_end(ap);
	return (ftpf);
}
