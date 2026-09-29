/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_substr.c                                                          */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:36:54                                         */
/*   Updated: 2026/09/29 02:36:54                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 11:55:11 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/10 14:46:02 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len){
	char	*str;
	size_t	s_len;
	size_t	substr_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (start >= s_len){
		str = (char *)malloc(sizeof(char));
		if (!str)
			return (NULL);
		str[0] = '\0';
		return (str);
	}
	substr_len = s_len - start;
	if (len < substr_len)
		substr_len = len;
	str = (char *)malloc(sizeof(char) * (substr_len + 1));
	if (!str)
		return (NULL);
	ft_strlcpy(str, s + start, substr_len + 1);
	return (str);
}