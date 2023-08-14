/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:31 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/14 14:35:31 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argn, char *argc[])
{
	t_pushswap		*dt;

	dt = ft_ini(argn, argc);
	if (!dt)
		return (0);
	if (dt->len > 25)
	{
		ft_stack_pb(dt);
		ft_stack_pb(dt);
		ft_mvb(dt);
		while (dt->a)
			ft_do_the_next_best_move(dt);
		ft_sortb(dt);
	}
	else
		ft_shortphase(dt);
	ft_cleanup(dt);
	return (1);
}
