/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:44:50 by kglebows          #+#    #+#             */
/*   Updated: 2023/06/26 18:45:22 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void test_print_stacks(t_pushswap *dt)
{
	t_stack			*tmp;

	printf("::::: max :%4d :::::\n", dt->max);
	printf("::::: min :%4d :::::\n", dt->min);
	printf("::::: len :%4d :::::\n", dt->len);
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

