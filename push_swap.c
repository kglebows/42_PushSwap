/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:31 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/11 14:11:36 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argn, char *argc[])
{
	t_pushswap		*dt;

	dt = ft_ini(argn, argc);
	if (!dt)
		return (0);
	// ft_phase1(dt);
	// ft_phase2(&dt);
	// ft_phase3(&dt);
	// ft_result(&dt);
	// ft_cleanup(&dt);
	// ft_stack_pb(dt);
	//  test_input(dt);
	// test(dt);
	// distance_tester(dt);
	// test_stacks (dt);
	// if (dt->len > 120)
	// 	ft_phase500(dt);
	// else
	// 	ft_phase1(dt);
	// if (dt->len > 25)
	// {
	// 	ft_phase2(dt);
	// 	ft_phase3(dt);
	// 	ft_phase4(dt);
	// 	ft_phase5(dt);
	// }
	// else
	// 	ft_shortphase(dt);

	// sortB(dt);
	// test_stacks(dt);
	// ft_stack_pb(dt);
	// ft_stack_pb(dt);
	// test_stacks(dt);
	
	mvB(dt);
	while (dt->A)	
		do_the_next_best_move(dt);

	
	sortB(dt);

	// test_stacks(dt);
	
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
	// if (ft_ini_inputcheck(dt) == 0)
	// 	return (NULL);
	ft_ini_dtdata(dt);
	ft_ini_id(dt);
	if (dt->len < 110)
		ft_ini_mv(dt);
	// else
		// mvB(dt);
	return (dt);
}
