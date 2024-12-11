/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_map_convert.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchockbu <tchockbu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:42:00 by tchockbu          #+#    #+#             */
/*   Updated: 2024/12/10 21:12:08 by tchockbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	map_mark(t_8bit *mp, t_mppt mppt, t_rtm rec)
{
	unsigned int	x;
	unsigned int	y;
	unsigned int	i;
	unsigned int	j;

	x = rec.sqr_lc % mppt.col;
	y = rec.sqr_lc / mppt.col;
	j = 0;
	while (j < rec.sqr_sz)
	{
		i = 0;
		while (i < rec.sqr_sz)
		{
			mp[((j + y) * mppt.col) + x + i] = SQR_MARK;
			i ++;
		}
		j ++;
	}
}
