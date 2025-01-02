/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 11:53:59 by sferrad           #+#    #+#             */
/*   Updated: 2024/12/28 20:23:26 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(int *a, int *b)
{
	int	c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < size - 1)
	{
		if (tab[i] > tab[j] && i != size - 1)
		{
			ft_swap(&tab[i], &tab[j]);
			i = 0;
			j = 1;
		}
		else
		{
			i++;
			j++;
		}
	}
}

int	*convert_tab(t_list *list, int size)
{
	int		i;
	int		*tab;
	t_list	*tmp;

	if (!list || size <= 0)
		return (NULL);
	tmp = list;
	tab = (int *)malloc(sizeof(int) * size);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < size && tmp)
	{
		tab[i] = *(int *)(tmp->content);
		tmp = tmp->next;
		i++;
	}
	ft_sort_int_tab(tab, size);
	return (tab);
}

int	ft_find_min_index(t_list *list)
{
	int	min;
	int	index;
	int	min_index;

	if (!list)
		return (-1);
	min = *(int *)(list->content);
	index = 0;
	min_index = 0;
	while (list)
	{
		if (*(int *)(list->content) < min)
		{
			min = *(int *)(list->content);
			min_index = index;
		}
		list = list->next;
		index++;
	}
	return (min_index);
}

void	ft_move_to_top(t_list **pile, int index)
{
	int	size;

	size = ft_lstsize(*pile);
	if (index <= size / 2)
	{
		while (index > 0)
		{
			ft_instruct_rotate(pile, 1);
			index--;
		}
	}
	else
	{
		index = size - index;
		while (index > 0)
		{
			ft_instruct_reverse(pile, 1);
			index--;
		}
	}
}
