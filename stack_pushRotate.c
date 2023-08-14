/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pushRotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:45:58 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/14 13:46:25 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_pb(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->a->nxt;
	dt->a->nxt = dt->b;
	last = ft_stacklast(dt->b);
	dt->b = dt->a;
	dt->a = tmp;
	dt->cnt++;
	dt->alen--;
	write(1, "pb\n", 3);
}

void	ft_stack_pa(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->b->nxt;
	dt->b->nxt = dt->a;
	last = ft_stacklast(dt->a);
	dt->a = dt->b;
	dt->b = tmp;
	if (dt->a->id < dt->top)
		dt->top = dt->a->id;
	dt->cnt++;
	dt->alen++;
	write(1, "pa\n", 3);
}

void	ft_stack_ra(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->a;
	dt->a = dt->a->nxt;
	last = ft_stacklast(dt->a);
	last->nxt = tmp;
	tmp->nxt = NULL;
	dt->cnt++;
	write(1, "ra\n", 3);
}

void	ft_stack_rb(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	if (dt->b->nxt)
	{
		tmp = dt->b;
		dt->b = dt->b->nxt;
		last = ft_stacklast(dt->b);
		last->nxt = tmp;
		tmp->nxt = NULL;
		dt->cnt++;
		write(1, "rb\n", 3);
	}
}

void	ft_stack_rr(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->a;
	dt->a = dt->a->nxt;
	last = ft_stacklast(dt->a);
	last->nxt = tmp;
	tmp->nxt = NULL;
	tmp = dt->b;
	dt->b = dt->b->nxt;
	last = ft_stacklast(dt->b);
	last->nxt = tmp;
	tmp->nxt = NULL;
	dt->cnt++;
	write(1, "rr\n", 3);
}
