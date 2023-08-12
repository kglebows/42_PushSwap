/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:18:43 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/12 13:01:28 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pushswap *ft_Error(void)
{
	write(1, "Error\n", 6);
	return (NULL);
}

int ft_isnum(char *str)
{
	while (*str != '\0')
	{
		if (!(ft_isdigit((int) *str) || *str == '-' || *str == '+'))
			return (0);
		str++;
	}
	return(1);
}
