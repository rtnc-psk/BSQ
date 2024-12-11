/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:05:21 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/11 13:06:10 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	main(int argc, char **argv)
{
	t_8bit *mp;
	t_rtm	result_;
	int		i;
	t_mppt	mppt;

	if (argc > 1)
	{
		i = 1;
		while (i < argc)
		{
			if (!ft_map_check(argv[i]))
				ft_putstr("Map Error\n");
			else
			{
				ft_assign_map(mppt, argv[i]);
				mp = malloc(sizeof(t_8bit) * mppt.col * mppt.row);
				result_ = solver(mp, mppt);
				map_mark(mp ,mppt, result_);
				print_map(mp, mppt, ".oX");
			}
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
