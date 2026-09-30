# libft

Bibliothèque C personnelle regroupant la **libft**, **get_next_line** et **ft_printf** dans un même projet. Elle est conçue pour être compilée facilement et réutilisée dans les projets C/42.

## Sommaire

- [Structure du projet](#structure-du-projet)
- [Compilation](#compilation)
- [Utilisation](#utilisation)
- [Fonctions de la libft](#fonctions-de-la-libft)
- [Get Next Line](#get-next-line)
- [ft_printf](#ft_printf)
- [Contraintes et qualité du code](#contraintes-et-qualité-du-code)

## Structure du projet

```text
.
├── Makefile
├── README.md
├── include/
│   └── libft.h                 # En-têtes publics (selon l'organisation du projet)
├── src/                        # Fonctions principales de la libft
│   ├── ctype/                  # Classification et conversion de caractères
│   ├── memory/                 # Manipulation de zones mémoire
│   ├── string/                 # Manipulation de chaînes
│   ├── conversion/             # Conversions numériques et chaînes
│   ├── fd/                     # Écriture vers un descripteur
│   └── list/                   # Fonctions de listes chaînées
├── gnl/                        # Module get_next_line
│   ├── get_next_line.c
│   ├── get_next_line_utils.c
│   └── get_next_line.h
└── printf/                     # Module ft_printf
    ├── ft_printf.c
    ├── ft_printf_utils.c
    └── ft_printf.h
```

> Les noms de fichiers utilitaires peuvent varier selon l'organisation retenue. La séparation fonctionnelle reste la suivante : `src/` pour la libft, `gnl/` pour la lecture ligne par ligne et `printf/` pour l'affichage formaté.

## Compilation

Le projet utilise `make` et produit généralement une bibliothèque statique `libft.a` à la racine du projet.

```bash
make          # Compile la libft et les modules intégrés
make bonus    # Ajoute les fonctions bonus de listes, si elles sont prévues
make clean    # Supprime les fichiers objets (.o)
make fclean   # Supprime les fichiers objets et libft.a
make re       # Exécute fclean puis make
```

### Cibles complémentaires recommandées

Si elles sont définies dans le `Makefile`, les cibles suivantes peuvent aussi être utilisées :

```bash
make norm     # Lance norminette
make test     # Lance la suite de tests du projet
```

Vérifier les cibles effectivement disponibles avec :

```bash
make help     # si cette cible est fournie
sed -n '1,220p' Makefile
```

## Utilisation

### Inclure la bibliothèque

Depuis un fichier C situé dans le projet :

```c
#include "libft.h"
```

Ou, si les en-têtes sont dans `include/` :

```bash
cc -Wall -Wextra -Werror -Iinclude main.c -L. -lft -o programme
```

Exemple minimal :

```c
#include "libft.h"

int main(void)
{
    ft_putendl_fd("Bonjour depuis libft", 1);
    ft_printf("Valeur : %d\n", 42);
    return (0);
}
```

Compiler et exécuter :

```bash
make
cc -Wall -Wextra -Werror -Iinclude main.c -L. -lft -o programme
./programme
```

### Utiliser get_next_line

`get_next_line` lit une ligne par appel et conserve automatiquement les données restantes entre deux appels. La ligne renvoyée contient le `\n` lorsqu'il est présent, et est terminée par `\0`.

```c
#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
    int     fd;
    char    *line;

    fd = open("fichier.txt", O_RDONLY);
    if (fd == -1)
        return (1);
    line = get_next_line(fd);
    while (line != NULL)
    {
        write(1, line, ft_strlen(line));
        free(line);
        line = get_next_line(fd);
    }
    close(fd);
    return (0);
}
```

Selon l'implémentation, `BUFFER_SIZE` peut être défini à la compilation :

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -Iinclude main.c -L. -lft -o lecteur
```

## Fonctions de la libft

### Caractères

| Fonction | Rôle |
|---|---|
| `ft_isalpha` | Vérifie si le caractère est alphabétique |
| `ft_isdigit` | Vérifie si le caractère est un chiffre décimal |
| `ft_isalnum` | Vérifie si le caractère est alphanumérique |
| `ft_isascii` | Vérifie si la valeur appartient à l'ASCII |
| `ft_isprint` | Vérifie si le caractère est imprimable |
| `ft_toupper` | Convertit une lettre en majuscule |
| `ft_tolower` | Convertit une lettre en minuscule |

### Mémoire

| Fonction | Rôle |
|---|---|
| `ft_memset` | Remplit une zone mémoire avec une valeur |
| `ft_bzero` | Met une zone mémoire à zéro |
| `ft_memcpy` | Copie une zone mémoire non chevauchante |
| `ft_memmove` | Copie une zone mémoire, y compris chevauchante |
| `ft_memchr` | Recherche un octet dans une zone mémoire |
| `ft_memcmp` | Compare deux zones mémoire |
| `ft_calloc` | Alloue et initialise une zone à zéro |

### Chaînes de caractères

| Fonction | Rôle |
|---|---|
| `ft_strlen` | Retourne la longueur d'une chaîne |
| `ft_strlcpy` | Copie une chaîne avec terminaison contrôlée |
| `ft_strlcat` | Concatène avec une taille de destination contrôlée |
| `ft_strchr` | Recherche la première occurrence d'un caractère |
| `ft_strrchr` | Recherche la dernière occurrence d'un caractère |
| `ft_strncmp` | Compare au plus `n` caractères |
| `ft_strnstr` | Recherche une sous-chaîne dans une longueur donnée |
| `ft_strdup` | Duplique une chaîne |
| `ft_substr` | Extrait une sous-chaîne allouée |
| `ft_strjoin` | Assemble deux chaînes dans une nouvelle chaîne |
| `ft_strtrim` | Retire un ensemble de caractères aux extrémités |
| `ft_split` | Découpe une chaîne selon un séparateur |
| `ft_strmapi` | Applique une fonction à chaque caractère |
| `ft_striteri` | Applique une fonction avec index à chaque caractère |

### Conversions et sortie

| Fonction | Rôle |
|---|---|
| `ft_atoi` | Convertit une chaîne en entier |
| `ft_itoa` | Convertit un entier en chaîne allouée |
| `ft_putchar_fd` | Écrit un caractère vers un descripteur |
| `ft_putstr_fd` | Écrit une chaîne vers un descripteur |
| `ft_putendl_fd` | Écrit une chaîne suivie d'un saut de ligne |
| `ft_putnbr_fd` | Écrit un entier vers un descripteur |

### Listes chaînées — bonus

| Fonction | Rôle |
|---|---|
| `ft_lstnew` | Crée un nouvel élément |
| `ft_lstadd_front` | Ajoute un élément au début |
| `ft_lstsize` | Compte les éléments |
| `ft_lstlast` | Retourne le dernier élément |
| `ft_lstadd_back` | Ajoute un élément à la fin |
| `ft_lstdelone` | Supprime un élément |
| `ft_lstclear` | Supprime toute une liste |
| `ft_lstiter` | Applique une fonction à chaque élément |
| `ft_lstmap` | Crée une liste transformée |

Le type habituellement associé aux listes est :

```c
typedef struct s_list
{
    void            *content;
    struct s_list    *next;
}   t_list;
```

## Get Next Line

### API publique

| Fonction | Rôle |
|---|---|
| `get_next_line` | Retourne la prochaine ligne d'un descripteur |
| `get_next_line_bonus` | Variante bonus permettant plusieurs descripteurs simultanés, si fournie |

### Comportement

- Retourne une chaîne allouée ou `NULL` en cas de fin de fichier ou d'erreur.
- Conserve les caractères lus après le saut de ligne pour l'appel suivant.
- Accepte un descripteur de fichier valide et une valeur de `BUFFER_SIZE` strictement positive.
- La mémoire de chaque ligne retournée doit être libérée par l'appelant.
- Les erreurs de lecture et les descripteurs invalides doivent être traités sans fuite mémoire.

## ft_printf

`ft_printf` reproduit le comportement essentiel de `printf` en écrivant sur la sortie standard et retourne le nombre de caractères écrits.

### API publique

| Fonction | Rôle |
|---|---|
| `ft_printf` | Affiche une chaîne selon une chaîne de format |

### Conversions prises en charge

| Spécificateur | Type attendu | Description |
|---|---|---|
| `%c` | `int` | Caractère |
| `%s` | `char *` | Chaîne de caractères |
| `%p` | `void *` | Adresse en hexadécimal préfixée par `0x` |
| `%d` | `int` | Entier signé en base 10 |
| `%i` | `int` | Entier signé en base 10 |
| `%u` | `unsigned int` | Entier non signé en base 10 |
| `%x` | `unsigned int` | Entier hexadécimal en minuscules |
| `%X` | `unsigned int` | Entier hexadécimal en majuscules |
| `%%` | aucun | Caractère `%` littéral |

Exemple :

```c
ft_printf("Texte : %s\nEntier : %d\nAdresse : %p\n", "libft", 42, ptr);
```

Les fonctions internes de conversion et d'écriture du dossier `printf/` ne constituent pas l'API publique : elles servent à l'implémentation de `ft_printf` et peuvent être nommées différemment selon le projet.

## Contraintes et qualité du code

La compilation recommandée utilise :

```bash
-Wall -Wextra -Werror
```

Avant de publier une modification :

```bash
make fclean && make
make bonus
norminette
```

Vérifier notamment :

- les valeurs de retour des appels système et allocations ;
- la libération de toute mémoire allouée en cas d'erreur ;
- la gestion des chaînes `NULL` selon le contrat de chaque fonction ;
- les cas limites : chaîne vide, entier négatif, `INT_MIN`, fichier vide et dernière ligne sans `\n` ;
- l'absence de fichiers objets ou binaires générés dans le dépôt.

## Licence

Projet pédagogique. Les modalités de réutilisation et de distribution dépendent du dépôt qui contient cette bibliothèque.












# libft

Bibliothèque C personnelle regroupant les fonctions utilitaires de la **libft core**, ainsi que deux modules complémentaires : **get_next_line (gnl)** et **ft_printf (printf)**.

## Structure globale


```text
.
├── Makefile                    # Build système principal (gère libft, gnl, printf)
├── README.md                   # Documentation générale du projet
├── libft.h                     # En-têtes publics principaux
│
├── src/                        # Fonctions principales de la libft (40 fonctions)
│   │
│   ├── character/              # Classification et conversion de caractères (7 fonctions)
│   │   ├── ft_isalnum.c
│   │   ├── ft_isalpha.c
│   │   ├── ft_isascii.c
│   │   ├── ft_isdigit.c
│   │   ├── ft_isprint.c
│   │   ├── ft_tolower.c
│   │   └── ft_toupper.c
│   │
│   ├── convert/                # Conversions numériques (4 fonctions)
│   │   ├── ft_atoi.c
│   │   ├── ft_itoa.c
│   │   ├── ft_count_digits.c
│   │   └── ft_check_int_overflow.c
│   │
│   ├── list/                   # Fonctions de listes chaînées (9 fonctions)
│   │   ├── ft_lstnew.c
│   │   ├── ft_lstadd_front.c
│   │   ├── ft_lstadd_back.c
│   │   ├── ft_lstsize.c
│   │   ├── ft_lstlast.c
│   │   ├── ft_lstdelone.c
│   │   ├── ft_lstclear.c
│   │   ├── ft_lstiter.c
│   │   └── ft_lstmap.c
│   │
│   ├── memory/                 # Manipulation de zones mémoire (7 fonctions)
│   │   ├── ft_bzero.c
│   │   ├── ft_calloc.c
│   │   ├── ft_memchr.c
│   │   ├── ft_memcmp.c
│   │   ├── ft_memcpy.c
│   │   ├── ft_memmove.c
│   │   └── ft_memset.c
│   │
│   ├── output/                 # Affichage et écriture (6 fonctions)
│   │   ├── ft_putchar.c
│   │   ├── ft_putchar_fd.c
│   │   ├── ft_putendl_fd.c
│   │   ├── ft_putnbr_fd.c
│   │   ├── ft_putstr.c
│   │   └── ft_putstr_fd.c
│   │
│   ├── split/                  # Tokenization et découpage (7 fonctions)
│   │   ├── ft_split.c
│   │   ├── ft_alloc_str_array.c
│   │   ├── ft_count_tokens.c
│   │   ├── ft_extract_tokens.c
│   │   ├── ft_free_str_array.c
│   │   ├── ft_is_separator.c
│   │   └── ft_token_len.c
│   │
│   └── string/                 # Manipulation de chaînes (13 fonctions)
│       ├── ft_strchr.c
│       ├── ft_strdup.c
│       ├── ft_striteri.c
│       ├── ft_strjoin.c
│       ├── ft_strlcat.c
│       ├── ft_strlcpy.c
│       ├── ft_strlen.c
│       ├── ft_strmapi.c
│       ├── ft_strncmp.c
│       ├── ft_strnstr.c
│       ├── ft_strrchr.c
│       ├── ft_strtrim.c
│       └── ft_substr.c
│
├── gnl/                        # Module Get Next Line (lecture fichier ligne par ligne)
│   ├── Makefile
│   ├── README.gnl.md           # Documentation détaillée du module
│   ├── get_next_line.h
│   └── src/
│       ├── core/
│       │   ├── get_next_line.c
│       │   └── get_next_line_bonus.c
│       └── utils/
│           ├── get_next_line_utils.c
│           └── get_next_line_utils_bonus.c
│
├── printf/                     # Module Ft_printf (formatage et affichage avancé)
│   ├── Makefile
│   ├── README.printf.md        # Documentation détaillée du module
│   ├── ft_printf.h
│   └── src/
│       ├── main/
│       │   └── ft_printf.c
│       ├── convert/
│       │   ├── ft_nbr_unsigned.c
│       │   ├── ft_hexa_min.c
│       │   ├── ft_hexa_maj.c
│       │   ├── ft_pointer_hexa.c
│       │   └── ft_float.c
│       └── format/
│           └── ft_percent.c
│
├── obj/                        # Fichiers objets générés (git-ignored)
│   ├── character/
│   ├── convert/
│   ├── list/
│   ├── memory/
│   ├── output/
│   ├── split/
│   └── string/
│
├── libft.a                     # Archive statique finale (git-ignored)
└── .gitignore                  # Fichiers à ignorer
```

Chaque module peut être compilé et utilisé indépendamment. La bibliothèque core fournit les primitives communes ; `gnl` et `printf` ajoutent respectivement la lecture ligne par ligne et le formatage de sorties.

## libft core — 40 fonctions

### Caractères

| Fonction | Rôle |
| --- | --- |
| `ft_isalpha` | Vérifie si un caractère est alphabétique. |
| `ft_isdigit` | Vérifie si un caractère est un chiffre décimal. |
| `ft_isalnum` | Vérifie si un caractère est alphanumérique. |
| `ft_isascii` | Vérifie si une valeur appartient à l'ASCII. |
| `ft_isprint` | Vérifie si un caractère est imprimable. |

### Conversion de casse et longueur

| Fonction | Rôle |
| --- | --- |
| `ft_toupper` | Convertit une lettre minuscule en majuscule. |
| `ft_tolower` | Convertit une lettre majuscule en minuscule. |
| `ft_strlen` | Calcule la longueur d'une chaîne. |

### Mémoire

| Fonction | Rôle |
| --- | --- |
| `ft_memset` | Remplit une zone mémoire avec un octet. |
| `ft_bzero` | Met une zone mémoire à zéro. |
| `ft_memcpy` | Copie une zone mémoire non chevauchante. |
| `ft_memmove` | Copie une zone mémoire, y compris si elle se chevauche. |
| `ft_memchr` | Recherche un octet dans une zone mémoire. |
| `ft_memcmp` | Compare deux zones mémoire. |

### Chaînes : copie et recherche

| Fonction | Rôle |
| --- | --- |
| `ft_strlcpy` | Copie une chaîne avec limitation de taille. |
| `ft_strlcat` | Concatène une chaîne avec limitation de taille. |
| `ft_strchr` | Recherche la première occurrence d'un caractère. |
| `ft_strrchr` | Recherche la dernière occurrence d'un caractère. |
| `ft_strncmp` | Compare au plus `n` caractères. |
| `ft_strnstr` | Recherche une sous-chaîne dans une chaîne limitée. |

### Conversion et allocation

| Fonction | Rôle |
| --- | --- |
| `ft_atoi` | Convertit une chaîne en entier. |
| `ft_calloc` | Alloue et initialise une zone mémoire à zéro. |
| `ft_strdup` | Duplique une chaîne. |

### Construction et transformation de chaînes

| Fonction | Rôle |
| --- | --- |
| `ft_substr` | Extrait une sous-chaîne. |
| `ft_strjoin` | Assemble deux chaînes. |
| `ft_strtrim` | Retire un ensemble de caractères aux extrémités. |
| `ft_split` | Découpe une chaîne selon un séparateur. |
| `ft_itoa` | Convertit un entier en chaîne. |
| `ft_strmapi` | Applique une fonction à chaque caractère et crée une nouvelle chaîne. |
| `ft_striteri` | Applique une fonction à chaque caractère, sur place. |

### Écriture sur des descripteurs

| Fonction | Rôle |
| --- | --- |
| `ft_putchar_fd` | Écrit un caractère sur un descripteur. |
| `ft_putstr_fd` | Écrit une chaîne sur un descripteur. |
| `ft_putendl_fd` | Écrit une chaîne suivie d'un retour à la ligne. |
| `ft_putnbr_fd` | Écrit un entier sur un descripteur. |

### Listes chaînées

| Fonction | Rôle |
| --- | --- |
| `ft_lstnew` | Crée un élément de liste. |
| `ft_lstadd_front` | Ajoute un élément au début. |
| `ft_lstsize` | Compte les éléments d'une liste. |
| `ft_lstlast` | Retourne le dernier élément. |
| `ft_lstadd_back` | Ajoute un élément à la fin. |
| `ft_lstclear` | Supprime et libère tous les éléments. |

> **Total : 40 fonctions core.** Les prototypes et les structures publiques sont disponibles dans `libft.h`.

## Modules complémentaires

### gnl

Pour plus d'informations sur **gnl**, voir [`README GNL`](gnl/README.gnl.md).

`get_next_line` lit une ligne depuis un descripteur à chaque appel, conserve le reliquat entre les appels et retourne `NULL` en fin de fichier ou en cas d'erreur.

### printf

Pour plus d'informations sur **printf**, voir [`README printf`](printf/README.printf.md).

`ft_printf` fournit un formatage proche de `printf`, avec les conversions et règles documentées dans le README du module.

## Compilation avec Make

Depuis la racine du dépôt :

```bash
# Bibliothèque core uniquement
make
# ou
make all

# Nettoyer les fichiers objets
make clean

# Supprimer les objets et la bibliothèque compilée
make fclean

# Recompiler proprement
make re
```

Selon l'organisation des Makefiles, les modules peuvent aussi être construits séparément :

```bash
make -C gnl
make -C printf
```

Si le Makefile global expose des cibles dédiées, les variantes suivantes sont également disponibles :

```bash
make gnl
make printf
make bonus
```

Utiliser `make help` pour afficher les cibles effectivement proposées par le dépôt. Les cibles absentes d'un Makefile doivent être remplacées par la commande `make -C <module>` correspondante.

## Utilisation des trois composants

### 1. Utiliser la core libft

```c
#include "libft.h"

int main(void)
{
    char *copy = ft_strdup("hello, libft");

    if (!copy)
        return (1);
    ft_putendl_fd(copy, 1);
    free(copy);
    return (0);
}
```

Compiler avec la bibliothèque core :

```bash
cc -Wall -Wextra -Werror main.c -I. -L. -lft -o demo
```

### 2. Utiliser gnl avec la core libft

```c
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int     fd;
    char    *line;

    if (argc != 2)
        return (1);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_putstr_fd(line, 1);
        free(line);
    }
    close(fd);
    return (0);
}
```

Exemple de compilation (adapter les chemins et le nom des archives au Makefile) :

```bash
cc -Wall -Wextra -Werror main.c gnl/get_next_line.c \
   gnl/get_next_line_utils.c -I. -Ignl -L. -lft -o reader
```

### 3. Utiliser ft_printf avec la core libft

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Nom: %s | valeur: %d | hexadécimal: %x\n",
        "libft", 42, 42);
    return (0);
}
```

Exemple de compilation :

```bash
cc -Wall -Wextra -Werror main.c printf/ft_printf.c \
   printf/ft_printf_utils.c -I. -Iprintf -L. -lft -o formatter
```

### 4. Combiner les trois composants

```c
#include "get_next_line.h"
#include "ft_printf.h"

int main(int argc, char **argv)
{
    int  fd;
    char *line;

    if (argc != 2)
        return (1);
    fd = open(argv[1], O_RDONLY);
    if (fd < 0)
        return (1);
    while ((line = get_next_line(fd)) != NULL)
    {
        ft_printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

Le principe reste identique : construire chaque module, inclure son header, puis lier les objets ou les archives correspondant à la structure réelle du dépôt.

## Dépendances et conventions

- Projet en C compilé avec `-Wall -Wextra -Werror`.
- Les headers doivent être ajoutés avec `-I` lorsque le module n'est pas dans le répertoire courant.
- Toute mémoire retournée par une fonction d'allocation doit être libérée par l'appelant.
- Les chemins des sources indiqués dans les exemples sont indicatifs : vérifier les noms exacts dans les Makefiles de `gnl` et `printf`.
