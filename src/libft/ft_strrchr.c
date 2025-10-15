/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:50:31 by aarias-d          #+#    #+#             */
/*   Updated: 2025/05/29 16:41:48 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		count;
	char	*d;

	d = (char *)s;
	count = ft_strlen(s);
	if ((char)c == '\0')
		return (&d[count]);
	while (count >= 0)
	{
		if (d[count] == (char)c)
			return (&d[count]);
		count--;
	}
	return (NULL);
}
