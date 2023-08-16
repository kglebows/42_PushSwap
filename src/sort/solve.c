/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 13:10:51 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/16 16:17:56 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	mvb_(t_pushswap *dt, t_stack *tmp, int cnt, int rot)
{
	if (cnt < dt->alen / 2)
	{
		tmp->rt = rot * -1;
		rot++;
	}
	if (cnt == dt->alen / 2 && dt->alen % 2 == 1)
		rot++;
	if (cnt == dt->alen / 2)
		cnt++;
	if (cnt > dt->alen / 2)
	{
		tmp->rt = rot;
		rot--;
	}
	return (rot);
}

void	mvb(t_pushswap *dt)
{
	t_stack			*tmp;
	int				rot;
	int				cnt;

	rot = 0;
	cnt = 0;
	tmp = dt->a;
	while (tmp)
	{
		tmp->mv = ft_distance(tmp->id, dt);
		rot = mvb_(dt, tmp, cnt, rot);
		if (cnt == dt->alen / 2)
			cnt++;
		cnt++;
		tmp = tmp->nxt;
	}
}

void	sortb(t_pushswap *dt)
{
	int		turn;

	turn = ft_distance(0, dt);
	while (turn != 0)
	{
		if (turn > 0)
		{
			ft_stack_rb(0, dt);
			turn--;
		}
		if (turn < 0)
		{
			ft_stack_rrb(0, dt);
			turn++;
		}
	}
	while (dt->b)
		ft_stack_pa(0, dt);
}

void	ft_solve(t_pushswap *dt)
{
	if (dt->len > 25)
	{
		ft_stack_pb(0, dt);
		ft_stack_pb(0, dt);
		mvb(dt);
		while (dt->a)
		{
			ft_sort(dt);
			mvb(dt);
		}
		sortb(dt);
	}
	else
	{
		ft_presorted(dt);
		ft_phase1(dt);
		ft_phase2(dt);
	}
}
