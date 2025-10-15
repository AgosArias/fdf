/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:50:15 by aarias-d          #+#    #+#             */
/*   Updated: 2025/05/29 17:23:56 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*w;
	int		x;

	if (s == NULL )
		return (NULL);
	if (len == 0 || start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	if ((size_t)ft_strlen(s) - (size_t)start < len)
		len = (size_t)ft_strlen(s) - (size_t)start;
	w = (char *)malloc(sizeof(char) * (len + 1));
	if (w == NULL)
		return (NULL);
	x = 0;
	while ((size_t)x < len)
	{
		w[x] = s[x + start];
		x++;
	}
	w[x] = '\0';
	return (w);
}
