/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )  */
/*    `---'                                                       `---`  */
/*                                                                        */
/*   ft_extract_tokens.c                                                 */
/*   By: natrijau                                                        */
/*   Created: 2026/09/29 01:14:11                                        */
/*   Updated: 2026/09/29 01:14:11                                        */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

char	**ft_extract_tokens(char const *s, char sep, char **array){
	size_t	i;
	size_t	j;
	size_t	len;

	i = 0;
	j = 0;
	while (s[i]){
		if (ft_is_separator(s[i], sep)){
			i++;
			continue ;
		}
		len = ft_token_len(s + i, sep);
		array[j] = ft_substr(s, i, len);
		if (!array[j]){
			ft_free_str_array(array);
			return (NULL);
		}
		i += len;
		j++;
	}
	array[j] = NULL;
	return (array);
}