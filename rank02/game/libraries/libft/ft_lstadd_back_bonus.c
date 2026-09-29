

#include "libft.h"

void	ft_lstadd_back(t_list_libft **lst, t_list_libft *new)
{
	t_list_libft	*last;

	if (lst)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}
