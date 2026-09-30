/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_lstdelone.c                                                       */
/*   By: natrijau                                                         */
/*   Created: 2026/09/30 02:37:34                                         */
/*   Updated: 2026/09/30 02:37:34                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

void ft_lstdelone(t_list *lst, void (*del)(void *))
{
    if (lst && del)
    {
        del(lst->content);
        free(lst);
    }
}   