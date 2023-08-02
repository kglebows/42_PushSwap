/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_reverseRotate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:46:07 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/02 17:55:16 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_stack_rra(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->A;
	last = ft_stacklast(dt->A);
	dt->A = last;
	dt->A->nxt = tmp;
	while (tmp->nxt != last)
		tmp = tmp->nxt;
	tmp->nxt = NULL;
	dt->cnt++;
	write(1, "rra\n", 4);
}
void ft_stack_rrb(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->B;
	last = ft_stacklast(dt->B);
	dt->B = last;
	dt->B->nxt = tmp;
	while (tmp->nxt != last)
		tmp = tmp->nxt;
	tmp->nxt = NULL;
	dt->cnt++;
	write(1, "rrb\n", 4);
}

void ft_stack_rrr(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->A;
	last = ft_stacklast(dt->A);
	dt->A = last;
	dt->A->nxt = tmp;
	while (tmp->nxt != last)
		tmp = tmp->nxt;
	tmp->nxt = NULL;
	tmp = dt->B;
	last = ft_stacklast(dt->B);
	dt->B = last;
	dt->B->nxt = tmp;
	while (tmp->nxt != last)
		tmp = tmp->nxt;
	tmp->nxt = NULL;
	dt->cnt++;
	write(1, "rrr\n", 4);
}
