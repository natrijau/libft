/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )  */
/*    `---'                                                       `---`  */
/*                                                                        */
/*   ft_count_tokens.c                                                   */
/*   By: natrijau                                                        */
/*   Created: 2026/09/29 01:10:24                                        */
/*   Updated: 2026/09/29 01:10:24                                        */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

size_t  ft_count_tokens(const char *str, char sep){
	size_t	count;

	count = 0;
	for (size_t i = 0; str[i]; i++){
		if (!ft_is_separator(str[i], sep)
			&& (str[i + 1] == '\0' || ft_is_separator(str[i + 1], sep)))
			count++;
	}
	return (count);
}