/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 21:30:19 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/11 13:03:05 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_strlen(char *str)
{
	int	count;

	count = 0;
	while (str[count] != '\0')
	{
		count++;
	}
	return (count);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);

}
void	ft_putstr(char *str)
{
	write(STDOUT_FILENO, str, ft_strlen(str));
}
/*
char	*rm_space(char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
	{
		i++;
	}
	return (&str[i]);
}
*/

int	ft_atoi(char *str)
{
	int	r;
	int	pn;
	int	i;

	i = 0;
	r = 0;
	pn = 1;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			pn = -pn;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
			r = r * 10 + (str[i] - '0');
		else
			break ;
		i++;
	}
	return (r * pn);
}
