/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 13:06:31 by kglebows          #+#    #+#             */
/*   Updated: 2023/06/23 22:41:26 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

int main(int argn, char *argc[])
{
	t_pushswap		*dt;

	dt = ft_ini(argn, argc);
	if (!dt)
		return (0);
	// ft_phase1(&dt);
	// ft_phase2(&dt);
	// ft_phase3(&dt);
	// ft_result(&dt);
	test_print_stacks(dt);
	// ft_cleanup(&dt);
	return (0);
}

void test_print_stacks(t_pushswap *dt)
{
	t_stack			*tmp;

	printf(":::::: Stack A ::::::\n");
	printf("::  id :  nb :  mv ::\n");
	tmp = dt->A;
	while (tmp->nxt != dt->A)
	{
		printf("::%4d :%4d :%4d ::\n", tmp->id, tmp->nb, tmp->mv);
		tmp = tmp->nxt;
	}
	printf("::%4d :%4d :%4d ::\n", tmp->id, tmp->nb, tmp->mv);
	printf(":::::::::::::::::::::\n");
}

t_pushswap *ft_ini(int argn, char *argc[])
{
	t_pushswap	*dt;

	if (argn < 2)
		return (NULL);
	dt = ft_ini_dt();
	if (!dt || ft_ini_A(argn, argc, dt) == 0)
		return (NULL);
	if (ft_ini_inputcheck(dt) == 0)
		return (NULL);
	ft_ini_index(dt);
	ft_ini_phase1(dt);
	return (dt);
}

int ft_ini_A(int argn, char *argc[], t_pushswap *dt)
{
	int			i[2];
	char		**arr;
	t_stack		*A;

	A = dt->A;
	i[0] = 1;
	while (i[0] < argn)
	{
		arr = ft_split(argc[i[0]], ' ');
		i[1] = 0;
		while(arr[i[1]] != NULL)
		{
			if (A == NULL)
				A = ft_stack_ini(ft_atoi(arr[i[1]]), dt);
			else
				A = ft_stack_add(A, ft_atoi(arr[i[1]]));
			i[1]++;
		}
		i[0]++;
	}
	if (A != NULL)
		A->nxt = dt->A;
	else
		return (0);
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
	dt->cmd = NULL;
	dt->len = 0;
	dt->max = 0;
	dt->min = 0;
	dt->phase1_id = 0;
	return(dt);
}

t_stack	*ft_stack_add(t_stack *A, int nb)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->nb = nb;
	new->mv = 0;
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
	new->mv = 0;
	new->nxt = NULL;
	new->id = 0;
	dt->A = new;
	return (new);
}

int ft_ini_inputcheck(t_pushswap *dt)
{
	/*
	ToDo:
	- check for doubles
	- check for nulls
	- check for int values
	*/
	return (1);
}

void ft_ini_index(t_pushswap *dt)
{
	/*
	ToDo:
	- Calculate max, min, len in dt.
	- assign indexes (1 to max) via bubble sort.
	*/
}

void ft_ini_phase1(t_pushswap *dt)
{
	/*
	ToDo:
	- find phase 1 id (assign number of the sorted elements to mv, then find the biggest mv, assign to dt phase1_id)
	*/
}

void ft_stack_pa(t_pushswap *dt)
{
	
}
void ft_stack_pb(t_pushswap *dt)
{
	
}
void ft_stack_ra(t_pushswap *dt)
{
	
}
void ft_stack_rb(t_pushswap *dt)
{
	
}
void ft_stack_rr(t_pushswap *dt)
{
	
}
void ft_stack_rra(t_pushswap *dt)
{
	
}
void ft_stack_rrb(t_pushswap *dt)
{
	
}
void ft_stack_rrr(t_pushswap *dt)
{
	
}
void ft_stack_sa(t_pushswap *dt)
{
	
}
void ft_stack_sb(t_pushswap *dt)
{
	
}
void ft_stack_ss(t_pushswap *dt)
{
	
}