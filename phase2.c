/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:18:13 by kglebows          #+#    #+#             */
/*   Updated: 2023/07/27 14:17:45 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int distance(int id, int top, t_pushswap *dt)
{
	t_stack		*tmp;
	int			distance;

	distance = 0;
	tmp = dt->A;
	while (tmp && tmp->id < id)
	{
		distance++;
		tmp = tmp->nxt;
	}
	tmp = dt->A;
	if (tmp->id == top || distance != 0)
		return (distance);
	while (tmp->id != top)
		tmp = tmp->nxt;
	while (tmp)
	{
		if (tmp->id > id)
			distance++;
		tmp = tmp->nxt;
	}
	return (distance * -1);
}

int swap(int first, int next)
{
	if (first < 0)
		first = first * -1;
	if (next < 0)
		next = next * -1;
	if (next + 1 < first)
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
		dist = distance(dt->B->id, top, dt);
		if (dt->B->nxt->id <= bot && swap(dist, distance(dt->B->nxt->id, top, dt)))
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

int find_top(int low, int high, t_pushswap *dt)
{
	t_stack		*tmp;
	int			top;

	tmp = dt->A;
	top = tmp->id;
	while (tmp)
	{
		if (tmp->id <= high && tmp->id >= low && tmp->id < top)
			top = tmp->id;
		tmp = tmp->nxt;
	}
	return (top);
}

int route(int low, int high, t_pushswap *dt)
{
	t_stack		*tmp;
	int			distance;

	distance = 0;
	tmp = dt->A;
	while (tmp->id < low)
	{
		distance++;
		tmp = tmp->nxt;
	}
	while (tmp->id < high)
		tmp = tmp->nxt;
	while (tmp)
	{
		distance--;
		tmp = tmp->nxt;
	}
	return (distance);
}

void ft_phase2(t_pushswap *dt)
{
	int		top;

	top = dt->A->id;
	while (dt->B->id <= (dt->len / 2))
		top = sort(top, (dt->len / 4), dt);
	if (route(dt->len / 2, (dt->len / 2) + (dt->len / 4), dt) < 0)
	{
		while (dt->A->id < dt->len / 2)
			ft_stack_ra(dt);
	}
	else
	{
		while (dt->A->id < ((dt->len / 2) + (dt->len / 4)))
			ft_stack_rra(dt);
		while (dt->A->id > ((dt->len / 2) + (dt->len / 4)))
			ft_stack_rra(dt);
	}
}

int stack_B_sorted(t_pushswap *dt)
{
	t_stack		*tmp;

	tmp = dt->B;
	while (tmp->nxt != NULL && tmp->nxt->id == tmp->id + 1)
			tmp = tmp->nxt;
	if (tmp->nxt == NULL)
		return (1);
	return (0);
}

void ft_phase3(t_pushswap *dt)
{
	int		top;
	int		bot;
	
	bot = dt->len / 2 + dt->len / 4;
	top = find_top(dt->len / 2, bot, dt);
	while (dt->B->id >= (dt->len / 2))
		top = sort(top, bot, dt);
	while (dt->A->id > dt->len / 4)
		ft_stack_rra(dt);
	bot = dt->len / 2;
	top = dt->A->id;
	while (dt->B->id <= (dt->len / 2))
		top = sort(top, bot, dt);
	while (dt->A->id < dt->len / 2 + dt->len / 4)
		ft_stack_rra(dt);
	bot = dt->len;
	top = (dt->len / 2) + (dt->len / 4);
	while (dt->B->nxt && stack_B_sorted(dt) == 0)
	{
		if (dt->B->id == dt->len)
			ft_stack_rb(dt);
		else
			top = sort(top, bot, dt);
	}
	while (dt->A->id != 1)
		ft_stack_ra(dt);
	while (dt->B)
	{
		ft_stack_rrb(dt);
		ft_stack_pa(dt);
	}
	while (dt->A->id != 1)
		ft_stack_ra(dt);
}

