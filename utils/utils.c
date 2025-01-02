/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sferrad <sferrad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:04:43 by sferrad           #+#    #+#             */
/*   Updated: 2024/12/13 18:04:29 by sferrad          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_double(t_list *list)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = list;
	while (tmp->next)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (*(int *)tmp->content == *(int *)tmp2->content)
				return (0);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	check_tab(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\t')
			return (0);
		i++;
	}
	return (1);
}

long int	ft_atol(const char *str)
{
	long int	result;
	int			sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			sign = -1;
	}
	while (*str >= '0' && *str <= '9')
	{
		if (result > (LONG_MAX / 10) || (result == (LONG_MAX / 10) && (*str
					- '0') > 7))
		{
			if (sign == 1)
				return (LONG_MAX);
			else
				return (LONG_MIN);
		}
		result = result * 10 + (*str++ - '0');
	}
	return (result * sign);
}

void	ft_sort_four(t_list **a, t_list **b)
{
	int	min_index;

	if (ft_lstsize(*a) > 3)
	{
		min_index = ft_find_min_index(*a);
		ft_move_to_top(a, min_index);
		ft_instruct_push(a, b, 1);
	}
	ft_sort_three(a);
	while (*b)
	{
		ft_instruct_push(b, a, 2);
	}
}
