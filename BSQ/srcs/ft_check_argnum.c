/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_argnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rprasopk <rprasopk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 16:25:07 by rprasopk          #+#    #+#             */
/*   Updated: 2024/12/11 16:34:14 by rprasopk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/bsq.h"

int	ft_check_argnum(int argc)
{
	if (argc > 1)
		return (TRUE);
	else
	{
		ft_putstr("./BSQ [MAP_1] . . . [MAP_N]\n");
		return (FALSE);
	}
}
