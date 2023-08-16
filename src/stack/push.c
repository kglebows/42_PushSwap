/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:45:58 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/16 18:29:04 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_pb(int mute, t_pushswap *dt)
{
	t_stack			*tmp;

	if (dt->a)
	{
		tmp = dt->a->nxt;
		dt->a->nxt = dt->b;
		dt->b = dt->a;
		dt->a = tmp;
		dt->alen--;
	}
	dt->cnt++;
	if (mute == 0)
		write(1, "pb\n", 3);
}

void	ft_stack_pa(int mute, t_pushswap *dt)
{
	t_stack			*tmp;

	if (dt->b)
	{
		tmp = dt->b->nxt;
		dt->b->nxt = dt->a;
		dt->a = dt->b;
		dt->b = tmp;
		if (dt->a->id < dt->top)
			dt->top = dt->a->id;
		dt->alen++;
	}
	dt->cnt++;
	if (mute == 0)
		write(1, "pa\n", 3);
}
