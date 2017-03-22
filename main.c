/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 21:53:29 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/22 02:18:26 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(/*int ac, char **av*/)
{
//	char	*str = "BANANAS";
//	char *ptr;
//	char *ptr2;
//	long ret = 0;
//	int					nbr = 42;
//	unsigned int		num = 42;
//	int i = ft_printf("String literal\n");
//	printf("%d\n", printf("String literal\n"));
	int i = ft_printf("% u|%+u\n", 42, 42);
//	printf("%d\n", printf("{%10R}"));
//	int i = ft_printf("This is %D my test.\n", strtol((av[1]), &ptr, ret));
//	printf("%d\n", printf("This is %ld tu test.\n", strtol((av[1]), &ptr2, ret)));
	ft_putnbr(i);
//	printf("Let's test some flags '%.0u' && '%.0u'\n", nbr, num);
	return (0);
}
