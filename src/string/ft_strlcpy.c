/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_strlcpy.c                                                         */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:38:47                                         */
/*   Updated: 2026/09/29 02:38:47                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h" 

size_t	ft_strlcpy(char *dst, const char *src, size_t size){
	size_t	i;
	size_t	len_src;

	if (!dst || !src)
		return (0);
	len_src = ft_strlen(src);
	if (size == 0)
		return (len_src);
	for (i = 0; src[i] && i < size - 1; i++)
		dst[i] = src[i];
	dst[i] = '\0';
	return (len_src);
}