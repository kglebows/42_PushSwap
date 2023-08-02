/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_swap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:46:11 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/02 17:55:33 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_stack_sa(t_pushswap *dt)
{
	t_stack			*tmp;

	tmp = dt->A;
	dt->A = dt->A->nxt;
	tmp->nxt = dt->A->nxt;
	dt->A->nxt = tmp;
	dt->cnt++;
	write(1, "sa\n", 3);
}

void ft_stack_sb(t_pushswap *dt)
{
	t_stack			*tmp;

	tmp = dt->B;
	dt->B = dt->B->nxt;
	tmp->nxt = dt->B->nxt;
	dt->B->nxt = tmp;
	dt->cnt++;
	write(1, "sb\n", 3);
}
void ft_stack_ss(t_pushswap *dt)
{
	t_stack			*tmp;

	tmp = dt->A;
	dt->A = dt->A->nxt;
	tmp->nxt = dt->A->nxt;
	dt->A->nxt = tmp;
	tmp = dt->B;
	dt->B = dt->B->nxt;
	tmp->nxt = dt->B->nxt;
	dt->B->nxt = tmp;
	dt->cnt++;
	write(1, "ss\n", 3);
}
