
#include "get_next_line.h"

void	put_node(t_list **list, char *buf)
{
	t_list	*last_node;
	t_list	*new_node;

	last_node = find_last_node(*list);
	new_node = malloc(sizeof(t_list));
	if (!new_node)
		return ;
	if (last_node == NULL)
		*list = new_node;
	else
		last_node->next = new_node;
	new_node->buf = buf;
	new_node->next = NULL;
}

void	creat_list(t_list **list, int fd)
{
	int		count_read;
	char	*buf;

	while (!found_newline(*list))
	{
		buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		count_read = read(fd, buf, BUFFER_SIZE);
		if (!count_read || count_read < 0)
		{
			free(buf);
			return ;
		}
		buf[count_read] = '\0';
		put_node(list, buf);
	}
}

char	*get_line(t_list *list)
{
	int		str_len;
	char	*next_str;

	if (!list)
		return (NULL);
	str_len = len_to_newline(list);
	next_str = malloc(sizeof(char) * (str_len + 1));
	if (!next_str)
		return (NULL);
	copy_str_list(list, next_str);
	return (next_str);
}

void	clean_list(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	char	*buf;
	int		i;
	int		j;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	clean_node = malloc(sizeof(t_list));
	if (!buf || !clean_node)
		return ;
	last_node = find_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->buf[i] && last_node->buf[i] != '\n')
		i++;
	while (last_node->buf[i] != '\0' && last_node->buf[++i] != '\0')
		buf[j++] = last_node->buf[i];
	buf[j] = '\0';
	clean_node->buf = buf;
	clean_node->next = NULL;
	clear_list(list, clean_node, buf);
}

char	*get_next_line(int fd)
{
	static t_list	*list;
	char			*next_line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	creat_list(&list, fd);
	if (!list)
		return (NULL);
	next_line = get_line(list);
	clean_list(&list);
	return (next_line);
}
