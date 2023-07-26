/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:44:50 by kglebows          #+#    #+#             */
/*   Updated: 2023/07/26 20:56:55 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void test(t_pushswap *dt)
{
	test_input(dt);
	ft_phase1(dt);
	test_stacks(dt);
	ft_phase2(dt);
	test_stacks(dt);
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
			printf(": %4d :\n", B->id);
		else
			printf(":      :\n");
		if (A)
			A = A->nxt;
		if (B)
			B = B->nxt;
	}
	printf(":::::::::::::::\n");
}

