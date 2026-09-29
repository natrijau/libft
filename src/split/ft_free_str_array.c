/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )  */
/*    `---'                                                       `---`  */
/*                                                                        */
/*   ft_free_str_array.c                                                 */
/*   By: natrijau                                                        */
/*   Created: 2026/09/29 01:12:24                                        */
/*   Updated: 2026/09/29 01:12:24                                        */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

void	ft_free_str_array(char **array){

	if (!array)
		return ;

	for (size_t i = 0; array[i]; i++){
		free(array[i]);
	}
	
	free(array);
}