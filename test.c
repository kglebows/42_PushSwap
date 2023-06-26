/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:44:50 by kglebows          #+#    #+#             */
/*   Updated: 2023/06/26 21:09:38 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void test(t_pushswap *dt)
{
	test_input(dt);
	ft_stack_pb(dt);
	test_stacks(dt);
	ft_stack_pa(dt);
	test_stacks(dt);
	ft_stack_pb(dt);
	test_stacks(dt);
}

void test_input(t_pushswap *dt)
{
	t_stack			*tmp;

	printf("::::: max :%4d :::::\n", dt->max);
	printf("::::: min :%4d :::::\n", dt->min);
	printf("::::: len :%4d :::::\n", dt->len);
	printf("::::: ph1 :%4d :::::\n", dt->ph1);
	printf(":::::: Stack A ::::::\n");
	printf("::  id :  nb :  mv ::\n");
	tmp = dt->A;
	while (tmp->nxt != dt->A)
	{
		printf("::%4d :%4d :%4d ::\n", tmp->id, tmp->nb, tmp->mv);
		tmp = tmp->nxt;
	}
	printf("::%4d :%4d :%4d ::\n", tmp->id, tmp->nb, tmp->mv);
	printf(":::::::::::::::::::::\n");
}

void test_stacks(t_pushswap *dt)
{
	t_stack			*tmp;

	printf(":Stack A:\n");
	tmp = dt->A;
	while (tmp->nxt != dt->A)
	{
		printf(": %5d :\n", tmp->id);
		tmp = tmp->nxt;
	}
	printf(": %5d :\n", tmp->id);
	printf(":Stack B:\n");
	tmp = dt->B;
	while (tmp->nxt != NULL)
	{
		printf(": %5d :\n", tmp->id);
		tmp = tmp->nxt;
	}
	printf(": %5d :\n", tmp->id);
}

