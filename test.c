/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:44:50 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/11 15:52:36 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

void distance_test(t_pushswap *dt)
{
	int		test;

	test_stacks(dt);
	test = distanceA(1, dt);
	printf("dla 1: %d\n", test);
	test = distanceA(3, dt);
	printf("dla 3: %d\n", test);
	test = distanceA(5, dt);
	printf("dla 5: %d\n", test);
	test = distanceA(7, dt);
	printf("dla 7: %d\n", test);
	test = distanceA(9, dt);
	printf("dla 9: %d\n", test);
	test = distanceA(11, dt);
	printf("dla 11: %d\n", test);
}

void distance_tester(t_pushswap *dt)
{
	// for input : ./push_swap 1 2 3 4 5 6 7 8 9 10 
	// ft_stack_ra(dt);
	ft_stack_pb(dt);
	ft_stack_ra(dt);
	ft_stack_pb(dt);
	ft_stack_ra(dt);
	ft_stack_pb(dt);
	ft_stack_ra(dt);
	ft_stack_pb(dt);
	ft_stack_ra(dt);
	ft_stack_pb(dt);
	distance_test(dt);
	ft_stack_rrb(dt);
	distance_test(dt);
	ft_stack_rrb(dt);
	distance_test(dt);
	ft_stack_rrb(dt);
	ft_stack_rrb(dt);
	distance_test(dt);
}

void test(t_pushswap *dt)
{

	test_input(dt);
	if (dt->len > 110)
		sortB(dt);
	else
		ft_phase1(dt);
	test_stacks(dt);
	printf("---ph1\n");
	if (dt->len > 25)
	{
		ft_phase2(dt);
		test_stacks(dt);
		printf("---ph2\n");
		ft_phase3(dt);
		test_stacks(dt);
		printf("---ph3\n");
		ft_phase4(dt);
		test_stacks(dt);
		printf("---ph4\n");
		ft_phase5(dt);
		test_stacks(dt);
		printf("---ph5\n");	
	}
	else
	{
		ft_shortphase(dt);
		test_stacks(dt);
		printf("---short\n");	
	}
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
			printf(": %4d :", B->id);
		else
			printf(":      :");
		if (A)
			printf("%4d.%4d\n", A->rt, A->mv);
		else
			printf("\n");
		if (A)
			A = A->nxt;
		if (B)
			B = B->nxt;
	}
	printf(":::::%5d:::::\n", dt->cnt);
}

// unused functions :

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
	skip = sw(first, next);
	if (skip > dt->len / k)
		ft_stack_ra(dt);
	else if (skip > 0)
		ft_stack_sa(dt);
	else if (first == 0)
		ft_stack_pb(dt);
	else
	{
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
}

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

void mvB_OLD(t_pushswap *dt)
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

void ft_phase500(t_pushswap *dt)
{
	int			step;
	int			smooth;
	int			last;
	int			first;

	step = dt->len * 0.06;
	last = 0;
	first = 0;
	while(dt->A->id != first)
	{
		smooth = 0;
		while(dt->A->id != first)
		{
			// if (dt->A->nxt && dt->A->nxt->id < dt->A->id)
			// {
			// 	if (dt->B && dt->B->nxt && dt->B->nxt->id > dt->B->id)
			// 		ft_stack_ss(dt);
			// 	else
			// 		ft_stack_sa(dt);
			// }
			if (dt->A->id > last && dt->A->id < last + step + smooth)
			{
				last = dt->A->id;
				if (first == 0)
					first = last;
				if (dt->B && dt->B->nxt && dt->B->id > dt->len / 2)
					ft_stack_rr(dt);
				else
					ft_stack_ra(dt);
			}
			else
				ft_stack_pb(dt);
			smooth++;
		}
	}
}

void ft_phase5(t_pushswap *dt)
{
	int		top;
	int		bot;

	bot = dt->len;
	top = (dt->len / 2) + (dt->len / 4);
	while (dt->B)
	{
		top = sort(top, bot, dt);
	}
	
	while (dt->A->id != 1)
		ft_stack_ra(dt);
	// ft_stack_pa(dt);
	// ft_stack_ra(dt);
}

void ft_phase3(t_pushswap *dt)
{
	int		top;
	int		bot;
	
	bot = dt->len / 2 + dt->len / 4;
	top = 1;
	while (dt->B->id >= (dt->len / 2))
		top = sort(top, bot, dt);
	while (dt->A->id > dt->len / 4)
		ft_stack_rra(dt);
	
}

