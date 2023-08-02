/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:11:47 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/02 16:03:45 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void find_top(t_pushswap *dt)
{
	t_stack		*tmp;

	tmp = dt->A;
	while (tmp)
	{
		if (tmp->id < dt->top)
			dt->top = tmp->id;
		tmp = tmp->nxt;
	}
}

int sorted(t_pushswap *dt)
{
	t_stack		*tmp;

	tmp = dt->A;
	while (tmp->nxt && tmp->nxt->id > tmp->id)
		tmp = tmp->nxt;
	if (!tmp->nxt)
		return (1);
	else if (tmp->nxt->id < tmp->id)
		tmp = tmp->nxt;
	while (tmp->nxt && tmp->nxt->id > tmp->id && tmp->id < dt->A->id)
		tmp = tmp->nxt;
	if (!tmp->nxt && tmp->id < dt->A->id)
		return (1);
	return (0);
}

void ft_phase1(t_pushswap *dt)
{
	int		first;
	int		last;

	if (sorted(dt) == 1)
		return ;
	while (dt->A->mv != dt->ph1)
		ft_stack_pb(dt);
	first = dt->A->id;
	last = first;
	if (dt->len > 3)
		ft_stack_ra(dt);
	dt->ph1--;
	while (dt->A && (dt->A->id != first || dt->len <= 5))
	{
		if (sorted(dt) == 1)
		{
			find_top(dt);
			return ;
		}
		//else if (dt->A->nxt && dt->A->nxt->id > last && dt->A->nxt->id < dt->A->id)
		else if (dt->len < 6 && dt->A->nxt && dt->A->nxt->id < dt->A->id)
			ft_stack_sa(dt);
		else if (dt->A->id > last && dt->A->mv == dt->ph1)
		{	
			last = dt->A->id;
			if (dt->B && dt->B->nxt && dt->B->id > (dt->len / 2))
				ft_stack_rr(dt);
			else
				ft_stack_ra(dt);
			dt->ph1--;
		}
		else if (dt->B && dt->B->id > (dt->len / 2))
		{
			if (dt->B->nxt)
				ft_stack_rb(dt);
			ft_stack_pb(dt);
		}
		else
			ft_stack_pb(dt);
	}
	if (dt->B && dt->B->id >= (dt->len / 2))
		ft_stack_rb(dt);
	find_top(dt);
}


// int ft_phase1_sorted(t_pushswap *dt)
// {
// 	t_stack		*tmp;

// 	tmp = dt->A;
// 	while (tmp->nxt != NULL && tmp->nxt->id > tmp->id)
// 			tmp = tmp->nxt;
// 	if (tmp->nxt == NULL)
// 		return (1);
// 	return (0);
// }

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