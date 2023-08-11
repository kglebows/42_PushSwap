/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/09 11:30:33 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/11 14:17:34 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int sw(int first, int next)
{
	if (first < 0)
		first = first * -1;
	if (next < 0)
		next = next * -1;
	if (next < first)
		return (first);
	return (0);
}

void stepB(t_pushswap *dt)
{
	int			k;
	int			first;
	int			next;
	// int			skip;

	k = 6;
	first = distanceB(dt->A->id, dt);
	if (dt->A->nxt)
		next = distanceB(dt->A->nxt->id, dt);
	else
		next = -9999999;
	// skip = sw(first, next);
	// if (skip > dt->len / k)
	// 	ft_stack_ra(dt);
	// else if (skip > 0)
	// 	ft_stack_sa(dt);
	// else if (first == 0)
	// 	ft_stack_pb(dt);
	// else
	// {
		while (first < -25 || first > 25)
		{
			if (first > 0)
			{
				ft_stack_rb(dt);
				first--;
			}
			if (first < 0)
			{
				ft_stack_rrb(dt);
				first++;
			}
		}
		ft_stack_pb(dt);
	}
// }

void mvB(t_pushswap *dt)
{
	t_stack			*tmp;
	int				rot;
	int				cnt;

	rot = 0;
	cnt = 0;
	tmp = dt->A;
	while (tmp)
	{
		tmp->mv = distanceB(tmp->id, dt);
		// printf("Alen:%d\n", dt->Alen);
		if (cnt < dt->Alen / 2)
		{
			tmp->rt = rot * -1;
			rot++;
		}
		if (cnt == dt->Alen / 2 && dt->Alen % 2 == 1)
			rot++;
		if (cnt == dt->Alen / 2)
			cnt++;
		if (cnt > dt->Alen / 2)
		{
			tmp->rt = rot;
			rot--;
		}
		cnt++;
		tmp = tmp->nxt;
	}
}

void sortB(t_pushswap *dt)
{
	int		turn;

	turn = distanceB(0, dt);
	while (turn != 0)
	{
		if (turn > 0)
		{
			ft_stack_rb(dt);
			turn--;
		}
		if (turn < 0)
		{
			ft_stack_rrb(dt);
			turn++;
		}
	}
	while (dt->B)
		ft_stack_pa(dt);
}

int abs(int n)
{
	if (n < 0)
		n *= -1;
	return (n);
}

int best(int rB, int rA)
{
	if (abs(rA) > abs(rB))
		return(abs(rA + rB) + abs(rA));
	else
		return(abs(rA + rB) + abs(rB));
}

void find_the_next_best_move(t_pushswap *dt)
{
	t_stack			*tmp;

	tmp = dt->A;
	dt->ph1 = tmp->mv;
	dt->top = tmp->rt;
	while (tmp)
	{
		if (best(tmp->mv, tmp->rt) < best(dt->ph1, dt->top))
		{
			dt->ph1 = tmp->mv;
			dt->top = tmp->rt;
		}
		tmp = tmp->nxt;
	}
	// printf("best move: %d %d\n", dt->ph1, dt->top);
	// if (abs(dt->ph1 + dt->top) > 24)
	// {
	// 	ft_stack_pb(dt);
	// 	mvB(dt);
	// 	find_the_next_best_move(dt);
	// }
}

void single_rotations(t_pushswap *dt)
{
	if (dt->B->nxt && dt->ph1 > 0)
	{
		ft_stack_rb(dt);
		dt->ph1--;
	}
	else if (dt->B->nxt && dt->ph1 < 0)
	{
		ft_stack_rrb(dt);
		dt->ph1++;
	}
	else if (dt->A->nxt && dt->top > 0)
	{
		ft_stack_rra(dt);
		dt->top--;
	}
	else if (dt->A->nxt && dt->top < 0)
	{
		ft_stack_ra(dt);
		dt->top++;
	}
	else
		ft_Error();
}

void do_the_next_best_move(t_pushswap *dt)
{
	find_the_next_best_move(dt);
	while (dt->ph1 != 0 || dt->top != 0)
	{
		if (dt->B->nxt && dt->A->nxt && dt->ph1 > 0 && dt->top < 0)
		{
			ft_stack_rr(dt);
			dt->ph1--;
			dt->top++;
		}
		else if (dt->B->nxt && dt->A->nxt && dt->ph1 < 0 && dt->top > 0)
		{
			ft_stack_rrr(dt);
			dt->ph1++;
			dt->top--;
		}
		else
			single_rotations(dt);
	}
	ft_stack_pb(dt);
	mvB(dt);
}
