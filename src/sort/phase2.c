/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:18:13 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/16 15:34:34 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dista_(int id, int r, t_pushswap *dt)
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

int	dista(int id, t_pushswap *dt)
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
	r = dista_(id, r, dt);
	if (r <= len - r)
		return (r);
	else
		return ((len - r) * -1);
}

int	sort_(int dist, t_pushswap *dt)
{
	if (dist == 0)
		ft_stack_pa(0, dt);
	else if (dist > 0)
	{
		while (dist > 0)
		{
			ft_stack_ra(0, dt);
			dist--;
		}
		ft_stack_pa(0, dt);
	}
	else
	{
		while (dist < 0)
		{
			ft_stack_rra(0, dt);
			dist++;
		}
		ft_stack_pa(0, dt);
	}
	return (dist);
}

int	sort(int top, int bot, t_pushswap *dt)
{
	int		dist;

	if (dt->b->id > bot)
		ft_stack_rb(0, dt);
	else
	{
		dist = dista(dt->b->id, dt);
		if (dt->b->nxt && dt->b->nxt->id <= bot
			&& ft_swap(dist, dista(dt->b->nxt->id, dt)))
			ft_stack_sb(0, dt);
		else
			dist = sort_(dist, dt);
		if (dt->a->id < top)
			top = dt->a->id;
	}
	return (top);
}

void	ft_phase2(t_pushswap *dt)
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
	if (dista(0, dt) > 0)
	{
		while (dt->a->id != 1)
			ft_stack_ra(0, dt);
	}
	else
	{
		while (dt->a->id != 1)
			ft_stack_rra(0, dt);
	}
}
