/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   ft_split.c                                                           */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 02:19:59                                         */
/*   Updated: 2026/09/29 02:19:59                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natrijau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:32:29 by natrijau          #+#    #+#             */
/*   Updated: 2023/11/14 13:51:31 by natrijau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_split(char const *s, char c){
	char	**split;
	size_t	nb_tokens;

	if (s == NULL)
		s = "";
	nb_tokens = ft_count_tokens(s, c);
	split = ft_alloc_str_array(nb_tokens);
	if (!split)
		return (NULL);
	return (ft_extract_tokens(s, c, split));
}