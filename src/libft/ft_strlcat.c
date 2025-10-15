/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:51:24 by aarias-d          #+#    #+#             */
/*   Updated: 2025/05/29 16:52:29 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t			i;
	size_t			j;
	size_t			tam;
	unsigned char	*d;
	unsigned char	*s;

	if (size == 0)
		return (ft_strlen(src));
	d = (unsigned char *) dest;
	s = (unsigned char *) src;
	i = ft_strlen(dest);
	if (i >= size)
		return (ft_strlen(src) + size);
	j = 0;
	tam = i + ft_strlen(src);
	while (s[j] && i < size - 1)
		d[i++] = s[j++];
	d[i] = '\0';
	return (tam);
}
