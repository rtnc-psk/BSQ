/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tchockbu <tchockbu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:42:00 by tchockbu          #+#    #+#             */
/*   Updated: 2024/12/10 21:14:44 by tchockbu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include "../includes/bsq.h"
# include <stdio.h>

typedef struct test
{
	t_8bit 			*mp;
	unsigned int	col;
	unsigned int	row;
	unsigned int	obn;
	unsigned int	*obl;
} tt;

void printmap(t_8bit *mp, t_mppt mppt);
tt	map_create(void);
void mapprint_marked(t_8bit *mp, t_mppt mppt, t_rtm rec);

#endif
