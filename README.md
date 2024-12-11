# Libft

Bienvenue dans le dépôt **Libft** ! Ce projet a pour objectif de vous faire coder en C une bibliothèque de fonctions usuelles que vous pourrez utiliser pour vos prochains projets.

---

## Table des matières

1. [Introduction](#introduction)
2. [Règles communes](#règles-communes)
3. [Partie obligatoire](#partie-obligatoire)
   - [Considérations techniques](#considérations-techniques)
   - [Partie 1 - Fonctions de la libc](#partie-1---fonctions-de-la-libc)
   - [Partie 2 - Fonctions supplémentaires](#partie-2---fonctions-supplémentaires)
4. [Partie bonus](#partie-bonus)
5. [Rendu et évaluation](#rendu-et-évaluation)

---

## Introduction

La programmation en C peut devenir laborieuse sans accès à des fonctions pratiques. Ce projet vous propose de réécrire ces fonctions pour mieux les comprendre et vous les approprier. Cette bibliothèque pourra être enrichie et utilisée dans vos projets futurs.

Prenez le temps d'ajouter des fonctionnalités tout au long de l'année, mais veillez toujours à respecter les fonctions autorisées dans chaque projet.

---

## Règles communes

- Le projet doit être écrit en **C**.
- Respectez la **Norme**.
- Les fonctions ne doivent pas provoquer de comportement inattendu (segmentation fault, double free, etc.).
- Aucune **fuite mémoire** n'est tolérée.
- Un **Makefile** est requis et doit contenir au minimum les règles suivantes : `NAME`, `all`, `clean`, `fclean`, `re`.
- Les fichiers bonus doivent être inclus dans une règle dédiée nommée `bonus`.
- La bibliothèque doit être compilée avec la commande `ar` (et non `libtool`).

---

## Partie obligatoire

### Considérations techniques

- Interdiction d'utiliser des variables globales.
- Les fonctions auxiliaires doivent être définies en `static`.
- Tous les fichiers `.c` doivent être compilés avec les flags `-Wall -Wextra -Werror`.
- La bibliothèque doit être compilée en un fichier `libft.a` situé à la racine du dépôt.

### Partie 1 - Fonctions de la libc

Recodez les fonctions suivantes de la libc avec le préfixe `ft_` :

- **Manipulation de chaînes** : `toupper`, `tolower`, `strchr`, `strrchr`, `strncmp`, `strnstr`, `strlen`, `strlcpy`, `strlcat`
- **Tests de caractères** : `isalpha`, `isdigit`, `isalnum`, `isascii`, `isprint`
- **Manipulation de mémoire** : `memset`, `bzero`, `memcpy`, `memmove`, `memchr`, `memcmp`
- **Autres** : `atoi`
- **Fonctions nécessitant `malloc`** : `calloc`, `strdup`

### Partie 2 - Fonctions supplémentaires

Implémentez les fonctions suivantes :

- **Manipulation de chaînes** :
  - `ft_substr`
  - `ft_strjoin`
  - `ft_strtrim`
  - `ft_split`
- **Conversion** :
  - `ft_itoa`
- **Manipulation avancée de chaînes** :
  - `ft_strmapi`
  - `ft_striteri`
- **Affichage** :
  - `ft_putchar_fd`
  - `ft_putstr_fd`
  - `ft_putendl_fd`
  - `ft_putnbr_fd`

---

## Partie bonus

Pour aller plus loin, vous pouvez ajouter des fonctions bonus telles que la gestion de listes chaînées :

- `ft_lstnew`
- `ft_lstadd_front`
- `ft_lstsize`
- `ft_lstlast`
- `ft_lstadd_back`
- `ft_lstdelone`
- `ft_lstclear`
- `ft_lstiter`
- `ft_lstmap`

