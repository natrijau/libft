/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_lstiter.c                                                         */
/*   By: natrijau                                                         */
/*   Created: 2026/09/30 02:50:47                                         */
/*   Updated: 2026/09/30 02:50:47                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}   