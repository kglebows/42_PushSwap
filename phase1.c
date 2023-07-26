/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:11:47 by kglebows          #+#    #+#             */
/*   Updated: 2023/07/26 14:58:56 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_phase1(t_pushswap *dt)
{
	int		first;
	int		last;

	while (dt->A->mv != dt->ph1)
		ft_stack_pb(dt);
	if (ft_phase1_sorted(dt) == 1)
		return ;
	first = dt->A->id;
	last = first;
	ft_stack_ra(dt);
	dt->ph1--;
	while (dt->A && dt->A->id != first)
	{
		if (ft_phase1_imdone(dt, first, last) == 1)
			return ;
		// else if (dt->A->nxt->id > last && dt->A->nxt->id < dt->A->id)
		// 	ft_stack_sa(dt);
		else if (dt->A->id > last && dt->A->mv == dt->ph1)
		{	
			last = dt->A->id;
			if (dt->B->id > (dt->len / 2))
				ft_stack_rr(dt);
			else
				ft_stack_ra(dt);
			dt->ph1--;
		}
		else if (dt->B->id > (dt->len / 2))
		{
			ft_stack_rb(dt);
			ft_stack_pb(dt);
		}
		else
			ft_stack_pb(dt);
	}
	if (dt->B->id > (dt->len / 2))
		ft_stack_rb(dt);
}

int ft_phase1_imdone(t_pushswap *dt, int first, int last)
{
	t_stack		*tmp;

	tmp = dt->A;
	if (dt->A->id > last)
	{
		while (tmp->nxt->id > tmp->id)
			tmp = tmp->nxt;
		if (tmp->nxt->id == first)
			return (1);
	}
	return (0);
}

int ft_phase1_sorted(t_pushswap *dt)
{
	t_stack		*tmp;

	tmp = dt->A;
	while (tmp->nxt != NULL && tmp->nxt->id > tmp->id)
			tmp = tmp->nxt;
	if (tmp->nxt == NULL)
		return (1);
	return (0);
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

dribbbleee disabled, need to do tests after finishinig phase 2 and 3
*/