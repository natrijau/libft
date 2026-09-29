/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_strlcat.c                                                         */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:29:11                                         */
/*   Updated: 2026/09/29 02:29:11                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"	

size_t	ft_strlcat(char *dst, const char *src, size_t size){
	size_t	len_dest;
	size_t	len_src;
	size_t	i;

	if (!dst || !src)
		return (0);
	len_dest = ft_strlen(dst);
	len_src = ft_strlen(src);
	if (size <= len_dest)
		return (len_src + size);
	for (i = 0; src[i] && (len_dest + i < size - 1); i++)
		dst[len_dest + i] = src[i];
	dst[len_dest + i] = '\0';
	return (len_src + len_dest);
}
