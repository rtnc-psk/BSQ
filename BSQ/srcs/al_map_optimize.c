/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_map_optimize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchockbu <tchockbu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:42:00 by tchockbu          #+#    #+#             */
/*   Updated: 2024/12/10 21:12:08 by tchockbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	set_map_notfill(t_8bit *mp, t_mppt mppt, unsigned int *fsr)
{
	unsigned int	i;
	unsigned int	tmp;

	i = 0;
	if (fsr[2] >= fsr[0])
	{
		while (fsr[1] >= i && i <= fsr[0])
		{
			tmp = (fsr[2] - fsr[0]) * mppt.col + fsr[1] - i;
			if (FILLABLE == mp[tmp])
				mp[tmp] = NOT_FILL;
			i++;
		}
	}
	i = 0;
	if (fsr[1] >= fsr[0])
	{
		while (fsr[2] >= i && i < fsr[0])
		{
			tmp = (fsr[2] - i) * mppt.col + fsr[1] - fsr[0];
			if (FILLABLE == mp[tmp])
				mp[tmp] = NOT_FILL;
			i++;
		}
	}
}
// if (fsr[2] >= fsr[0]) Horizental loop
// if (fsr[1] >= fsr[0]) Veritcal loop

void	set_mp_fill_skip(t_8bit *mp, t_mppt mppt, unsigned int *slr)
{
	unsigned int	i;
	unsigned int	fs[3];
	unsigned int	tmp;

	i = 0;
	while (i < mppt.obn)
	{
		tmp = mppt.obl[i];
		fs[0] = slr[3];
		fs[1] = tmp % mppt.col;
		fs[2] = tmp / mppt.col;
		while (fs[0] < slr[0])
		{
			set_map_notfill(mp, mppt, (unsigned int *)fs);
			fs[0]++;
		}
		i++;
	}
}
// fsr[0] => Temporaries values
// fsr[1] => Location of processing map (column j)
// fsr[2] => Location of processing map (row    i)

// slr[0] => Temporaries values
// slr[1] => Location of processing map (column j)
// slr[2] => Location of processing map (row    i)
// slr[3] => Store the biggest square found
// slr[4] => Store the location of first biggest square found
// slr[5] => Column dynamic boundary >> mppt.col + 1 - sl[3]
// slr[6] =>    Row dynamic boundary >> mppt.row + 1 - sl[3]

unsigned int	sqr_count(t_8bit *mp, t_mppt mppt, unsigned int *slr)
{
	unsigned int	sqr;
	unsigned int	i;
	unsigned int	x;
	unsigned int	y;

	x = slr[1];
	y = slr[2];
	sqr = 1;
	while (x + sqr < mppt.col && y + sqr < mppt.row)
	{
		i = 0;
		while (i <= sqr && x + i < mppt.col && y + i < mppt.row)
		{
			if (OBSTACLE == mp[(y + sqr) * mppt.col + (x + i)])
				return (sqr);
			if (OBSTACLE == mp[(i + y) * mppt.col + (x + sqr)])
				return (sqr);
			i++;
		}
		sqr++;
	}
	return (sqr);
}
// slr[0] => Temporaries values
// slr[1] => Location of processing map (column j)
// slr[2] => Location of processing map (row    i)
// slr[3] => Store the biggest square found
// slr[4] => Store the location of first biggest square found
// slr[5] => Column dynamic boundary >> mppt.col + 1 - sl[3]
// slr[6] =>    Row dynamic boundary >> mppt.row + 1 - sl[3]

// +-------> j column
// | X11 X12 X13
// | X21 X22 X23
// V X31 X32 X33
// i row         Xij     mp[i][j]
// To access array using mp[(i)*(MAXCOL) + j]
// To reverse to row using i / MAXCOL
// To reverse to col using i % MAXCOL
