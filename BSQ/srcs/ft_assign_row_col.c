/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_row_col.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:34:01 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/11 17:30:13 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_assign_row_col(char *map_path)
{
	t_mppt	mppt;
	char	**split;
	char	fob[3];

	split = ft_read_file(map_path);
	mppt.row = check_firstline(split[0], (char *)fob);
	mppt.col = ft_strlen(split[1]);
	mppt.obn = 0;
	mppt.obl = NULL;
	return (mppt.row * mppt.col);
}
