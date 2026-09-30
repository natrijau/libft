/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_lstlast.c                                                         */
/*   By: natrijau                                                         */
/*   Created: 2026/09/30 02:37:03                                         */
/*   Updated: 2026/09/30 02:37:03                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

t_list *ft_lstlast(t_list *lst)
{
    if (!lst)
        return (NULL);
    while (lst->next)
        lst = lst->next;
    return (lst);
}   