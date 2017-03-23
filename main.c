/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 21:53:29 by kmurray           #+#    #+#             */
/*   Updated: 2017/03/22 20:43:28 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main(/*int ac, char **av*/)
{
	int i = ft_printf("% h");
//	printf("%d\n", printf("%lp", &nbr));
	ft_putnbr(i);
	return (0);
}
