
#include "libft.h"

void	ft_lstclear(t_list_libft **lst, void (*del)(void*))
{
	t_list_libft	*aux;

	if (!del || !lst || !*lst)
		return ;
	while (*lst)
	{
		aux = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = aux;
	}
}
