/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:44:50 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/11 12:26:17 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void distance_test(t_pushswap *dt)
{
	int		test;

	test_stacks(dt);
	test = distanceA(1, dt);
	printf("dla 1: %d\n", test);
	test = distanceA(3, dt);
	printf("dla 3: %d\n", test);
	test = distanceA(5, dt);
	printf("dla 5: %d\n", test);
	test = distanceA(7, dt);
	printf("dla 7: %d\n", test);
	test = distanceA(9, dt);
	printf("dla 9: %d\n", test);
	test = distanceA(11, dt);
	printf("dla 11: %d\n", test);
}

void distance_tester(t_pushswap *dt)
{
	// for input : ./push_swap 1 2 3 4 5 6 7 8 9 10 
	// ft_stack_ra(dt);
	ft_stack_pb(dt);
	ft_stack_ra(dt);
	ft_stack_pb(dt);
	ft_stack_ra(dt);
	ft_stack_pb(dt);
	ft_stack_ra(dt);
	ft_stack_pb(dt);
	ft_stack_ra(dt);
	ft_stack_pb(dt);
	distance_test(dt);
	ft_stack_rrb(dt);
	distance_test(dt);
	ft_stack_rrb(dt);
	distance_test(dt);
	ft_stack_rrb(dt);
	ft_stack_rrb(dt);
	distance_test(dt);
}

void test(t_pushswap *dt)
{

	test_input(dt);
	if (dt->len > 110)
		sortB(dt);
	else
		ft_phase1(dt);
	test_stacks(dt);
	printf("---ph1\n");
	if (dt->len > 25)
	{
		ft_phase2(dt);
		test_stacks(dt);
		printf("---ph2\n");
		ft_phase3(dt);
		test_stacks(dt);
		printf("---ph3\n");
		ft_phase4(dt);
		test_stacks(dt);
		printf("---ph4\n");
		ft_phase5(dt);
		test_stacks(dt);
		printf("---ph5\n");	
	}
	else
	{
		ft_shortphase(dt);
		test_stacks(dt);
		printf("---short\n");	
	}
}

void test_input(t_pushswap *dt)
{
	t_stack			*tmp;

	printf("::::::Push Swap::::::\n");
	printf("::::: max :%4d :::::\n", dt->max);
	printf("::::: min :%4d :::::\n", dt->min);
	printf("::::: len :%4d :::::\n", dt->len);
	printf("::::: ph1 :%4d :::::\n", dt->ph1);
	printf("::::::::INPUT::::::::\n");
	printf("::  id :  nb :  mv ::\n");
	tmp = dt->A;
	while (tmp != NULL)
	{
		printf("::%4d :%4d :%4d ::\n", tmp->id, tmp->nb, tmp->mv);
		tmp = tmp->nxt;
	}
	printf(":::::::::::::::::::::\n");
}

void test_stacks(t_pushswap *dt)
{
	t_stack			*A;
	t_stack			*B;

	printf("::: A ::: B :::\n");
	A = dt->A;
	B = dt->B;
	while (A || B)
	{
		if (A)
			printf(": %4d ", A->id);
		else
			printf(":      ");
		if (B)
			printf(": %4d :", B->id);
		else
			printf(":      :");
		if (A)
			printf("%4d.%4d\n", A->rt, A->mv);
		else
			printf("\n");
		if (A)
			A = A->nxt;
		if (B)
			B = B->nxt;
	}
	printf(":::::%5d:::::\n", dt->cnt);
}

