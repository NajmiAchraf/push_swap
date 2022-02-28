/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anajmi <anajmi@student.1337.ma>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 10:52:01 by anajmi            #+#    #+#             */
/*   Updated: 2022/02/21 19:05:16 by anajmi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_sign(int sign)
{
	if (sign == -1)
		return (0);
	else
		return (-1);
}

int	ft_atoi(const char *str)
{
	long	nbr;
	int		sign;
	int		a;

	a = 0;
	nbr = 0;
	sign = 1;
	while (str[a] == ' ' || (9 <= str[a] && str[a] <= 13))
		a++;
	if (str[a] == '-' || str[a] == '+')
	{
		if (str[a] == '-')
			sign *= (-1);
		a++;
	}
	while ('0' <= str[a] && str[a] <= '9')
	{
		nbr *= 10;
		if (nbr > INT32_MAX)
			return (check_sign(sign));
		if (-nbr < INT32_MIN)
			return (check_sign(sign));
		nbr += str[a] - '0';
		a++;
	}
	return (nbr * sign);
}
/*
int	main(void)
{
	int		val;
	char 	str[] = "9223372036854775807";
	// char 	str[] = "9223372036854775807";
	// char 	str[] = "4294967299";

	val = ft_atoi(str);
	printf("String value = %s, Int value = %d\n", str, val);
	val = atoi(str);
	printf("String value = %s, Int value = %d\n", str, val);
	return (0);
}
*/
