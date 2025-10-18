/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d < aarias-d@student.42malaga.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:51:29 by aarias-d          #+#    #+#             */
/*   Updated: 2025/10/18 18:35:53 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*w;
	int		a;
	int		b;

	b = -1;
	a = -1;
	if (!s1 && !s2)
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	w = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (w == NULL)
		return (NULL);
	while (s1[++a] != '\0')
		w[a] = s1[a];
	while (s2[++b] != '\0')
		w[a + b] = s2[b];
	w[a + b] = '\0';
	return (w);
}
