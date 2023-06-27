/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:51:33 by kglebows          #+#    #+#             */
/*   Updated: 2023/06/27 11:20:38 by kglebows         ###   ########.fr       */
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
}

void ft_ini_id(t_pushswap *dt)
{
	t_stack		*temp;

	temp = dt->A;
	while (temp->nxt != NULL)
	{
		temp->id = ft_ini_id_index(temp, dt);
		temp = temp->nxt;
	}
	temp->id = ft_ini_id_index(temp, dt);
}

int ft_ini_id_index(t_stack *temp, t_pushswap *dt)
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

void ft_ini_ph1(t_pushswap *dt)
{
	t_stack		*temp;
	t_stack		*tmp;
	int			top;
	int			mv;

	temp = dt->A;
	while (temp->nxt != NULL)
	{
		mv = 1;
		top = temp->id;
		tmp = temp;
		while (tmp->nxt != NULL)
		{
			tmp = tmp->nxt;
			if (top < tmp->id)
			{
				mv++;
				top = tmp->id;
			}
		}
		temp->mv = mv;
		temp = temp->nxt;
	}
	ft_ini_ph1_id(dt);
}

void ft_ini_ph1_id(t_pushswap *dt)
{
	t_stack		*tmp;
	int			ph1;

	ph1 = 0;
	tmp = dt->A;
	while (tmp->nxt != NULL)
	{
		if (tmp->mv > ph1)
		{
			ph1 = tmp->mv;
			dt->ph1 = tmp->id;
		}
		tmp = tmp->nxt;
	}
}