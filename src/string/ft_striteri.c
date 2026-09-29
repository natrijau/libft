/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_striteri.c                                                        */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:28:30                                         */
/*   Updated: 2026/09/29 02:28:30                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *)){
	size_t	i;

	if (!s)
		return ;
	for (i = 0; s[i]; i++)
		(*f)(i, s + i);
}
