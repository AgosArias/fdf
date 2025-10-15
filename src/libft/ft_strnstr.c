/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:50:38 by aarias-d          #+#    #+#             */
/*   Updated: 2025/05/29 16:51:16 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	large;

	if (*needle == '\0')
		return ((char *)haystack);
	large = ft_strlen(needle);
	if (*haystack == '\0' || len < large || ft_strlen(haystack) < large)
		return (NULL);
	while (haystack && 0 < len && len >= large)
	{
		if (ft_strncmp(haystack, needle, large) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
