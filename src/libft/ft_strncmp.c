/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:51:00 by aarias-d          #+#    #+#             */
/*   Updated: 2025/05/29 16:32:37 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	if (n == 0)
		return (0);
	count = 0;
	while (count < n - 1 && s1[count] && s2[count] && s1[count] == s2[count])
		count++;
	if (s1[count] == s2[count])
		return (0);
	return ((unsigned char)s1[count] - (unsigned char) s2[count]);
}
