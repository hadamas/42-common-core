
#include "libft.h"

int	ft_lstsize(t_list_libft *lst)
{
	int	i;

	i = 0;
	while (lst != NULL)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}
