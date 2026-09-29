/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_count_digits.c                                                    */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:45:00                                         */
/*   Updated: 2026/09/29 02:45:00                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

int	ft_count_digits(int nb){
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = nb * -1;
	while (nb > 0){
		nb = nb / 10;
		count++;
	}
	return (count);
}