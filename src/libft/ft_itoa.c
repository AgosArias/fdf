/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:49:35 by aarias-d          #+#    #+#             */
/*   Updated: 2025/05/30 16:06:02 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lenght(long n)
{
	int	i;

	i = 1;
	while (n >= 10)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*c;
	long	num;
	int		i;
	int		symbol;

	symbol = 0;
	num = n;
	if (num < 0)
	{
		symbol++;
		num = -num;
	}
	i = ft_lenght(num) + symbol;
	c = (char *)malloc(sizeof(char) * (i + 1));
	if (c == NULL)
		return (NULL);
	if (symbol == 1)
		c[0] = '-';
	c[i] = '\0';
	while (symbol <= i - 1)
	{
		c[i-- -1] = (num % 10) + '0';
		num = num / 10;
	}
	return (c);
}
