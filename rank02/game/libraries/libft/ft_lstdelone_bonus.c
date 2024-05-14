
#include "libft.h"

void	ft_lstdelone(t_list_libft *lst, void (*del)(void*))
{
	if (!del)
		return ;
	if (lst)
	{
		del(lst->content);
		free(lst);
	}
}
