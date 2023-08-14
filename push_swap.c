/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:31 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/14 13:47:07 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pushswap	*ft_ini(int argn, char *argc[])
{
	t_pushswap	*dt;

	if (argn < 2)
		return (NULL);
	dt = ft_ini_dt();
	if (!dt || ft_ini_a(argn, argc, dt) == 0)
		return (ft_error());
	if (ft_ini_inputcheck(dt) == 0)
		return (ft_error());
	ft_ini_dtdata(dt);
	ft_ini_id(dt);
	if (dt->len < 26)
		ft_ini_mv(dt);
	return (dt);
}

void	ft_cleanup(t_pushswap *dt)
{
	t_stack		*tmp;
	t_stack		*nxt;

	tmp = dt->a;
	while (tmp)
	{
		nxt = tmp->nxt;
		free(tmp);
		tmp = nxt;
	}
	tmp = dt->b;
	while (tmp)
	{
		nxt = tmp->nxt;
		free(tmp);
		tmp = nxt;
	}
	free(dt);
	dt = NULL;
}

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
		mvb(dt);
		while (dt->a)
			do_the_next_best_move(dt);
		sortb(dt);
	}
	else
		ft_shortphase(dt);
	ft_cleanup(dt);
	return (1);
}
