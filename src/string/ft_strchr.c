/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_strchr.c                                                          */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:23:29                                         */
/*   Updated: 2026/09/29 02:23:29                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

char	*ft_strchr(const char *s, int c){
	unsigned char	*s_cpy;
	unsigned char	c_cpy;

	s_cpy = (unsigned char *) s;
	c_cpy = (unsigned char) c;
	while (*s_cpy){
		if (*s_cpy == c_cpy)
			return ((char *)s_cpy);
		s_cpy++;
	}
	if (c_cpy == '\0')
		return ((char *)s_cpy);
	return (NULL);
}
