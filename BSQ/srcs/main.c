/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:05:21 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/11 17:31:22 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	main(int argc, char **argv)
{
	t_8bit	*mp;
	t_rtm	result_;
	t_mppt	mppt;
	char	*fob;
	int		i;

	if (!ft_check_argnum(argc))
		return (0);
	i = 0;
	while (++i < argc)
	{
		if (!ft_map_check(argv[i]))
			ft_putstr("Map Error\n");
		else
		{
			fob = ft_assign_fob(argv[i]);
			mp = malloc(sizeof(t_8bit) * (ft_assign_row_col(argv[i])));
			mppt = ft_assign_map(argv[i], mp);
			result_ = solver(mp, mppt);
			map_mark(mp, mppt, result_);
			print_map(mp, mppt, fob);
			free(mp);
			free(fob);
		}
	}
}
