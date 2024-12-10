/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 18:44:01 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/11 00:14:21 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_get_file_size(char *dictpath)
{
	char	c;
	int		file;
	int		count;

	file = open(dictpath, O_RDONLY);
	if (file == -1)
		return (-1);
	count = 0;
	while (read(file, &c, 1))
		count++;
	close(file);
	return (count);
}

char	**ft_read_file(char *map_path)
{
	char	*buffer;
	char	**split;
	int		file;
	int		size;
	int		bytes_read;

	size = ft_get_file_size(map_path);
	if (size < 0)
		return (FALSE);
	file = open(map_path, O_RDONLY);
	if (file == -1)
		return (FALSE);
	buffer = malloc (sizeof(char) * (size + 1));
	if (buffer == 0)
		return ((void)close(file), NULL);
	bytes_read = read(file, buffer, size);
	if (bytes_read != size)
		return (free(buffer), (void)close(file), NULL);
	buffer[size] = '\0';
	split = ft_split(buffer, "\n");
	free(buffer);
	close(file);
	return (split);
}
