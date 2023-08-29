/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:46:07 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/29 13:26:42 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_rra(int mute, t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	if (dt->a && dt->a->nxt)
	{
		tmp = dt->a;
		last = ft_stack_last(dt->a);
		dt->a = last;
		dt->a->nxt = tmp;
		while (tmp->nxt != last)
			tmp = tmp->nxt;
		tmp->nxt = NULL;
	}
	dt->cnt++;
	if (mute == 0)
		write(1, "rra\n", 4);
}

void	ft_stack_rrb(int mute, t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	if (dt->b && dt->b->nxt)
	{
		tmp = dt->b;
		last = ft_stack_last(dt->b);
		dt->b = last;
		dt->b->nxt = tmp;
		while (tmp->nxt != last)
			tmp = tmp->nxt;
		tmp->nxt = NULL;
	}
	dt->cnt++;
	if (mute == 0)
		write(1, "rrb\n", 4);
}

void	ft_stack_rrr(int mute, t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	if (dt->b && dt->a && dt->a->nxt && dt->b->nxt)
	{
		tmp = dt->a;
		last = ft_stack_last(dt->a);
		dt->a = last;
		dt->a->nxt = tmp;
		while (tmp->nxt != last)
			tmp = tmp->nxt;
		tmp->nxt = NULL;
		tmp = dt->b;
		last = ft_stack_last(dt->b);
		dt->b = last;
		dt->b->nxt = tmp;
		while (tmp->nxt != last)
			tmp = tmp->nxt;
		tmp->nxt = NULL;
	}
	dt->cnt++;
	if (mute == 0)
		write(1, "rrr\n", 4);
}
