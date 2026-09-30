/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   get_next_line_bonus.c                                                */
/*   By: natrijau                                                         */
/*   Created: 2026/09/30 02:05:13                                         */
/*   Updated: 2026/09/30 02:05:13                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */


#include "../../get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stock[1024];
	char			*line;

	if (fd < 0 || fd >= 1024 || BUFFER_SIZE <= 0)
		return (NULL);
	if (get_stock(&stock[fd], fd) < 0)
	{
		free(stock[fd]);
		stock[fd] = NULL;
		return (NULL);
	}
	line = get_line(stock[fd]);
	cut_nl_end(&stock[fd]);
	if (stock[fd] && !*stock[fd])
	{
		free(stock[fd]);
		stock[fd] = NULL;
	}
	return (line);
}
