/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchockbu <tchockbu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:42:00 by tchockbu          #+#    #+#             */
/*   Updated: 2024/12/11 11:27:17 by tchockbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	print_map(t_8bit *mp, t_mppt mppt, char *str)
{
	t_8bit			temp;
	unsigned int	i;
	unsigned int	j;

	j = 0;
	while (j < mppt.row)
	{
		i = 0;
		while (i < mppt.col)
		{
			temp = mp[(j * mppt.col) + i];
			if (temp == NOT_FILL)
				ft_putchar(str[0]);
			else if (temp == FILLABLE)
				ft_putchar(str[0]);
			else if (temp == SQR_MARK)
				ft_putchar(str[2]);
			else
				ft_putchar(str[1]);
			i ++;
		}
		ft_putchar('\n');
		j ++;
	}
}
// str[0] = . FILLABLE, NOT_FILL
// str[1] = o OBSTACLE
// str[2] = X SQR_MARK
