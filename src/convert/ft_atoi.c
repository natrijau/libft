/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_atoi.c                                                            */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:49:16                                         */
/*   Updated: 2026/09/29 02:49:16                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

int	ft_atoi(const char *nptr){
    unsigned int	i;
    int				sign;
    int				nb;

    i = 0;
    nb = 0;
    sign = 1;
    while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
        i++;
    if (nptr[i] == '+' || nptr[i] == '-'){
        if (nptr[i] == '-')
            sign = -1;
        i++;
    }
    while (nptr[i] >= '0' && nptr[i] <= '9'){
        nb = (nb * 10) + (nptr[i] - 48);
        i++;
    }
    return (nb * sign);
}