void ft_phase4(t_pushswap *dt)
{
	int		top;
	int		bot;

	bot = dt->len / 2;
	top = dt->A->id;
	while (dt->B->id < (dt->len / 2))
		top = sort(top, bot, dt);
	while (dt->A->id < dt->len / 2 + dt->len / 4)
		ft_stack_rra(dt);
}

int distance_(int id, t_pushswap *dt)
{
	t_stack		*tmp;
	int			distance;

	distance = 0;
	tmp = dt->A;
	while (tmp && tmp->id < id)
	{
		distance++;
		tmp = tmp->nxt;
	}
	tmp = dt->A;
	if (tmp->id == dt->top || distance != 0)
		return (distance);
	while (tmp->id != dt->top)
		tmp = tmp->nxt;
	while (tmp)
	{
		if (tmp->id > id)
			distance++;
		tmp = tmp->nxt;
	}
	return (distance * -1);
}

int distance_end(int id, int top, t_pushswap *dt)
{
	t_stack		*tmp;
	int			distance_top;
	int			distance_bot;

	distance_top = 0;
	distance_bot = 0;
	tmp = dt->A;
	while (tmp && tmp->id < id && tmp->id != 1)
	{
		distance_top++;
		tmp = tmp->nxt;
	}
	while (tmp && tmp->id != top)
		tmp = tmp->nxt;
	while (tmp)
	{
		if (tmp->id > id)
			distance_bot--;
		tmp = tmp->nxt;
	}
	if (distance_bot == 0)
		return (distance_top);
	else
		return (distance_bot);
}

int distance__(int id, t_pushswap *dt)
{
	t_stack		*tmp;
	int			r;
	int			rr;

	r = 0;
	rr = 0;
	tmp = dt->A;
	while (tmp && tmp->nxt)
	{
		if (dt->top > id && tmp->id == dt->top)
			break;
		r++;
		if (tmp->id < id && tmp->nxt->id > id)
			break;
		if (tmp->nxt->id == dt->top && tmp->id < id)
			break;
		tmp = tmp->nxt;
	}
	if (tmp && !tmp->nxt && tmp->id > id)
		rr++;
	while (tmp && tmp->nxt)
	{
		rr++;
		tmp = tmp->nxt;
	}
	// printf("r%d : rr%d\n", r, rr);
	if (tmp && dt->A->id > id && tmp->id < id)
		return (0);
	if (r <= rr)
		return (r);
	else
		return (rr * -1);
}

int sort_end(int top, int bot, t_pushswap *dt)
{
	int		dist;

	if (dt->B->id >= bot)
		ft_stack_rb(dt);
	else
	{
		dist = distance(dt->B->id, dt);
		if (dt->B->nxt->id < bot && swap(dist, distance(dt->B->nxt->id, dt)))
			ft_stack_sb(dt);
		else if (dist == 0)
			ft_stack_pa(dt);
		else if (dist > 0)
		{
			while (dist > 0)
			{
				ft_stack_ra(dt);
				dist--;
			}
			ft_stack_pa(dt);
		}
		else
		{
			while (dist < 0)
			{
				ft_stack_rra(dt);
				dist++;
			}
			ft_stack_pa(dt);
		}
		if (dt->A->id < top)
			top = dt->A->id;
	}
	return (top);
}

void ft_phase2(t_pushswap *dt)
{
	int		top;

	top = dt->A->id;
	while (dt->B->id <= (dt->len / 2))
		top = sort(top, (dt->len / 4), dt);
	if (route(dt->len / 2, (dt->len / 2) + (dt->len / 4), dt) < 0)
	{
		while (dt->A->id < dt->len / 2)
			ft_stack_ra(dt);
	}
	else
	{
		while (dt->A->id < ((dt->len / 2) + (dt->len / 4)))
			ft_stack_rra(dt);
		while (dt->A->id > ((dt->len / 2) + (dt->len / 4)))
			ft_stack_rra(dt);
	}
}

int route(int low, int high, t_pushswap *dt)
{
	t_stack		*tmp;
	int			distance;

	distance = 0;
	tmp = dt->A;
	while (tmp->id < low)
	{
		distance++;
		tmp = tmp->nxt;
	}
	while (tmp->id < high)
		tmp = tmp->nxt;
	while (tmp)
	{
		distance--;
		tmp = tmp->nxt;
	}
	return (distance);
}

int stack_B_sorted(t_pushswap *dt)
{
	t_stack		*tmp;

	tmp = dt->B;
	while (tmp->nxt != NULL && tmp->nxt->id == tmp->id + 1)
			tmp = tmp->nxt;
	if (tmp->nxt == NULL)
		return (1);
	return (0);
}


