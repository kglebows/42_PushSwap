/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 18:42:58 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/12 14:39:49 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_stack_add(t_stack *A, int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->mv = 1;
	new->rt = 0;
	new->nxt = NULL;
	new->id = 0;
	A->nxt = new;
	return (new);
}

t_stack	*ft_stack_ini(int nb, t_pushswap *dt)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->mv = 1;
	new->nxt = NULL;
	new->rt = 0;
	new->id = 0;
	dt->A = new;
	return (new);
}

int ft_ini_A(int argn, char *argc[], t_pushswap *dt)
{
	long		i[3];
	char		**arr;
	t_stack		*A;

	A = dt->A;
	i[0] = 1;
	while (i[0] < argn)
	{
		arr = ft_split(argc[i[0]], ' ');
		i[1] = 0;
		while(arr[i[1]])
		{
			i[2] = ft_atoi(arr[i[1]]);
			if (!ft_isnum(arr[i[1]]) || i[2] > 2147483647 || i[2] < -2147483648)
				return (0);
			if (!A)
				A = ft_stack_ini((int) i[2], dt);
			else
				A = ft_stack_add(A, (int) i[2]);
			i[1]++;
		}
		ft_free(arr); 
		i[0]++;
	}
	return (1);
}

t_pushswap *ft_ini_dt()
{
	t_pushswap		*dt;

	dt = malloc(sizeof(t_pushswap));
	if (!dt)
		return(NULL);
	dt->A = NULL;
	dt->B = NULL;
	dt->len = 0;
	dt->Alen = 0;
	dt->max = 0;
	dt->min = 0;
	dt->ph1 = 0;
	dt->top = 2147483647;
	dt->cnt = 0;
	return(dt);
}

int ft_ini_inputcheck(t_pushswap *dt)
{
	t_stack		*temp;
	t_stack		*tmp;
	int			check;

	temp = dt->A;
	while (temp->nxt != NULL)
	{
		check = temp->nb;
		tmp = temp;
		while (tmp->nxt != NULL)
		{
			tmp = tmp->nxt;
			if (tmp->nb == check)
				return (0);
		}
		temp = temp->nxt;
	}
	return (1);
}
