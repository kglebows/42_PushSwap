/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:31 by kglebows          #+#    #+#             */
/*   Updated: 2023/06/23 18:54:39 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int main(int argn, char *argc[])
{
	t_pushswap		*dt;
	t_stack			*tmp;

	if (argn < 2)
		return (0);
	dt = ft_ini(argn, argc);
	tmp = dt->A;
	while (tmp->nxt != dt->A)
	{
		printf("%d :: %d\n", tmp->id, tmp->nb);
		tmp = tmp->nxt;
	}
	printf("%d :: %d\n", tmp->id, tmp->nb);
	// ft_phase1(&dt);
	// ft_phase2(&dt);
	// ft_phase3(&dt);
	// ft_result(&dt);
	// ft_cleanup(&dt);
	return (0);
}

t_pushswap *ft_ini(int argn, char *argc[])
{
	int			i;
	int			j;
	char		**arr;
	t_stack		*A;
	t_pushswap	*dt;

	dt = ft_dt_ini();
	A = dt->A;
	i = 1;
	while (i < argn)
	{
		arr = ft_split(argc[i], ' ');
		j = 0;
		while(arr[j] != NULL)
		{
			if (A == NULL)
			{
				dt->A = ft_stackadd(A, ft_atoi(arr[j]));
				A = dt->A;
			}
			else
				A = ft_stackadd(A, ft_atoi(arr[j]));
			j++;
		}
		i++;
	}
	if (A != NULL)
		A->nxt = dt->A;
	return (dt);
}

t_pushswap *ft_dt_ini()
{
	t_pushswap		*dt;

	dt = malloc(sizeof(t_pushswap));
	if (!dt)
		return(NULL);
	dt->A = NULL;
	dt->B = NULL;
	dt->cmd = NULL;
	dt->len = 0;
	dt->max = 0;
	dt->min = 0;
	dt->phase1_id = 0;
	return(dt);
}

t_stack	*ft_stackadd(t_stack *A, int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->mv = 0;
	new->nxt = NULL;
	if (A != NULL)
	{
		new->id = A->id + 1;
		A->nxt = new;
	}
	else
		new->id = 1;
	return (new);
}