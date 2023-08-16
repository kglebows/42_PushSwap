/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:46:11 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/16 18:49:23 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_stack_sa(int mute, t_pushswap *dt)
{
	t_stack			*tmp;

	if (dt->a->nxt)
	{
		tmp = dt->a;
		dt->a = dt->a->nxt;
		tmp->nxt = dt->a->nxt;
		dt->a->nxt = tmp;
	}
	dt->cnt++;
	if (mute == 0)
		write(1, "sa\n", 3);
}

void	ft_stack_sb(int mute, t_pushswap *dt)
{
	t_stack			*tmp;

	if (dt->b->nxt)
	{
		tmp = dt->b;
		dt->b = dt->b->nxt;
		tmp->nxt = dt->b->nxt;
		dt->b->nxt = tmp;
	}
	dt->cnt++;
	if (mute == 0)
		write(1, "sb\n", 3);
}

void	ft_stack_ss(int mute, t_pushswap *dt)
{
	t_stack			*tmp;

	if (dt->a->nxt)
	{
		tmp = dt->a;
		dt->a = dt->a->nxt;
		tmp->nxt = dt->a->nxt;
		dt->a->nxt = tmp;
	}
	if (dt->b->nxt)
	{
		tmp = dt->b;
		dt->b = dt->b->nxt;
		tmp->nxt = dt->b->nxt;
		dt->b->nxt = tmp;
	}
	dt->cnt++;
	if (mute == 0)
		write(1, "ss\n", 3);
}
