/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:11:47 by kglebows          #+#    #+#             */
/*   Updated: 2023/06/27 16:40:17 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_phase1(t_pushswap *dt)
{
	int		i;

	i = dt->ph1;
	while (dt->A->id != dt->ph1)
		ft_stack_pb(dt);
	test_stacks(dt);
	ft_stack_ra(dt);
	while (dt->A && dt->A->id != i)
	{
		if (dt->A->id >= dt->ph1)
		{
			dt->ph1 = dt->A->id;
			ft_stack_ra(dt);
		}
		else
			ft_stack_pb(dt);
	}
}