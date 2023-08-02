/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:31 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/02 20:33:20 by kglebows         ###   ########.fr       */
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

	// test(dt);
	
	ft_phase1(dt);
	if (dt->len > 25)
	{
		ft_phase2(dt);
		ft_phase3(dt);
		ft_phase4(dt);
		ft_phase5(dt);
	}
	else
		ft_shortphase(dt);

	
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
	ft_ini_mv(dt);
	return (dt);
}
