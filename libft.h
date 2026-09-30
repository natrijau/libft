/* ~<(o )___ ====================================coincoin====== ___( o)>~ */
/*   ( ._> /                                                    \ <._ )   */
/*    `---'                                                       `---`   */
/*                                                                        */
/*   libft.h                                                              */
/*   By: natrijau                                                         */
/*   Created: 2026/09/29 01:29:52                                         */
/*   Updated: 2026/09/29 02:15:00                                         */
/*                                                                        */
/* ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~ */

#ifndef LIBFT_H
# define LIBFT_H

#include    <stdlib.h>
#include    <unistd.h>

typedef struct s_list{
	void			*content;
	struct s_list	*next;
}   t_list;

/* ----------------------------- Memory functions -------------------------- */

/* Remplit 'n' octets a partir de 's' avec des zeros. */
void	ft_bzero(void *s, size_t n);

/* Recherche le caractere 'c' dans les 'n' premiers octets de 's'. Retourne un pointeur ou NULL. */
void	*ft_memchr(const void *s, int c, size_t n);

/* Copie 'n' octets de 'src' vers 'dest' (pas de chevauchement). */
void	*ft_memcpy(void *dest, const void *src, size_t n);

/* Copie 'n' octets de 'src' vers 'dest' (gere les chevauchements). */
void	*ft_memmove(void *dest, const void *src, size_t n);

/* Remplit 'n' octets a partir de 'str' avec le caractere 'c'. */
void	*ft_memset(void *str, int c, size_t n);

/* Alloue et initialise a zero un bloc memoire pour 'nmemb' elements de 'size' octets. */
void	*ft_calloc(size_t nmemb, size_t size);

/* Compare les 'n' premiers octets de 's1' et 's2'. Retourne la difference. */
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/* --------------------------- Character functions -------------------------- */

/* Verifie si 'c' est un caractere alphanumerique. */
int		ft_isalnum(int c);

/* Verifie si 'c' est une lettre. */
int		ft_isalpha(int c);

/* Verifie si 'c' est un caractere ASCII. */
int		ft_isascii(int c);

/* Verifie si 'c' est un chiffre. */
int		ft_isdigit(int c);

/* Verifie si 'c' est un caractere imprimable. */
int		ft_isprint(int c);

/* Convertit 'c' en minuscule. */
int		ft_tolower(int c);

/* Convertit 'c' en majuscule. */
int		ft_toupper(int c);

/* --------------------------- Bonus (Linked List) -------------------------- */

/* Cree un nouveau noeud avec 'content' et next = NULL. */
t_list	*ft_lstnew(void *content);

/* Ajoute le noeud 'new' au debut de la liste 'lst'. */
void	ft_lstadd_front(t_list **lst, t_list *new);

/* Compte le nombre de noeuds dans la liste. */
int		ft_lstsize(t_list *lst);

/* Retourne le dernier noeud de la liste. */
t_list	*ft_lstlast(t_list *lst);

/* Ajoute le noeud 'new' a la fin de la liste 'lst'. */
void	ft_lstadd_back(t_list **lst, t_list *new);

/* Libere un noeud et son contenu (via 'del'). */
void	ft_lstdelone(t_list *lst, void (*del)(void *));

/* Libere toute la liste et met le pointeur a NULL. */
void	ft_lstclear(t_list **lst, void (*del)(void *));

/* Applique 'f' au contenu de chaque noeud. */
void	ft_lstiter(t_list *lst, void (*f)(void *));

/* Cree une nouvelle liste en appliquant 'f' a chaque noeud. */
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ----------------------------- String functions --------------------------- */

/* Retourne la longueur de 'str'. */
size_t	ft_strlen(const char *str);

/* Ajoute 'src' a 'dst' jusqu'a 'size', termine par '\0'. Retourne la longueur totale. */
size_t	ft_strlcat(char *dst, const char *src, size_t size);

