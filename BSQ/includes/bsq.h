/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 00:42:00 by tchockbu          #+#    #+#             */
/*   Updated: 2024/12/11 20:01:25 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

# include <stdio.h>

// struct that contain properties of maps
// col > map column aka x-axis
// row > map    row aka y-axis
// obn > count of obstacles
// obl > array of obstacles position
typedef struct s_map_properties
{
	unsigned int	col;
	unsigned int	row;
	unsigned int	obn;
	unsigned int	*obl;
}	t_mppt;

// struct that contain return value
// sqr_sz is biggest square size found
// sqr_lc is first biggest square position
typedef struct s_return_map
{
	unsigned int	sqr_sz;
	unsigned int	sqr_lc;
}	t_rtm;

// unsigned char type for memory reduction from 4 to 1 bytes
typedef unsigned char	t_8bit;

// Boolean statement value 1
# define TRUE		1
// Boolean statement value 0
# define FALSE		0

// Map status 0 indicated this position is empty and/or fillable
# define FILLABLE	4
// Map status 1 indicated this position is obstacle
# define OBSTACLE	1
// Map status 2 indicated this position could be skip to reduce the process
# define NOT_FILL	2
// Map status 3 indicated this square could be here
# define SQR_MARK	3

// Function that solve the maps
t_rtm			solver(t_8bit *mp, t_mppt mppt);
t_mppt			ft_assign_map(char *map_path, t_8bit *mp);

// Function that count and return biggest square size possibles in any position
unsigned int	sqr_count(t_8bit *mp, t_mppt mppt, unsigned int *slr);

// Function that run array of obstacles and set NOT_FILL on the map
// around them to indicates that position should be skip
void			set_mp_fill_skip(t_8bit *mp, t_mppt mppt, unsigned int *slr);
void			print_map(t_8bit *mp, t_mppt mppt, char *str);
void			map_mark(t_8bit *mp, t_mppt mppt, t_rtm rec);

int				check_firstline(char *split, char *fob);
int				ft_strlen(char *str);
int				ft_atoi(char *str);
int				ft_map_check(char *map_path);
int				ft_check_argnum(int argc);
int				ft_count_word(char *str, char *charset);
char			**ft_split(char *str, char *charset);
char			**ft_read_file(char *map_path);
char			*ft_assign_fob(char *map_path);
void			ft_putchar(char c);
void			ft_putstr(char *str);
int				ft_assign_row_col(char *map_path);

#endif
