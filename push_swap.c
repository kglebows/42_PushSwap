/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:31 by kglebows          #+#    #+#             */
/*   Updated: 2023/06/27 15:23:04 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argn, char *argc[])
{
	t_pushswap		*dt;

	dt = ft_ini(argn, argc);
	if (!dt)
		return (0);
	// ft_phase1(&dt);
	// ft_phase2(&dt);
	// ft_phase3(&dt);
	// ft_result(&dt);
	test(dt);
	// ft_cleanup(&dt);
	return (1);
}

t_pushswap *ft_ini(int argn, char *argc[])
{
	t_pushswap	*dt;

	if (argn < 2)
		return (NULL);
	dt = ft_ini_dt();
	if (!dt || ft_ini_A(argn, argc, dt) == 0)
		return (NULL);
	if (ft_ini_inputcheck(dt) == 0)
		return (NULL);
	ft_ini_dtdata(dt);
	ft_ini_id(dt);
	ft_ini_ph1(dt);
	return (dt);
}

void ft_stack_pb(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->A->nxt;
	dt->A->nxt = dt->B;
	last = ft_stacklast(dt->B);
	dt->B = dt->A;
	dt->A = tmp;
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
	write(1, "ra\n", 3);
}
void ft_stack_rb(t_pushswap *dt)
{
	t_stack			*tmp;
	t_stack			*last;

	tmp = dt->B;
	dt->B = dt->B->nxt;
	last = ft_stacklast(dt->B);
	last->nxt = tmp;
	tmp->nxt = NULL;
	write(1, "rb\n", 3);
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
	write(1, "rr\n", 3);
}
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
	write(1, "rra\n", 4);
}
/*
void ft_stack_rrb(t_pushswap *dt)
{
	
}
void ft_stack_rrr(t_pushswap *dt)
{
	
}
void ft_stack_sa(t_pushswap *dt)
{
	
}
void ft_stack_sb(t_pushswap *dt)
{
	
}
void ft_stack_ss(t_pushswap *dt)
{
	
}
*/