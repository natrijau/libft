/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   get_next_line.h                                                      */
/*   By: natrijau                                                         */
/*   Created: 2026/09/30 01:59:23                                         */
/*   Updated: 2026/09/30 01:59:23                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <../libft.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# ifndef MAX_FD
#  define MAX_FD 1024
# endif

/*
** ---------------------------------------------------------------------------
** Utils (src/utils/get_next_line_utils.c)
** ---------------------------------------------------------------------------
*/

/* Check whether a string contains a newline character. */
int		have_nl(char *str);


/*
** ---------------------------------------------------------------------------
** Core (src/core/get_next_line.c)
** ---------------------------------------------------------------------------
*/

/* Return the next line and update the single-file stock. */
char	*get_next_line(int fd);
/* Cut the line portion from the beginning of a stock. */
char	*cut_nl_start(char *stock);
/* Cut the consumed line from the remaining stock. */
void	cut_nl_end(char **stock);
/* Extract one complete line from a stock. */
char	*get_line(char *stock);
/* Read data until a newline or end of file is reached. */
int		get_stock(char **stock, int fd);

/*
** ---------------------------------------------------------------------------
** Bonus utils (src/utils/get_next_line_utils_bonus.c)
** ---------------------------------------------------------------------------
*/

/* Check whether a string contains a newline character (bonus). */
int		have_nl_bonus(char *str);
/* Join two strings and return a newly allocated string (bonus). */
char	*ft_strjoin_bonus(char *s1, char *s2);
/* Return a newly allocated substring of a string (bonus). */
char	*ft_substr_bonus(char *s, unsigned int start, size_t len);
/* Allocate zero-initialized memory (bonus). */
void	*ft_calloc_bonus(size_t nmemb, size_t size);
/* Return the length of a string (bonus). */
size_t	ft_strlen_bonus(char *str);

/*
** ---------------------------------------------------------------------------
** Bonus core (src/core/get_next_line_bonus.c)
** ---------------------------------------------------------------------------
*/

/* Return the next line and update the multi-fd stock array (bonus). */
char	*get_next_line_bonus(int fd);
/* Cut the line portion from the beginning of a stock (bonus). */
char	*cut_nl_start_bonus(char *stock);
/* Cut the consumed line from the remaining stock (bonus). */
void	cut_nl_end_bonus(char **stock);
/* Extract one complete line from a stock (bonus). */
char	*get_line_bonus(char *stock);
/* Read data until a newline or end of file is reached (bonus). */
int		get_stock_bonus(char **stock, int fd);

#endif