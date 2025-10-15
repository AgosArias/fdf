/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aarias-d <aarias-d@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 17:00:58 by aarias-d          #+#    #+#             */
/*   Updated: 2025/05/30 17:13:42 by aarias-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*nodo;

	if (!lst || !new)
		return ;
	if (!*lst)
		*lst = new;
	else
	{
		nodo = *lst;
		while (nodo->next)
			nodo = nodo->next;
		nodo->next = new;
	}
}