/* Copie jusqu'a 'size - 1' caracteres de 'src' dans 'dst', termine par '\0'. */
size_t	ft_strlcpy(char *dst, const char *src, size_t size);

/* Compare les 'n' premiers caracteres de 's1' et 's2'. */
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/* Recherche la premiere occurrence de 'c' dans 's'. */
char	*ft_strchr(const char *s, int c);

/* Recherche la derniere occurrence de 'c' dans 's'. */
char	*ft_strrchr(const char *s, int c);

/* Recherche 'little' dans 'big', limitee a 'len' caracteres. */
char	*ft_strnstr(const char *big, const char *little, size_t len);

/* Duplique 's' en allouant une nouvelle chaine. */
char	*ft_strdup(const char *s);

/* Extrait une sous-chaine de 's' a partir de 'start', 'len' caracteres max. */
char	*ft_substr(char const *s, unsigned int start, size_t len);

/* Concatene 's1' et 's2' dans une nouvelle chaine. */
char	*ft_strjoin(char const *s1, char const *s2);

/* Cree une nouvelle chaine en supprimant les caracteres de 'set' aux extremites de 's1'. */
char	*ft_strtrim(char const *s1, char const *set);

/* Applique la fonction 'f' a chaque caractere de 's' avec son index. Retourne une nouvelle chaine. */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/* Applique la fonction 'f' a chaque caractere de 's' avec son index. Modifie 's' sur place. */
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/* ------------------------- Conversion functions --------------------------- */

/* Convertit 'nptr' en nombre entier. */
int		ft_atoi(const char *nptr);

/*
** Verifie si (current * 10) + next_digit causera un overflow sur un int.
** Retourne 1 si overflow, 0 sinon.
** Generique : utilisable dans atoi, conversions numeriques, parsing, etc.
**
** Params:
**   current  : valeur actuelle accumulee
**   digit    : prochain chiffre a ajouter (0-9)
**   is_negative : 1 si nombre negatif, 0 sinon
*/
int	ft_check_int_overflow(int current, int digit, int is_negative);

/*
** Compte le nombre de chiffres dans l'entier 'nb'.
** Retourne 1 si nb == 0, sinon le nombre de chiffres.
*/
int		ft_count_digits(int nb);

/* Convertit l'entier 'n' en chaine de caracteres allouee. */
char	*ft_itoa(int n);

/* ----------------------------- Split & tokens ------------------------------ */

/* Decoupe 's' en tableau de strings delimiter par 'c'. Le tableau est termine par NULL. */
char	**ft_split(char const *s, char c);

/* Alloue un tableau de 'n' pointeurs char * avec slot pour NULL terminal. */
char	**ft_alloc_str_array(size_t n);

/* Extrait les tokens de 's' (delimiter par 'sep') dans 'array'. Chaque token est une nouvelle string. */
char	**ft_extract_tokens(char const *s, char sep, char **array);

/* Libere un tableau de strings et son contenu. */
void	ft_free_str_array(char **array);

/* Compte le nombre de tokens dans 'str', delimiter par 'sep'. */
size_t	ft_count_tokens(const char *str, char sep);

/* Retourne la longueur du token commencant a 'str' (avant 'sep' ou '\0'). */
size_t	ft_token_len(const char *str, char sep);

/* Verifie si 'c' est le separateur 'sep'. */
int		ft_is_separator(char c, char sep);

/* ---------------------------- Output (fd) functions ------------------------ */

/* Ecrit le caractere 'c' sur le descripteur de fichier 'fd'. */
void	ft_putchar_fd(char c, int fd);

/* Ecrit la chaine 's' sur le descripteur de fichier 'fd'. */
void	ft_putstr_fd(char *s, int fd);

/* Ecrit la chaine 's' suivie d'une nouvelle ligne sur le descripteur de fichier 'fd'. */
void	ft_putendl_fd(char *s, int fd);

/* Ecrit l'entier 'n' sur le descripteur de fichier 'fd'. */
void	ft_putnbr_fd(int n, int fd);

#endif  