/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchockbu <tchockbu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 1999/01/01 00:00:00 by tchockbu          #+#    #+#             */
/*   Updated: 2024/12/10 21:38:49 by tchockbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int main()
{
	printf("=====================================================================================================\n");
	tt	temp;
	t_mppt mppt;
	t_8bit *mp_1;

	temp = map_create();
	mppt.col = temp.col;
	mppt.row = temp.row;
	mppt.obn = temp.obn;
	mppt.obl = temp.obl;
	mp_1	 = temp.mp;

	// printf("col = %u, row = %u, OBSTACLE = %u\n", mppt.col, mppt.row, mppt.obn);
	// for (unsigned int i = 0; i < mppt.obn; i++)
	// {
	// 	printf("(%u,%u) ", mppt.obl[i] % mppt.col, mppt.obl[i] / mppt.col );
	// }
	// printf("\n");
	printmap(mp_1, mppt);
	{
		t_rtm a;
		a = solver(mp_1, mppt);
		printf("size %u, Locate (%u,%u)\n", a.sqr_sz, a.sqr_lc % mppt.col, a.sqr_lc / mppt.col);
		
		mapprint_marked(mp_1, mppt, a);
	}
	// {
	// 	unsigned int ara[7] = {0, 0, 0, 0, 0, 0, 0};
	// 	// lcol
	// 	ara[1] = 4;
	// 	// lrow
	// 	ara[2] = 7;
	// 	printf("(%u,%u) %u\n", ara[1], ara[2],
	// 		sqr_count(mp_1, mppt, (unsigned int *)ara));
	// 	printmap(mp_1, mppt);
	// }
	free(mp_1);
	printf("=====================================================================================================\n");
}

void printmap(t_8bit *mp, t_mppt mppt)
{
	printf("=====================================================================================================\n");
	printf("0                   1                   2                   3                   4                   5\n");
	printf("0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0\n");
	t_8bit temp;
	for (unsigned int i = 0; i < mppt.row; i++)
	{
		for (unsigned int j = 0; j < mppt.col; j++)
		{
			temp =  mp[i*mppt.col + j];
			if(temp == FILLABLE)
				printf("- ");
			else if (temp == NOT_FILL)
				printf(": ");
			else if (temp == SQR_MARK)
				printf("X ");
			else
				printf("%u ", temp);
		}
		putchar(10);
	}
}

