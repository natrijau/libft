/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_lstclear.c                                                        */
/*   By: natrijau                                                         */
/*   Created: 2026/09/30 02:38:04                                         */
/*   Updated: 2026/09/30 02:38:04                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

void ft_lstclear(t_list **lst, void (*del)(void *))
{
    t_list *next_node;

    if (lst && del)
    {
        while (*lst)
        {
            next_node = (*lst)->next;
            ft_lstdelone(*lst, del);
            *lst = next_node;
        }
    }
}   