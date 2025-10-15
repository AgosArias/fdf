/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:50:25 by aarias-d          #+#    #+#             */
/*   Updated: 2025/05/29 17:19:15 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_isinset(int c, char const *set)
{
	int	y;

	y = 0;
	while (set[y])
	{
		if (set[y] == c)
			return (1);
		y++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && ft_isinset(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_isinset(s1[end - 1], set) == 1)
		end--;
	if (end <= start)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start));
}
