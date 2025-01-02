/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 16:29:46 by sferrad           #+#    #+#             */
/*   Updated: 2024/12/28 19:39:08 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_find_max(t_list *list)
{
	int	max;
	int	bits;

	bits = 0;
	if (!list)
		return (0);
	max = *(int *)(list->content);
	while (list)
	{
		if (*(int *)(list->content) > max)
			max = *(int *)(list->content);
		list = list->next;
	}
	while (max > 0)
	{
		max >>= 1;
		bits++;
	}
	return (bits);
}

void	ft_index(t_list *list, int size)
{
	int		*tab;
	int		i;
	t_list	*tmp;

	tab = convert_tab(list, size);
	tmp = list;
	while (tmp)
	{
		i = 0;
		while (*(int *)(tmp->content) != tab[i] && i < size)
			i++;
		*(int *)(tmp->content) = i;
		tmp = tmp->next;
	}
	free(tab);
}

void	ft_radix_sort(t_list **pile_A, t_list **pile_B)
{
	int		i;
	int		bits;
	int		size;
	int		j;
	t_list	*head;

	head = *pile_A;
	size = ft_lstsize(*pile_A);
	ft_index(head, size);
	i = 0;
	bits = ft_find_max(head);
	while (i < bits)
	{
		j = 0;
		while (j++ < size)
		{
			if (((*(int *)((*pile_A)->content) >> i) & 1) == 0)
				ft_instruct_push(pile_A, pile_B, 1);
			else
				ft_instruct_rotate(pile_A, 1);
		}
		while (*pile_B)
			ft_instruct_push(pile_B, pile_A, 2);
		i++;
	}
}

void	ft_sort_three(t_list **stack)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)(*stack)->content;
	b = *(int *)(*stack)->next->content;
	c = *(int *)(*stack)->next->next->content;
	if (a > b && a > c)
		ft_instruct_rotate(stack, 1);
	else if (b > a && b > c)
		ft_instruct_reverse(stack, 1);
	if (*(int *)(*stack)->content > *(int *)(*stack)->next->content)
		ft_instruct_swap(*stack, 1);
}

void	ft_sort_five(t_list **a, t_list **b)
{
	int	min_index;

	while (ft_lstsize(*a) > 3)
	{
		min_index = ft_find_min_index(*a);
		ft_move_to_top(a, min_index);
		ft_instruct_push(a, b, 1);
	}
	ft_sort_three(a);
	while (*b)
		ft_instruct_push(b, a, 2);
}
