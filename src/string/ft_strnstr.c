/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_strnstr.c                                                         */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:36:48                                         */
/*   Updated: 2026/09/29 02:36:48                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len){
    size_t	i;
    size_t	j;
    size_t	k;

    if (!big || !little)
        return (NULL);
    if (little[0] == '\0')
        return ((char *)big);
    i = 0;
    while (big[i] && i < len){
        j = 0;
        k = i;
        while (big[i] == little[j] && i < len && big[i]){
            i++;
            j++;
        }
        if (little[j] == '\0')
            return ((char *)&big[k]);
        i = k + 1;
    }
    return (NULL);
}