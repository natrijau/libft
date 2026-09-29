/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_token_len.c                                                       */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:19:38                                         */
/*   Updated: 2026/09/29 02:19:38                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

size_t  ft_token_len(const char *str, char sep){
	size_t  len;

	len = 0;
	while (str[len] && !ft_is_separator(str[len], sep))
		len++;
	return (len);
}
