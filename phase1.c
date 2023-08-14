/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 16:11:47 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/14 13:38:18 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_top(t_pushswap *dt)
{
	t_stack		*tmp;

	tmp = dt->a;
	while (tmp)
	{
		if (tmp->id < dt->top)
			dt->top = tmp->id;
		tmp = tmp->nxt;
	}
}

int	sorted(t_pushswap *dt)
{
	t_stack		*tmp;

	tmp = dt->a;
	while (tmp->nxt && tmp->nxt->id > tmp->id)
		tmp = tmp->nxt;
	if (!tmp->nxt)
		return (1);
	else if (tmp->nxt->id < tmp->id)
		tmp = tmp->nxt;
	while (tmp->nxt && tmp->nxt->id > tmp->id && tmp->id < dt->a->id)
		tmp = tmp->nxt;
	if (!tmp->nxt && tmp->id < dt->a->id)
		return (1);
	return (0);
}

int	ft_phase1_(int last, t_pushswap *dt)
{
	if (dt->len < 6 && dt->a->nxt && dt->a->nxt->id < dt->a->id)
		ft_stack_sa(dt);
	else if (dt->a->id > last && dt->a->mv == dt->ph1)
	{	
		last = dt->a->id;
		if (dt->b && dt->b->nxt && dt->b->id > (dt->len / 2))
			ft_stack_rr(dt);
		else
			ft_stack_ra(dt);
		dt->ph1--;
	}
	else if (dt->b && dt->b->id > (dt->len / 2))
	{
		if (dt->b->nxt)
			ft_stack_rb(dt);
		ft_stack_pb(dt);
	}
	else
		ft_stack_pb(dt);
	return (last);
}

void	ft_phase1(t_pushswap *dt)
{
	int		first;
	int		last;

	if (sorted(dt) == 1)
		return ;
	while (dt->a->mv != dt->ph1)
		ft_stack_pb(dt);
	first = dt->a->id;
	last = first;
	if (dt->len > 3)
		ft_stack_ra(dt);
	dt->ph1--;
	while (dt->a && (dt->a->id != first || dt->len <= 5))
	{
		if (sorted(dt) == 1)
		{
			find_top(dt);
			return ;
		}
		last = ft_phase1_(last, dt);
	}
	if (dt->b && dt->b->id >= (dt->len / 2))
		ft_stack_rb(dt);
	find_top(dt);
}
