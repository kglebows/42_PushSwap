/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:32:46 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/29 13:25:24 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_ra(int mute, t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	if (dt->a && dt->a->nxt)
	{
		tmp = dt->a;
		dt->a = dt->a->nxt;
		last = ft_stack_last(dt->a);
		last->nxt = tmp;
		tmp->nxt = NULL;
	}
	dt->cnt++;
	if (mute == 0)
		write(1, "ra\n", 3);
}

void	ft_stack_rb(int mute, t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	if (dt->b && dt->b->nxt)
	{
		tmp = dt->b;
		dt->b = dt->b->nxt;
		last = ft_stack_last(dt->b);
		last->nxt = tmp;
		tmp->nxt = NULL;
	}
	dt->cnt++;
	if (mute == 0)
		write(1, "rb\n", 3);
}

void	ft_stack_rr(int mute, t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	if (dt->a && dt->a->nxt)
	{
		tmp = dt->a;
		dt->a = dt->a->nxt;
		last = ft_stack_last(dt->a);
		last->nxt = tmp;
		tmp->nxt = NULL;
	}
	if (dt->b && dt->b->nxt)
	{
		tmp = dt->b;
		dt->b = dt->b->nxt;
		last = ft_stack_last(dt->b);
		last->nxt = tmp;
		tmp->nxt = NULL;
	}
	dt->cnt++;
	if (mute == 0)
		write(1, "rr\n", 3);
}
