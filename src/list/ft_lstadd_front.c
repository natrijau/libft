/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_lstadd_front.c                                                    */
/*   By: natrijau                                                         */
/*   Created: 2026/09/30 02:36:42                                         */
/*   Updated: 2026/09/30 02:36:42                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

void ft_lstadd_front(t_list **alst, t_list *new)
{
    if (alst && new)
    {
        new->next = *alst;
        *alst = new;
    }
}   