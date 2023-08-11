/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:18:13 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/11 15:54:41 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int distance(int id, t_pushswap *dt)
{
	t_stack		*tmp;
	int			r;
	int			len;
	int			last;

	r = 0;
	len = 1;
	tmp = dt->A;
	while (tmp->nxt)
	{
		len++;
		tmp = tmp->nxt;
	}
	last = tmp->id;
	tmp = dt->A;
	if (tmp->id > id && last < id)
		return (0);
	while (tmp)
	{
		if (dt->top > id && tmp->id == dt->top)
			break;
		r++;
		if (tmp->nxt && tmp->id < id && tmp->nxt->id > id)
			break;
		if (tmp->nxt && tmp->nxt->id == dt->top && tmp->id < id)
			break;
		tmp = tmp->nxt;
	}
	if (r <= len - r)
		return (r);
	else
		return ((len - r) * -1);
}

int swap(int first, int next)
{
	if (first < 0)
		first = first * -1;
	if (next < 0)
		next = next * -1;
	if (next < first)
		return (1);
	return (0);
}

int sort(int top, int bot, t_pushswap *dt)
{
	int		dist;

	if (dt->B->id > bot)
		ft_stack_rb(dt);
	else
	{
		dist = distance(dt->B->id, dt);
		if (dt->B->nxt && dt->B->nxt->id <= bot && swap(dist, distance(dt->B->nxt->id, dt)))
			ft_stack_sb(dt);
		else if (dist == 0)
			ft_stack_pa(dt);
		else if (dist > 0)
		{
			while (dist > 0)
			{
				ft_stack_ra(dt);
				dist--;
			}
			ft_stack_pa(dt);
		}
		else
		{
			while (dist < 0)
			{
				ft_stack_rra(dt);
				dist++;
			}
			ft_stack_pa(dt);
		}
		if (dt->A->id < top)
			top = dt->A->id;
	}
	return (top);
}

void ft_shortphase(t_pushswap *dt)
{
	int		top;
	int		bot;

	ft_phase1(dt);
	bot = dt->len;
	top = 1;
	while (dt->B)
		top = sort(top, bot, dt);
	if (dt->A->id == 1)
		return ;
	if (distance(0, dt) > 0)
	{
		while (dt->A->id != 1)
			ft_stack_ra(dt);
	}
	else
	{
		while (dt->A->id != 1)
			ft_stack_rra(dt);
	}
}
