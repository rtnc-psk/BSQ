/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 13:34:01 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/11 14:26:08 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

t_mppt	if_false(void)
{
	t_mppt mppt;
	
	mppt.col = 0;
	mppt.row = 0;
	mppt.obn = 0;
	mppt.obl = NULL;
	return (mppt);
}

int	ft_check_obs(char **split, int line_count, char obs)
{
	int	i;
	int	j;
	int	count_obs;

	i = 0;
	count_obs = 0;
	while (++i <= line_count)
	{
		j = -1;
		while(split[i][++j] != '\0')
			if (split[i][j] == obs)
				count_obs++;
	}
	return (count_obs);
}

t_mppt 	ft_assign_map(char *map_path)
{
	t_mppt	mppt;
	char	**split;
	char	fob[3];

	split = ft_read_file(map_path);
	mppt.row = check_firstline(split[0], (char*)fob);
	mppt.col = ft_strlen(split[1]);
	mppt.obn = ft_check_obs(split, mppt.row, fob[1]);
	if (mppt.row == 0)
		return (if_false());
	if (mppt.col == 0)
		return (if_false());
	if (mppt.obn == 0)
		return (if_false());
	return (mppt);
}