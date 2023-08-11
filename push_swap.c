/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:31 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/11 16:12:03 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	if (dt->len < 26)
		ft_ini_mv(dt);
	return (dt);
}

void ft_cleanup(t_pushswap *dt)
{
	dt->len = 0;
}

int main(int argn, char *argc[])
{
	t_pushswap		*dt;

	dt = ft_ini(argn, argc); // tu jeszcze sprawdzic input
	if (!dt)
		return (0);
	if (dt->len > 25)
	{
		ft_stack_pb(dt);
		ft_stack_pb(dt);
		mvB(dt);
		while (dt->A)	
			do_the_next_best_move(dt);
		sortB(dt);
	}
	else
		ft_shortphase(dt);
	ft_cleanup(dt);
	return (1);
}