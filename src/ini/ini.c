/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:51:33 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/16 13:55:22 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	assign_sorted_id(t_stack *temp, t_pushswap *dt)
{
	t_stack		*tmp;
	int			index;

	index = 1;
	tmp = dt->a;
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

void	ini_id(t_pushswap *dt)
{
	t_stack		*temp;

	temp = dt->a;
	while (temp->nxt != NULL)
	{
		temp->id = assign_sorted_id(temp, dt);
		temp = temp->nxt;
	}
	temp->id = assign_sorted_id(temp, dt);
}

void	ini_dtdata(t_pushswap *dt)
{
	t_stack		*tmp;

	tmp = dt->a;
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
	dt->alen = dt->len;
}

t_pushswap	*ini_dt(void)
{
	t_pushswap		*dt;

	dt = malloc(sizeof(t_pushswap));
	if (!dt)
		return (NULL);
	dt->a = NULL;
	dt->b = NULL;
	dt->len = 0;
	dt->alen = 0;
	dt->max = 0;
	dt->min = 0;
	dt->ph1 = 0;
	dt->top = 2147483647;
	dt->cnt = 0;
	return (dt);
}

t_pushswap	*ft_ini(int argn, char *argc[])
{
	t_pushswap	*dt;

	if (argn < 2)
		return (NULL);
	dt = ini_dt();
	if (!dt || ft_ini_a(argn, argc, dt) == 0)
		return (ft_error(dt));
	if (ft_ini_inputcheck(dt) == 0)
		return (ft_error(dt));
	ini_dtdata(dt);
	ini_id(dt);
	return (dt);
}
