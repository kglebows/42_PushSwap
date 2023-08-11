/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:30:33 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/11 15:32:46 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int best(int rB, int rA)
{
	if (abs(rA) > abs(rB))
		return(abs(rA + rB) + abs(rA));
	else
		return(abs(rA + rB) + abs(rB));
}

void find_the_next_best_move(t_pushswap *dt)
{
	t_stack			*tmp;

	tmp = dt->A;
	dt->ph1 = tmp->mv;
	dt->top = tmp->rt;
	while (tmp)
	{
		if (best(tmp->mv, tmp->rt) < best(dt->ph1, dt->top))
		{
			dt->ph1 = tmp->mv;
			dt->top = tmp->rt;
		}
		tmp = tmp->nxt;
	}
}

void single_rotations(t_pushswap *dt)
{
	if (dt->ph1 > 0)
	{
		ft_stack_rb(dt);
		if (!dt->B->nxt)
			ft_stack_pb(dt);
		dt->ph1--;
	}
	else if (dt->ph1 < 0)
	{
		ft_stack_rrb(dt);
		dt->ph1++;
	}
	else if (dt->top > 0)
	{
		ft_stack_rra(dt);
		dt->top--;
	}
	else if (dt->top < 0)
	{
		ft_stack_ra(dt);
		dt->top++;
	}
}

void do_the_next_best_move(t_pushswap *dt)
{
	find_the_next_best_move(dt);
	while (dt->ph1 != 0 || dt->top != 0)
	{
		if (dt->ph1 > 0 && dt->top < 0)
		{
			ft_stack_rr(dt);
			dt->ph1--;
			dt->top++;
		}
		else if (dt->ph1 < 0 && dt->top > 0)
		{
			ft_stack_rrr(dt);
			dt->ph1++;
			dt->top--;
		}
		else
			single_rotations(dt);
	}
	ft_stack_pb(dt);
	mvB(dt);
}
