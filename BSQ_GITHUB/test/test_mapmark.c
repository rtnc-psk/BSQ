/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_mapmark.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchockbu <tchockbu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1999/01/01 00:00:00 by tchockbu          #+#    #+#             */
/*   Updated: 2024/12/10 21:32:06 by tchockbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void mapprint_marked(t_8bit *mp, t_mppt mppt, t_rtm rec)
{
	t_8bit *mp2;
	unsigned int arr_sz = mppt.col * mppt.row;
	mp2 = malloc(sizeof(t_8bit) * arr_sz);
	for (unsigned int i = 0; i < arr_sz; i++)
		mp2[i] = mp[i];
	int x = rec.sqr_lc % mppt.col;
	int y = rec.sqr_lc / mppt.col;
	//printf("x = %d, y = %d\n",x,y);
	for (unsigned int j = 0; j < rec.sqr_sz; j++)
	{
		for (unsigned int i = 0; i < rec.sqr_sz; i++)
		{
			mp2[(j+y)*mppt.col + x + i] = SQR_MARK;
		}
	}
	printmap(mp2, mppt);
	free(mp2);
}
