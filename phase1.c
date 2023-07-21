/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:11:47 by kglebows          #+#    #+#             */
/*   Updated: 2023/07/21 16:35:27 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_phase1(t_pushswap *dt)
{
	int		i;
	int		last;

	i = dt->ph1;
	while (dt->A->id != dt->ph1)
		ft_stack_pb(dt);
	last = dt->A->id;
	ft_stack_ra(dt);
	while (dt->A && dt->A->id != i)
	{
		if (dt->A->nxt->id > last && dt->A->nxt->id < dt->A->id)
		{
			ft_stack_sa(dt);
		}
		else if (dt->A->id >= dt->ph1)
		{
			dt->ph1 = dt->A->id;
			last = dt->A->id;
			ft_stack_ra(dt);
		}
		else
			ft_stack_pb(dt);
	}
}

/*
possible optimalizations:
- leave rotations if already sorted
- check for sa/ss
- check for rr with pa
- further improvement - dribbbleee with ss


 dribbbleee 
15 <-scan (dt->A->id)
14 <-next (dt->A->nxt->id)
9
10
11
13 <-last (last = dt->A->id when last ra)
=
sa if next > last && next < scan


 imdone 
 14 <- scan > last <if>(tmp = dt->A, scan = tmp->id)
 15 <- next > scan <while>(next = tmp->nxt->id)<tmp = tmp->nxt >> tmp->nxt->id = i>
 9  <- original phase1 id (i)
 10
 11
 13 <-last
=
when i reached - return. 


*/