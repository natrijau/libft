/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_lstadd_back.c                                                     */
/*   By: natrijau                                                         */
/*   Created: 2026/09/30 02:37:15                                         */
/*   Updated: 2026/09/30 02:37:15                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

void ft_lstadd_back(t_list **alst, t_list *new)
{
    t_list *last;

    if (!alst || !new)
        return;
    if (!*alst)
    {
        *alst = new;
        return;
    }
    last = ft_lstlast(*alst);
    last->next = new;
}   