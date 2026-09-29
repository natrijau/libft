/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )  */
/*    `---'                                                       `---`  */
/*                                                                        */
/*   ft_alloc_str_array.c                                                */
/*   By: natrijau                                                        */
/*   Created: 2026/09/29 01:13:12                                        */
/*   Updated: 2026/09/29 01:13:12                                        */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

char	**ft_alloc_str_array(size_t n){
	char	**array;

	array = (char **)malloc(sizeof(char *) * (n + 1));
	return (array);
}