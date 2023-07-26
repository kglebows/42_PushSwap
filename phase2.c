/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:18:13 by kglebows          #+#    #+#             */
/*   Updated: 2023/07/26 21:51:29 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int distance(int id, int top, t_pushswap *dt)
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
	if (tmp->id == top || distance != 0)
		return (distance);
	while (tmp->id != top)
		tmp = tmp->nxt;
	while (tmp)
	{
		if (tmp->id > id)
			distance++;
		tmp = tmp->nxt;
	}
	return (distance * -1);
}

int swap(int first, int next)
{
	if (first < 0)
		first = first * -1;
	if (next < 0)
		next = next * -1;
	if (next > first + 1)
		return (1);
	return (0);
}

void ft_phase2(t_pushswap *dt)
{
	int		top;
	int		dist;

	top = dt->A->id;
	while (dt->B->id <= (dt->len / 2))
	{
		if (dt->B->id > (dt->len / 4))
			ft_stack_rb(dt);
		else
		{
			dist = distance(dt->B->id, top, dt);
			if (swap(dist, distance(dt->B->nxt->id, top, dt)))
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
	}
}



/*

NEW ToDo:
phase 2-3 -> find the closest route to part 3 either through skipping part 2 or part 4. 
phase 3 -> drop part 4 at the end of B, fill part 3.
phase 3-4 -> rotate to the end of part 2
phase 4 -> fill part 2
phase 4-5 -> rotate through part 1 or part 3 (25%)
phase 5 -> fill part 4
phase 6 -> rotate to begining of part 1
DONE

possible improvements :
implementing old plan for each part for finding the best combination of rotation both stacks



OLD ToDo:
0/	 Phase2 structure. Containing the solutions, afterimage, instruction list
0/?	 Structure should be part of t_stack? or at least a link to Phase2
0/=	 instruction string, first character -configuration, next instr per char
0/=	 -configuration O-ra/rb Q-rra/rrb X-ra/rrb K-rra/rb
0/=	 0pa, 1ra, 2rb, 3rra, 4rrb, 5rr, 6rrr, 7sa, 8sb, 9ss. 
1/A	 calculate distance for 4 possible combinations
1/B	 create the after image 
1/B* instead of copy. stack instruction, calculation, reverse instruction.
1/B* start with creating a instruction string. 
2/A	 calculate the $mv based on the distance combinations.
2/B	 calculate the avg_mv(1/A, 2/A <mv for every B element>) for after image
3/	 calculate the summary weight. Weight NOT stored in mv. mv is ph1 only. 
4/	 choose list of instructions based on weight, apply to A and B. 
5/	 start from 1 to B = NULL;
6/	 cleanup 

/%	 change name from mv to ph1.
/&	 test on stages. do 1 first, check the different cominations. compare.
/^	 test different ratios of distance : avg_mv
/^	 different scopes of impact could be usefull. tied with amount of input
/%	 Maybe another structure to save data for later analysis. easy remove.


Phase1:
/!	 determining direction can be beneficial rb/ra
/!	 if already sorted, should leave it. Both points can be connected 


/!	 based on phase1 mv presort stack B

 PROBLEM nr2/

 Passing imput arguments. passing empty string ? fix needed

*/