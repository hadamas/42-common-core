
#include "libft.h"

t_list_libft	*ft_lstnew(void *content)
{
	t_list_libft	*r;

	r = malloc(sizeof(*r));
	if (!r)
		return (NULL);
	r->content = content;
	r->next = NULL;
	return (r);
}
