/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:09:03 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/11 14:17:02 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

// [line_nbr]  [fill]     [obs]   [box]
//			  [len - 2] [len - 1] [len]
int	check_firstline(char *split, char *fob)
{
	int	line;
	int	len;
	int	i;

	len = ft_strlen(split);
	if (len < 4)
		return (FALSE);
	i = -1;
	while (split[++i] != '\0')
		if (split[i] < 32 || split[i] > 126)
			return (FALSE);
	if ((split[len - 1] == split[len - 2])
		|| (split[len - 1] == split[len - 3])
		|| (split[len - 2] == split[len - 3]))
	{
		return (FALSE);
	}
	fob[0] = split[len - 3];
	fob[1] = split[len - 2];
	fob[2] = split[len - 1];
	split[len - 3] = '\0';
	line = ft_atoi(split);
	return (line);
}

int	ft_count_line(char **split)
{
	int	count;

	count = 0;
	while (split[count])
		count++;
	return (count - 1);
}

int	ft_check_char(char **split, int line_count, char fill, char obs)
{
	int	i;
	int	j;

	i = 0;
	while (++i < line_count)
	{
		j = 0;
		while (split[i][++j] != '\0')
			if (split[i][j] != fill && split[i][j] != obs)
				return (FALSE);
	}
	return (TRUE);
}

char	*ft_assign_fob(char *map_path)
{
	int		len;
	char	*fob;
	char	**split;

	split = ft_read_file(map_path);
	fob = malloc(sizeof(char) * 4);
	len = ft_strlen(split[0]);
	fob[0] = split[0][len - 3];
	fob[1] = split[0][len - 2];
	fob[2] = split[0][len - 1];
	fob[3] = '\0';
	return (fob);
}

int	ft_map_check(char *map_path)
{
	int		line_num;
	int		line_count;
	char	**split;
	char	fob[3];

	split = ft_read_file(map_path);
	line_num = check_firstline(split[0], (char *)fob);
	line_count = ft_count_line(split);
	if (!line_num)
		return (FALSE);
	if (line_num != line_count)
		return (FALSE);
	while (--line_num > 1)
		if (ft_strlen(split[1]) != ft_strlen(split[line_num]))
			return (FALSE);
	if (!ft_check_char(split, line_count, fob[0], fob[1]))
		return (FALSE);
	return (TRUE);
}
