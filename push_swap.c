/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:31 by kglebows          #+#    #+#             */
/*   Updated: 2023/06/26 18:53:17 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

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
	test_print_stacks(dt);
	// ft_cleanup(&dt);
	return (0);
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
	// ft_ini_phase1(dt);
	return (dt);
}

/*
void ft_ini_phase1(t_pushswap *dt)
{
	
	ToDo:
	- find phase 1 id (assign number of the sorted elements to mv, then find the biggest mv, assign to dt phase1_id)
	
}

void ft_stack_pa(t_pushswap *dt)
{
	
}
void ft_stack_pb(t_pushswap *dt)
{
	
}
void ft_stack_ra(t_pushswap *dt)
{
	
}
void ft_stack_rb(t_pushswap *dt)
{
	
}
void ft_stack_rr(t_pushswap *dt)
{
	
}
void ft_stack_rra(t_pushswap *dt)
{
	
}
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