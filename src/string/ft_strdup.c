/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_strdup.c                                                          */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:24:57                                         */
/*   Updated: 2026/09/29 02:24:57                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

char	*ft_strdup(const char *s){
	char	*str;
	size_t	len;

	len = ft_strlen(s) + 1;
	str = (char *)malloc(len);
	if (str == NULL)
		return (NULL);
	ft_memcpy(str, s, len);
	return (str);
}