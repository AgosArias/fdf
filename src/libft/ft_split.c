/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/05 17:51:51 by aarias-d          #+#    #+#             */
/*   Updated: 2025/05/30 16:09:24 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_words(char const *s, char c)
{
	int	count;
	int	boolean;
	int	i;

	count = 0;
	boolean = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && boolean == 0)
		{
			boolean = 1;
			count++;
		}
		if (s[i] == c && boolean == 1)
			boolean = 0;
		i++;
	}
	return (count);
}

int	ft_fill_matriz(char **matriz, char const *s, int j, char c)
{
	int	len;

	len = 0;
	while (s[len] != '\0' && s[len] != c)
		len++;
	matriz[j] = ft_substr(s, 0, len);
	if (matriz[j] == NULL)
	{
		while (j > 0)
			free(matriz[--j]);
		free(matriz);
		return (0);
	}
	return (len);
}

char	**ft_split(char const *s, char c)
{
	int		j;
	char	**matriz;
	int		len;

	if (s == NULL)
		return (NULL);
	matriz = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (matriz == NULL)
		return (NULL);
	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			len = ft_fill_matriz(matriz, s, j++, c);
			if (len == 0)
				return (NULL);
			s += len;
		}
		else
			s++;
	}
	matriz[j] = NULL;
	return (matriz);
}
