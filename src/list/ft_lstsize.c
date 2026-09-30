/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_lstsize.c                                                         */
/*   By: natrijau                                                         */
/*   Created: 2026/09/30 02:36:51                                         */
/*   Updated: 2026/09/30 02:36:51                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

int ft_lstsize(t_list *lst)
{
    int count;

    count = 0;
    while (lst)
    {
        count++;
        lst = lst->next;
    }
    return (count);
}   