/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_itoa.c                                                            */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:47:41                                         */
/*   Updated: 2026/09/29 02:47:41                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

static char	*ft_fill_number(char *tab, int count, int n, int is_negative){
	while (count >= 0){
		tab[count] = n % 10 + 48;
		n /= 10;
		count--;
	}
	if (is_negative)
		tab[0] = '-';
	return (tab);
}

char *ft_itoa(int n){
	int		is_negative;
	int		count;
	char	*tab;

	is_negative = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n < 0){
		is_negative = 1;
		n = -n;
	}
	count = ft_count_digits(n) + is_negative;
	tab = (char *)malloc(sizeof(char) * (count + 1));
	if (!tab)
		return (NULL);
	tab[count] = 0;
	count--;
	return (ft_fill_number(tab, count, n, is_negative));
}