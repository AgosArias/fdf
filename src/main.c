/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agossariass <agossariass@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 17:43:48 by agossariass       #+#    #+#             */
/*   Updated: 2025/10/04 12:15:03 by agossariass      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	char	**matriz;

	if (argc != 2)
		ft_error("Bad Arguments");
	matriz = ft_create_matriz(argv[1]);
	ft_free_matriz(matriz);
	return (0);
}
