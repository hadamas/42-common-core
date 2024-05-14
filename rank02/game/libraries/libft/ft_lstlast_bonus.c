
#include "libft.h"

t_list_libft	*ft_lstlast(t_list_libft *lst)
{
	while (lst != NULL)
	{
		if (lst->next == NULL)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
