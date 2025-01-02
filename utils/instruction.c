/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 18:17:50 by sferrad           #+#    #+#             */
/*   Updated: 2024/12/28 20:23:51 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_instruct_swap(t_list *pile_X, int pile)
{
	void	*tmp_content;

	if (!pile_X || !(pile_X->next))
		return (pile_X);
	if (pile == 1)
		ft_printf("sa\n");
	else if (pile == 2)
		ft_printf("sb\n");
	else
		(void)pile;
	tmp_content = pile_X->content;
	pile_X->content = pile_X->next->content;
	pile_X->next->content = tmp_content;
	return (pile_X);
}

void	ft_instruct_push(t_list **src, t_list **dest, int pile)
{
	t_list	*tmp;

	if (!*src)
		return ;
	if (pile == 1)
		ft_printf("pb\n");
	else if (pile == 2)
		ft_printf("pa\n");
	tmp = *src;
	*src = (*src)->next;
	tmp->next = *dest;
	*dest = tmp;
}

void	ft_instruct_rotate(t_list **list, int pile)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!*list || !(*list)->next)
		return ;
	if (pile == 1)
		ft_printf("ra\n");
	else if (pile == 2)
		ft_printf("rb\n");
	else
		(void)pile;
	tmp = *list;
	*list = (*list)->next;
	tmp->next = NULL;
	tmp2 = ft_lstlast(*list);
	tmp2->next = tmp;
}

void	ft_instruct_reverse(t_list **list, int pile)
{
	t_list	*tmp;
	t_list	*tmp2;

	if (!(*list) || !(*list)->next)
		return ;
	if (pile == 1)
		ft_printf("rra\n");
	else if (pile == 2)
		ft_printf("rrb\n");
	else
		(void)pile;
	tmp = ft_lstlast(*list);
	tmp2 = *list;
	while (tmp2->next->next)
		tmp2 = tmp2->next;
	tmp2->next = NULL;
	tmp->next = *list;
	*list = tmp;
}

void	ft_instruct_ss_rr(t_list **pile_X, t_list **pile_Z, int instruct)
{
	if (instruct == 1)
	{
		*pile_X = ft_instruct_swap(*pile_X, 3);
		*pile_Z = ft_instruct_swap(*pile_Z, 3);
		ft_printf("ss\n");
	}
	if (instruct == 2)
	{
		ft_instruct_rotate(pile_X, 3);
		ft_instruct_rotate(pile_Z, 3);
		ft_printf("rr\n");
	}
	if (instruct == 3)
	{
		ft_instruct_reverse(pile_X, 3);
		ft_instruct_reverse(pile_Z, 3);
		ft_printf("rrr\n");
	}
	return ;
}
