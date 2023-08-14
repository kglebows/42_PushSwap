/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverseRotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:46:07 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/14 13:45:44 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_rra(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->a;
	last = ft_stacklast(dt->a);
	dt->a = last;
	dt->a->nxt = tmp;
	while (tmp->nxt != last)
		tmp = tmp->nxt;
	tmp->nxt = NULL;
	dt->cnt++;
	write(1, "rra\n", 4);
}

void	ft_stack_rrb(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->b;
	last = ft_stacklast(dt->b);
	dt->b = last;
	dt->b->nxt = tmp;
	while (tmp->nxt != last)
		tmp = tmp->nxt;
	tmp->nxt = NULL;
	dt->cnt++;
	write(1, "rrb\n", 4);
}

void	ft_stack_rrr(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->a;
	last = ft_stacklast(dt->a);
	dt->a = last;
	dt->a->nxt = tmp;
	while (tmp->nxt != last)
		tmp = tmp->nxt;
	tmp->nxt = NULL;
	tmp = dt->b;
	last = ft_stacklast(dt->b);
	dt->b = last;
	dt->b->nxt = tmp;
	while (tmp->nxt != last)
		tmp = tmp->nxt;
	tmp->nxt = NULL;
	dt->cnt++;
	write(1, "rrr\n", 4);
}
