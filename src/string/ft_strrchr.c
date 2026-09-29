/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )  */
/*    `---'                                                       `---`  */
/*                                                                        */
/*   ft_strrchr.c                                                        */
/*   By: natrijau                                                        */
/*   Created: 2026/09/29 01:22:33                                        */
/*   Updated: 2026/09/29 01:22:33                                        */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

char	*ft_strrchr(const char *s, int c){
	size_t			i;
	unsigned char	target;

	target = (unsigned char)c;
	i = 0;
	while (s[i])
		i++;
	while (1){
		if ((unsigned char)s[i] == target)
			return ((char *)&s[i]);
		if (i == 0)
			break ;
		i--;
	}
	return (NULL);
}




