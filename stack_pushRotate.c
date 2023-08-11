/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_pushRotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:45:58 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/11 13:04:25 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_stack_pb(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->A->nxt;
	dt->A->nxt = dt->B;
	last = ft_stacklast(dt->B);
	dt->B = dt->A;
	dt->A = tmp;
	dt->cnt++;
	dt->Alen--;
	dt->Blen++;
	write(1, "pb\n", 3);
}
void ft_stack_pa(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->B->nxt;
	dt->B->nxt = dt->A;
	last = ft_stacklast(dt->A);
	dt->A = dt->B;
	dt->B = tmp;
	if (dt->A->id < dt->top)
		dt->top = dt->A->id;
	dt->cnt++;
	dt->Alen++;
	dt->Blen--;
	write(1, "pa\n", 3);
}
void ft_stack_ra(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->A;
	dt->A = dt->A->nxt;
	last = ft_stacklast(dt->A);
	last->nxt = tmp;
	tmp->nxt = NULL;
	dt->cnt++;
	write(1, "ra\n", 3);
}
void ft_stack_rb(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	if (dt->B->nxt)
	{
		tmp = dt->B;
		dt->B = dt->B->nxt;
		last = ft_stacklast(dt->B);
		last->nxt = tmp;
		tmp->nxt = NULL;
		dt->cnt++;
		write(1, "rb\n", 3);	
	}
	else
		ft_Error();
}
void ft_stack_rr(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->A;
	dt->A = dt->A->nxt;
	last = ft_stacklast(dt->A);
	last->nxt = tmp;
	tmp->nxt = NULL;
	tmp = dt->B;
	dt->B = dt->B->nxt;
	last = ft_stacklast(dt->B);
	last->nxt = tmp;
	tmp->nxt = NULL;
	dt->cnt++;
	write(1, "rr\n", 3);
}
