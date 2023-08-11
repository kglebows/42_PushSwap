/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kglebows <kglebows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 17:12:23 by kglebows          #+#    #+#             */
/*   Updated: 2023/08/11 13:01:57 by kglebows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"

#include "stdio.h"

typedef struct s_stack
{
	int					nb;
	int					id;
	int					mv;
	int					rt;
	struct s_stack		*nxt;
}						t_stack;

typedef struct s_pushswap
{
	int					max;
	int					min;
	int					ph1;
	int					len;
	int					Alen;
	int					Blen;
	int					top;
	int					cnt;
	t_stack				*A;
	t_stack				*B;
	char				*cmd;
}						t_pushswap;


t_pushswap		*ft_ini(int argn, char *argc[]);
t_stack			*ft_stack_add(t_stack *A, int nb);
t_pushswap		*ft_ini_dt();
void			test_input(t_pushswap *dt);
int				ft_ini_A(int argn, char *argc[], t_pushswap *dt);
int				ft_ini_inputcheck(t_pushswap *dt);
t_stack			*ft_stack_ini(int nb, t_pushswap *dt);
void			ft_ini_id(t_pushswap *dt);
void			ft_ini_dtdata(t_pushswap *dt);
void			ft_stackiter(t_stack *stack, void (*f)(void *));

void			test(t_pushswap *dt);
void			test_stacks(t_pushswap *dt);
void			ft_stack_pa(t_pushswap *dt);
void			ft_stack_pb(t_pushswap *dt);
void			ft_stack_ra(t_pushswap *dt);
void			ft_stack_rb(t_pushswap *dt);
void			ft_stack_rr(t_pushswap *dt);
t_stack			*ft_stacklast(t_stack *stack);
void			ft_stack_rra(t_pushswap *dt);
void			ft_stack_rrb(t_pushswap *dt);
void			ft_stack_rrr(t_pushswap *dt);
void			ft_stack_sa(t_pushswap *dt);
void			ft_stack_sb(t_pushswap *dt);
void			ft_stack_ss(t_pushswap *dt);

void			ft_phase1(t_pushswap *dt);
int				ft_phase1_imdone(t_pushswap *dt, int first, int last);
void			ft_phase2(t_pushswap *dt);
int				ft_phase1_sorted(t_pushswap *dt);

// void reset\_mv(t_stack* node);
int find_longest_increasing_sequence(t_stack* node);
void ft_ini_mv(t_pushswap *dt);

void ft_phase2(t_pushswap *dt);
void ft_phase3(t_pushswap *dt);
void ft_phase4(t_pushswap *dt);
void ft_phase5(t_pushswap *dt);
void ft_shortphase(t_pushswap *dt);
void ft_phase500(t_pushswap *dt);

int distanceB(int id, t_pushswap *dt);
void sortB(t_pushswap *dt);
void distance_tester(t_pushswap *dt);
int distanceA(int id, t_pushswap *dt);
void mvB(t_pushswap *dt);
void ft_Error(void);
void do_the_next_best_move(t_pushswap *dt);

#endif

/*

NEW NEW ToDo:

clean up xD
rewrite phase 1 for 2 1 3. get rid of first and last
add move counter and checker



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

/*

ToDo:
- stack phase 1 mv calculation
- phase1_id
- B stack ini
- stack operations
- phase1 simulation 
- swap algorithm 
- rotate algorithm
- sort check
- distance calculation algorithm
- distance implementation.
- print out Error\n if error.

phase1 - push_swap:
- find the id that would leave in stack 1 the biggest number of elements after phase 1
- implementing swap when element fits the swap. When reaching the next element see if swap will still fit. if yes, do it.
- if sort check ok on A, begin phase 2.
- mv contains number of elements left in A after phase 1 - without swaps (default -1)

phase2 - rotate_push:
- mv (in stack B) - contains distance, + rotation, - reverse rotation. 
- 

swap alg:
- if swap in A, then check if swap in B would result in descending order, if yes - do double swap

distance alg:
- distance is a number of moves from B stack element to corresponding place in stack A.
- is is precalculated for rotating A stack, rotating B stack and rotating both. whichever takes less moves.
- Actual moving alg will calculate this again, this part focuses on finding the lowest amount of moves.
- < i could ditch it in favour of just wheeling it.- lets start with just that

*/