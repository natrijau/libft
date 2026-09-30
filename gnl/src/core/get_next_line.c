/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   get_next_line.c                                                      */
/*   By: natrijau                                                         */
/*   Created: 2026/09/30 02:01:10                                         */
/*   Updated: 2026/09/30 02:05:32                                        */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "../../get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*stock;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (get_stock(&stock, fd) < 0)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	line = get_line(stock);
	cut_nl_end(&stock);
	if (stock && !*stock)
	{
		free(stock);
		stock = NULL;
	}
	return (line);
}
