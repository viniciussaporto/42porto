/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:07:33 by vsa-port          #+#    #+#             */
/*   Updated: 2022/11/11 17:54:21 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	del(void *ptr)
{
	free(ptr);
}

void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (!lst || !del)
		return ;
	del(lst->content);
	free(lst);
}

/*void	del(void *this)
{
	free (this);
}

int	main ()
{
	t_list	*head;
	t_list	*dois;
	t_list	*tres;
	t_list	*quatro;

	char	*c1 = ft_strdup("um");
	char    *c2 = ft_strdup("dois");
	char    *c3 = ft_strdup("tres");
	char    *c4 = ft_strdup("quatro");

	head = ft_lstnew(c1);
	dois = ft_lstnew(c2);
	tres = ft_lstnew(c3);
	quatro = ft_lstnew(c4);

	ft_lstadd_back(&head, dois);
	ft_lstadd_back(&head, tres);
	ft_lstadd_back(&head, quatro);

	printf("\n%s	%s	%s	%s\n", (char *)head->content, 
			(char *)head ->next->content,
			(char *)head->next->next->content,
			(char *)head->next->next->next->content);
	printf("%p	%p	%p	%p	%p	%p\n", head, head->next, 
	head->next->next, 
	head->next->next->next, 
	head->next->next->next->next);
	ft_lstdelone(&head, del);

	printf("\n%p\n", head);

	return (0);
}*/
