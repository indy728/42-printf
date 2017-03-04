/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/08 16:31:54 by kmurray           #+#    #+#             */
/*   Updated: 2017/02/21 01:48:25 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	flag(char c)
{
	if (c == '%')
		return (1);
	return (0);
}



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
			if (*fmt_str == 'd' || *fmt_str == 'i')
				ftpf += ft_putlstr(ft_lltoa_base((int)va_arg(ap, int), 10));
			else if (*fmt_str == 'D')
				ftpf += ft_putlstr(ft_lltoa_base((long)va_arg(ap, long), 10));
			else if (*fmt_str == 'u' || *fmt_str == 'U')
				ftpf += ft_putlstr(ft_lltoa_base((uintmax_t)va_arg(ap, uintmax_t), 10));
			else if (*fmt_str == 'x')
				ftpf += ft_putlstr(ft_lltoa_base(va_arg(ap, long), 16));
			else if (*fmt_str == 'p')
			{
				ftpf += ft_putlstr("0x");
				ftpf += ft_putlstr(ft_lltoa_base((long)va_arg(ap, void *), 16));
			}
			else if (*fmt_str == 'o' || *fmt_str == 'O')
				ftpf += ft_putlstr(ft_lltoa_base(va_arg(ap, long), 8));
			else if (*fmt_str == 'c')
				ftpf += ft_putlchar(va_arg(ap, int));
			else if (*fmt_str == '%')
				ftpf += ft_putlchar('%');
			else if (*fmt_str == 's')
				ftpf += ft_putlstr(va_arg(ap, char *));
		}
		++fmt_str;
	}
	va_end(ap);
	return (ftpf);
}
