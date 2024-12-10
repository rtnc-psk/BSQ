/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:05:21 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/10 23:55:29 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	main(int argc, char **argv)
{
	int		i;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (!ft_map_check(argv[i]))
				ft_putstr("Map Error\n");
			else
				ft_putstr("Pass\n");
			i++;
		}
		if (i < argc)
			return (0);
	}
	else
	{
		ft_putstr("./BSQ [MAP_1] . . . [MAP_N]\n");
		return (0);
	}
}
