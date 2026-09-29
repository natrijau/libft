# Libft

Une bibliothèque C personnelle regroupant les fonctions utilitaires réécrites dans le cadre du projet **Libft**. Le dépôt est organisé par familles afin de garder une base de code lisible, modulaire et facile à intégrer dans d’autres projets C.

## Organisation du projet

Les sources sont regroupées dans les répertoires suivants :

```text
.
├── src/
│   ├── ctype/      # Tests et conversions de caractères
│   ├── memory/     # Manipulation de blocs mémoire
│   ├── string/     # Longueur, recherche et comparaison de chaînes
│   ├── stdlib/     # Conversion et allocation
│   └── list/       # Fonctions liées aux listes chaînées
├── Makefile
└── README.md
```

## Fonctions incluses

### Caractères — `src/ctype/`

- `ft_isalpha`
- `ft_isdigit`
- `ft_isalnum`
- `ft_isascii`
- `ft_isprint`
- `ft_toupper`
- `ft_tolower`

### Mémoire — `src/memory/`

- `ft_memset`
- `ft_bzero`
- `ft_memcpy`
- `ft_memmove`
- `ft_memchr`
- `ft_memcmp`
- `ft_calloc`

### Chaînes de caractères — `src/string/`

- `ft_strlen`
- `ft_strlcpy`
- `ft_strlcat`
- `ft_strchr`
- `ft_strrchr`
- `ft_strncmp`
- `ft_strnstr`
- `ft_strdup`

### Conversion — `src/stdlib/`

- `ft_atoi`

### Listes chaînées — `src/list/`

- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

## Compilation manuelle

Les fichiers sources peuvent être compilés avec les options suivantes :

```sh
cc -Wall -Wextra -Werror -c <fichier.c>
```

Les fichiers objets sont ensuite archivés dans la bibliothèque statique :

```sh
ar rcs libft.a *.o
```

## Commandes Makefile

Depuis la racine du projet :

| Commande | Rôle |
|---|---|
| `make` | Compile les sources et crée `libft.a`. |
| `make clean` | Supprime les fichiers objets (`.o`). |
| `make fclean` | Supprime les fichiers objets et `libft.a`. |
| `make re` | Lance un nettoyage complet puis recompile la bibliothèque. |
| `make help` | Affiche ce message d'aide |


## Utilisation

Inclure l’en-tête de la bibliothèque dans le code source :

```c
#include "libft.h"
```

Puis compiler le projet en ajoutant l’archive statique :

```sh
cc -Wall -Wextra -Werror main.c -L. -lft
```

## Vérifications

Le projet est compilé avec les avertissements suivants traités comme des erreurs :

```text
-Wall -Wextra -Werror
```

Les commandes `make`, `make clean`, `make fclean` et `make re` permettent de vérifier le cycle complet de compilation et de nettoyage.