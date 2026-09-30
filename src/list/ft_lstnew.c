/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_lstnew.c                                                          */
/*   By: natrijau                                                         */
/*   Created: 2026/09/30 02:36:24                                         */
/*   Updated: 2026/09/30 02:36:24                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

t_list *ft_lstnew(void *content)
{
    t_list *new_node;

    new_node = malloc(sizeof(t_list));
    if (!new_node)
        return (NULL);
    new_node->content = content;
    new_node->next = NULL;
    return (new_node);
}   