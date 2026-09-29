/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_strjoin.c                                                         */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:28:43                                         */
/*   Updated: 2026/09/29 02:28:43                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2){
	char	*str;
	size_t	len1;
	size_t	len2;
	size_t	i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!str)
		return (NULL);
	for (i = 0; i < len1; i++)
		str[i] = s1[i];
	for (i = 0; i < len2; i++)
		str[len1 + i] = s2[i];
	str[len1 + len2] = '\0';
	return (str);
}
