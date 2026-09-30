/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   get_next_line_utils_bonus.c                                          */
/*   By: natrijau                                                         */
/*   Created: 2026/09/30 02:01:42                                         */
/*   Updated: 2026/09/30 02:05:26                                        */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


#include "../../get_next_line.h"

int	have_nl(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*cut_nl_start(char *stock)
{
	size_t	index;

	if (!stock)
		return (NULL);
	index = 0;
	while (stock[index] && stock[index] != '\n')
		index++;
	if (stock[index] == '\n')
		index++;
	return (ft_substr(stock, 0, index));
}

void	cut_nl_end(char **stock)
{
	char	*remaining;
	size_t	index;

	if (!stock || !*stock)
		return ;
	index = 0;
	while ((*stock)[index] && (*stock)[index] != '\n')
		index++;
	if ((*stock)[index] == '\n')
		index++;
	remaining = ft_substr(*stock, index, ft_strlen(*stock) - index);
	free(*stock);
	*stock = remaining;
}

char	*get_line(char *stock)
{
	if (!stock || !*stock)
		return (NULL);
	return (cut_nl_start(stock));
}

int	get_stock(char **stock, int fd)
{
	char	*buffer;
	char	*joined;
	ssize_t	bytes_read;

	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!buffer)
		return (-1);
	bytes_read = 1;
	while (!have_nl(*stock) && bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		buffer[bytes_read] = '\0';
		joined = ft_strjoin(*stock, buffer);
		free(*stock);
		*stock = joined;
		if (!*stock)
			break ;
	}
	free(buffer);
	if (bytes_read < 0 || !*stock)
		return (-1);
	return (0);
}
