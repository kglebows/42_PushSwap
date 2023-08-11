/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:51:33 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/11 13:19:57 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void ft_ini_dtdata(t_pushswap *dt)
{
	t_stack		*tmp;

	tmp = dt->A;
	dt->len = 1;
	dt->max = tmp->nb;
	dt->min = tmp->nb;
	while (tmp->nxt != NULL)
	{
		tmp = tmp->nxt;
		dt->len++;
		if (tmp->nb > dt->max)
			dt->max = tmp->nb;
		if (tmp->nb < dt->min)
			dt->min = tmp->nb;
	}
	dt->Alen = dt->len;
}

int assign_sorted_id(t_stack *temp, t_pushswap *dt)
{
	t_stack		*tmp;
	int			index;

	index = 1;
	tmp = dt->A;
	while (tmp->nxt != NULL)
	{
		if (tmp->nb < temp->nb)
			index++;
		tmp = tmp->nxt;
	}
	if (tmp->nb < temp->nb)
		index++;
	return (index);
}

void ft_ini_id(t_pushswap *dt)
{
	t_stack		*temp;

	temp = dt->A;
	while (temp->nxt != NULL)
	{
		temp->id = assign_sorted_id(temp, dt);
		temp = temp->nxt;
	}
	temp->id = assign_sorted_id(temp, dt);
}


int find_longest_increasing_sequence(t_stack* node)
{
	t_stack		*current;
	int			max_mv;
	int			mv;

	if (node->nxt == NULL)
		return (node->mv);
	current = node->nxt;
	max_mv = node->mv;
	while (current != NULL)
	{
		if (current->id > node->id)
		{
			mv = find_longest_increasing_sequence(current);
			if (mv + 1 > max_mv)
				max_mv = mv + 1;
		}
		current = current->nxt;
	}
	return max_mv;
}

void ft_ini_mv(t_pushswap *dt)
{
	t_stack		*current;
	t_stack		*tmp;

	current = dt->A;
	while(current != NULL)
	{
		tmp = current->nxt;
		while(tmp != NULL)
		{
			tmp->mv = 1; 
			tmp = tmp->nxt;
		}
		current->mv = find_longest_increasing_sequence(current);
		if (current->mv > dt->ph1)
			dt->ph1 = current->mv;
		current = current->nxt;
	}
}
