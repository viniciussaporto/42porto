/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:34:15 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/07 14:55:39 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*j;
	
	j = *lst;
	if (!lst || !del)
		return ;
	while (*lst != NULL)
	{
		j = j->next;
		del((*lst)->content);
		free(*lst);
		*lst = j;
	}
	*lst = NULL;
}