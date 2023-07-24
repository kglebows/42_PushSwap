/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phase2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:18:13 by kglebows          #+#    #+#             */
/*   Updated: 2023/07/24 11:25:19 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// void ft_phase2(t_pushswap *dt)
// {
// 	ft_stackiter(dt->B, ft_phase2_mv(dt->B));
// }

// void *ft_phase2_mv(void *B)
// {
	
// }



/*

ToDo:
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