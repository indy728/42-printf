/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmurray <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 21:53:29 by kmurray           #+#    #+#             */
/*   Updated: 2017/02/14 23:36:53 by kmurray          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "printf.h"
#include <stdio.h>

int main()
{
//	char	*str = "BANANAS";
//	int		num = 69;

	int i = ft_printf("This is %d test.\n", 69);
	printf("%d\n", printf("This is %d test.\n", 69));
	ft_putnbr(i);
	return (0);
}
