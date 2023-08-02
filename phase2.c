/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:18:13 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/02 19:34:51 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#include <stdio.h>

int distance_(int id, t_pushswap *dt)
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
	if (tmp->id == dt->top || distance != 0)
		return (distance);
	while (tmp->id != dt->top)
		tmp = tmp->nxt;
	while (tmp)
	{
		if (tmp->id > id)
			distance++;
		tmp = tmp->nxt;
	}
	return (distance * -1);
}

int distance_end(int id, int top, t_pushswap *dt)
{
	t_stack		*tmp;
	int			distance_top;
	int			distance_bot;

	distance_top = 0;
	distance_bot = 0;
	tmp = dt->A;
	while (tmp && tmp->id < id && tmp->id != 1)
	{
		distance_top++;
		tmp = tmp->nxt;
	}
	while (tmp && tmp->id != top)
		tmp = tmp->nxt;
	while (tmp)
	{
		if (tmp->id > id)
			distance_bot--;
		tmp = tmp->nxt;
	}
	if (distance_bot == 0)
		return (distance_top);
	else
		return (distance_bot);
}

int distance__(int id, t_pushswap *dt)
{
	t_stack		*tmp;
	int			r;
	int			rr;

	r = 0;
	rr = 0;
	tmp = dt->A;
	while (tmp && tmp->nxt)
	{
		if (dt->top > id && tmp->id == dt->top)
			break;
		r++;
		if (tmp->id < id && tmp->nxt->id > id)
			break;
		if (tmp->nxt->id == dt->top && tmp->id < id)
			break;
		tmp = tmp->nxt;
	}
	if (tmp && !tmp->nxt && tmp->id > id)
		rr++;
	while (tmp && tmp->nxt)
	{
		rr++;
		tmp = tmp->nxt;
	}
	// printf("r%d : rr%d\n", r, rr);
	if (tmp && dt->A->id > id && tmp->id < id)
		return (0);
	if (r <= rr)
		return (r);
	else
		return (rr * -1);
}

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
	// if ((tmp->id == 1 && id > last) || (tmp->id > id && last < id) || (tmp->id < id && last > id))
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
	// printf("r%d : rr%d\n", r, len - r);
	// test_stacks(dt);
	// if (tmp && dt->A->id > id && tmp->id < id)
	// 	return (0);
	if (r <= len - r)
		return (r);
	else
		return ((len - r) * -1);
}


int swap(int first, int next)
{
	//  printf("%d :: %d\n", first, next);
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
		// test_stacks(dt);
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

int sort_end(int top, int bot, t_pushswap *dt)
{
	int		dist;

	if (dt->B->id >= bot)
		ft_stack_rb(dt);
	else
	{
		dist = distance(dt->B->id, dt);
		if (dt->B->nxt->id < bot && swap(dist, distance(dt->B->nxt->id, dt)))
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
	top = 1;
	while (dt->B->id >= (dt->len / 2))
		top = sort(top, bot, dt);
	while (dt->A->id > dt->len / 4)
		ft_stack_rra(dt);
	
}

void ft_phase4(t_pushswap *dt)
{
	int		top;
	int		bot;

	bot = dt->len / 2;
	top = dt->A->id;
	while (dt->B->id < (dt->len / 2))
		top = sort(top, bot, dt);
	while (dt->A->id < dt->len / 2 + dt->len / 4)
		ft_stack_rra(dt);
}

void ft_phase5(t_pushswap *dt)
{
	int		top;
	int		bot;

	bot = dt->len;
	top = (dt->len / 2) + (dt->len / 4);
	while (dt->B)
	{
		top = sort(top, bot, dt);
	}
	
	while (dt->A->id != 1)
		ft_stack_ra(dt);
	// ft_stack_pa(dt);
	// ft_stack_ra(dt);
}

void ft_shortphase(t_pushswap *dt)
{
	int		top;
	int		bot;

	bot = dt->len;
	top = 1;
	while (dt->B)
		top = sort(top, bot, dt);
	if (dt->A->id == 1)
		return ;
	//    test_stacks(dt);
	if (distance(0, dt) > 0)
	{
		while (dt->A->id != 1)
			ft_stack_ra(dt);
	}
	else
	{
		while (dt->A->id != 1)
		{
			ft_stack_rra(dt);
			// test_stacks(dt);
		}
	}
}