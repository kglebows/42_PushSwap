/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:31 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/14 15:42:20 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argn, char *argc[])
{
	t_pushswap		*dt;

	dt = ft_ini(argn, argc);
	if (!dt)
		return (0);
	ft_solve(dt);
	ft_cleanup(dt);
	return (1);
}
