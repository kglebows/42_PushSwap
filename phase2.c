/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:18:13 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/14 14:38:27 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	distance_(int id, int r, t_pushswap *dt)
{
	t_stack		*tmp;

	tmp = dt->a;
	while (tmp)
	{
		if (dt->top > id && tmp->id == dt->top)
			break ;
		r++;
		if (tmp->nxt && tmp->id < id && tmp->nxt->id > id)
			break ;
		if (tmp->nxt && tmp->nxt->id == dt->top && tmp->id < id)
			break ;
		tmp = tmp->nxt;
	}
	return (r);
}

int	distance(int id, t_pushswap *dt)
{
	t_stack		*tmp;
	int			r;
	int			len;
	int			last;

	r = 0;
	len = 1;
	tmp = dt->a;
	while (tmp->nxt)
	{
		len++;
		tmp = tmp->nxt;
	}
	last = tmp->id;
	if (dt->a->id > id && last < id)
		return (0);
	r = distance_(id, r, dt);
	if (r <= len - r)
		return (r);
	else
		return ((len - r) * -1);
}

int	sort_(int dist, t_pushswap *dt)
{
	if (dist == 0)
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
	return (dist);
}

int	sort(int top, int bot, t_pushswap *dt)
{
	int		dist;

	if (dt->b->id > bot)
		ft_stack_rb(dt);
	else
	{
		dist = distance(dt->b->id, dt);
		if (dt->b->nxt && dt->b->nxt->id <= bot
			&& ft_swap(dist, distance(dt->b->nxt->id, dt)))
			ft_stack_sb(dt);
		else
			dist = sort_(dist, dt);
		if (dt->a->id < top)
			top = dt->a->id;
	}
	return (top);
}

void	ft_shortphase(t_pushswap *dt)
{
	int		top;
	int		bot;

	ft_phase1(dt);
	bot = dt->len;
	top = 1;
	while (dt->b)
		top = sort(top, bot, dt);
	if (dt->a->id == 1)
		return ;
	if (distance(0, dt) > 0)
	{
		while (dt->a->id != 1)
			ft_stack_ra(dt);
	}
	else
	{
		while (dt->a->id != 1)
			ft_stack_rra(dt);
	}
}
