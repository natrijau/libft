/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_check_int_overflow.c                                              */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:52:02                                         */
/*   Updated: 2026/09/29 02:52:02                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"
#include <limits.h>

int	ft_check_int_overflow(int current, int digit, int is_negative){
	if (is_negative){
		if (current < INT_MIN / 10)
			return (1);
		if (current == INT_MIN / 10 && digit > 8)
			return (1);
	}
	else{
		if (current > INT_MAX / 10)
			return (1);
		if (current == INT_MAX / 10 && digit > 7)
			return (1);
	}
	return (0);
}