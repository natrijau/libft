/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_strncmp.c                                                         */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:36:43                                         */
/*   Updated: 2026/09/29 02:36:43                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n){
    unsigned char	*ccs1;
    unsigned char	*ccs2;
    size_t			i;

    ccs1 = (unsigned char *)s1;
    ccs2 = (unsigned char *)s2;
    i = 0;
    while ((ccs1[i] || ccs2[i]) && i < n){
        if (ccs1[i] != ccs2[i])
            return (ccs1[i] - ccs2[i]);
        i++;
    }
    return (0);
}