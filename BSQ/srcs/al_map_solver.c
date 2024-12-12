/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   al_map_solver.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:42:00 by tchockbu          #+#    #+#             */
/*   Updated: 2024/12/11 15:44:28 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

void	set_para_sl(t_mppt mppt, unsigned int *slr)
{
	slr[0] = 0;
	slr[1] = 0;
	slr[2] = 0;
	slr[3] = 1;
	slr[4] = 0;
	slr[5] = mppt.col + 1 - slr[3];
	slr[6] = mppt.row + 1 - slr[3];
}
//	slr[2] = 0; start loop at row 0
//	slr[3] = 1; square size start with 1;
//	slr[4] = 0; first postion start with (0,0)

unsigned int	*obstacle_arr(t_8bit *mp, t_mppt mppt)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	temp;
	unsigned int	*rt;

	i = 0;
	j = 0;
	temp = mppt.col * mppt.row;
	rt = malloc(sizeof(unsigned int) * mppt.obn);
	while (i < temp)
	{
		if (mp[i] == OBSTACLE)
		{
			rt[j] = i;
			j++;
		}
		i++;
	}
	return (rt);
}

void	set_boundary_sl(t_8bit *mp, t_mppt mppt, unsigned int *slr)
{
	slr[0] = sqr_count(mp, mppt, slr);
	if (slr[0] > slr[3])
	{
		set_mp_fill_skip(mp, mppt, (unsigned int *)slr);
		slr[4] = slr[2] * mppt.col + slr[1];
		slr[3] = slr[0];
		slr[5] = mppt.col + 1 - slr[3];
		slr[6] = mppt.row + 1 - slr[3];
	}
}

t_rtm	ret_struct(unsigned int *sqr_biggest, unsigned int *sqr_locate,
			t_8bit is_success)
{
	t_rtm	rt;

	if (is_success)
	{
		rt.sqr_sz = *sqr_biggest;
	}
	else
	{
		rt.sqr_sz = 0;
	}
	rt.sqr_lc = *sqr_locate;
	return (rt);
}

t_rtm	solver(t_8bit *mp, t_mppt mppt)
{
	t_8bit			is_success;
	unsigned int	sl[7];

	is_success = 0;
	mppt.obl = obstacle_arr(mp, mppt);
	set_para_sl(mppt, sl);
	while (sl[2] < sl[6])
	{
		sl[1] = 0;
		while (sl[1] < sl[5])
		{
			if (FILLABLE == mp[sl[2] * mppt.col + sl[1]])
			{
				set_boundary_sl(mp, mppt, sl);
				is_success = 1;
			}
			sl[1]++;
		}
		sl[2]++;
	}
	free(mppt.obl);
	return (ret_struct(&sl[3], &sl[4], is_success));
}
// l[0] => Temporaries values
// l[1] => Location of processing map (column j)
// l[2] => Location of processing map (row    i)
// l[3] => Store the biggest square found
// l[4] => Store the location of first biggest square found
// l[5] => Column dynamic boundary >> mppt.col + 1 - sl[3]
// l[6] =>    Row dynamic boundary >> mppt.row + 1 - sl[3]

// +-------> j column
// | X11 X12 X13
// | X21 X22 X23
// V X31 X32 X33
// i row         Xij     mp[i][j]
// To access array using mp[(i)*(MAXCOL) + j]
// To reverse to row using i / MAXCOL
// To reverse to col using i % MAXCOL
