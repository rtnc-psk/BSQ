/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 22:06:29 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/11 00:11:42 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H

void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_atoi(char *str);

char	**ft_split(char *str, char *charset);
int	ft_count_word(char *str, char *charset);

char	**ft_read_file(char *map_path);
int	ft_map_check(char *map_path);

# define TRUE  1
# define FALSE 0

typedef struct s_data
{
	char			*map;
	char			empty;
	char			obstacle;
	char			filler;
	unsigned int	nbr_lines;
	unsigned int	len_lines;
	unsigned int	bsq_x;
	unsigned int	bsq_y;
	unsigned long	n;
	int				fd;
}					t_data;

#endif
