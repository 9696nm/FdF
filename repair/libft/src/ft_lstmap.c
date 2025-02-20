/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hana/hmori <sagiri.mori@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:51:21 by hmori             #+#    #+#             */
/*   Updated: 2025/01/26 16:20:31 by hana/hmori       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	addlist(t_list **lst, void	*node)
{
	if (*lst == NULL)
		ft_lstadd_front(lst, node);
	else
		ft_lstadd_back(lst, node);
}

static void	*end(t_list *lst, void (*del)(void *))
{
	ft_lstclear(&lst, del);
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	void	*new_content;
	t_list	*new_list;
	t_list	*new_node;

	new_list = NULL;
	new_node = NULL;
	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	while (lst)
	{
		new_content = f(lst->content);
		if (new_content == NULL)
			del(new_content);
		else
		{
			new_node = (t_list *)malloc(sizeof(t_list));
			if (new_node == NULL)
				return (end(new_list, del));
			new_node->content = new_content;
			new_node->next = NULL;
			addlist(&new_list, new_node);
		}
		lst = lst->next;
	}
	return (new_list);
}
