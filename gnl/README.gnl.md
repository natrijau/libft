# get_next_line

## Table des matières

- [Présentation](#présentation)
- [Fonctionnalités](#fonctionnalités)
- [Architecture du projet](#architecture-du-projet)
- [Installation](#installation)
- [Commandes Makefile](#commandes-makefile)
- [Utilisation](#utilisation)
- [Section Makefile](#section-makefile)
- [Auteur](#auteur)
- [Licence](#licence)

## Présentation

`get_next_line` est une réimplémentation en C de la fonction standard `get_next_line`. Elle permet de lire une ligne depuis un descripteur de fichier, dans le cadre du cursus de l'école 42.

Le projet lit le fichier par blocs de taille `BUFFER_SIZE` et retourne une ligne à la fois, caractère de fin de ligne `\n` inclus. Il retourne `NULL` en fin de fichier ou en cas d'erreur. Une bibliothèque statique est produite par la compilation.

## Fonctionnalités

- Lecture progressive d'un fichier par blocs de taille `BUFFER_SIZE`.
- Retour d'une seule ligne par appel, avec `\n` lorsqu'il est présent.
- `BUFFER_SIZE` configurable, avec une valeur par défaut de `42` définie dans `get_next_line.h`.
- Version obligatoire utilisant un stock statique unique.
- Version bonus permettant de gérer simultanément plusieurs descripteurs de fichiers grâce à un tableau statique de stocks indexé par `fd`.
- `MAX_FD` configurable, avec une valeur par défaut de `1024` pour la version bonus.
- Fonctions utilitaires : `have_nl`, `ft_strlen`, `ft_calloc`, `ft_strjoin` et `ft_substr`, ainsi que leurs variantes bonus.
- Fonctions du cœur : `get_next_line`, `cut_nl_start`, `cut_nl_end`, `get_line` et `get_stock`.

## Architecture du projet

```text
get_next_line/
├── get_next_line.h
├── Makefile
├── README.md
└── src/
    ├── core/
    │   ├── get_next_line.c
    │   └── get_next_line_bonus.c
    └── utils/
        ├── get_next_line_utils.c
        └── get_next_line_utils_bonus.c
```

Le dossier `obj/` est généré lors de la compilation. Son arborescence reprend en miroir celle du dossier `src/`.

## Installation

Cloner le dépôt, entrer dans le dossier du projet, puis compiler la version obligatoire :

```bash
git clone <url-du-depot> get_next_line
cd get_next_line
make
```

## Commandes Makefile

| Commande | Description |
| --- | --- |
| `make` | Compile la version obligatoire et génère `get_next_line.a`. |
| `make bonus` | Compile la version multi-descripteurs et génère `get_next_line_bonus.a`. |
| `make clean` | Supprime le dossier `obj/`. |
| `make fclean` | Supprime `obj/` et les deux archives. |
| `make re` | Nettoie puis recompile. |
| `make help` | Affiche les cibles disponibles. |

## Utilisation

Inclure l'en-tête du projet dans le fichier qui utilise la fonction :

```c
#include "get_next_line.h"
```

Compiler ensuite le programme avec la bibliothèque statique :

```bash
gcc -Wall -Wextra -Werror -I. main.c get_next_line.a -o exemple
```

Exemple de lecture de toutes les lignes d'un fichier :

```c
int fd = open("fichier.txt", O_RDONLY);
char *ligne;

while ((ligne = get_next_line(fd)) != NULL)
{
    printf("%s", ligne);
    free(ligne);
}
close(fd);
```

La valeur de `BUFFER_SIZE` peut être remplacée à la compilation avec `-DBUFFER_SIZE=...`, par exemple :

```bash
gcc -Wall -Wextra -Werror -I. -DBUFFER_SIZE=9999 main.c get_next_line.a -o exemple
```

La sortie attendue reprend simplement le contenu du fichier lu :

```text
contenu du fichier
```

## Section Makefile

Le Makefile compile avec `gcc` et les options suivantes :

- `-Wall` : active les avertissements courants.
- `-Wextra` : active des avertissements supplémentaires.
- `-Werror` : transforme les avertissements en erreurs.
- `-I.` : indique le répertoire courant pour la recherche des en-têtes.

Les fichiers objets sont générés dans `obj/`, avec une arborescence en miroir de `src/`. Ils sont ensuite archivés dans les deux bibliothèques statiques : `get_next_line.a` pour la version obligatoire et `get_next_line_bonus.a` pour la version bonus.

## Auteur

- **Nom :** natrijau
- **Établissement :** école 42

## Licence

Projet pédagogique réalisé dans le cadre de l'école 42. Aucune licence de distribution spécifique ne s'applique au-delà des règles applicables au projet pédagogique.
