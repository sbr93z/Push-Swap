# Push-Swap

Push-Swap est un projet du cursus 42 qui consiste à trier une pile d'entiers en utilisant uniquement des opérations définies (push, swap, rotate, reverse rotate). L'objectif est de trier cette pile de manière optimale avec un nombre minimal d'opérations.

## Description

- **Algorithmique** : Utilisation d'algorithmes de tri optimisés, principalement avec des tris comme le tri par insertion et d'autres approches comme le tri en 3 étapes.
- **Opérations autorisées** : 
    - `sa` : Swap les deux premiers éléments de la pile A.
    - `sb` : Swap les deux premiers éléments de la pile B.
    - `ss` : Effectue `sa` et `sb` simultanément.
    - `pa` : Pousse le premier élément de la pile B dans la pile A.
    - `pb` : Pousse le premier élément de la pile A dans la pile B.
    - `ra` : Décale la pile A vers le haut.
    - `rb` : Décale la pile B vers le haut.
    - `rr` : Effectue `ra` et `rb` simultanément.
    - `rra` : Décale la pile A vers le bas.
    - `rrb` : Décale la pile B vers le bas.
    - `rrr` : Effectue `rra` et `rrb` simultanément.

## Installation

```bash
git clone git@github.com:sferrad/Push-Swap.git
cd push_swap
make
```
## Utilisation

Lancer le programme avec un ensemble de nombres :
```bash
./push_swap 5 4 3 2 1
```
Le programme va trier ces nombres avec un minimum d'opérations et afficher la séquence d'instructions nécessaires.

## Fichiers

libft/ : Ma bibliothèque personnelle, inclut les fonctions utiles comme `ft_printf`, `get_next_line`, etc.

utils/ : Contient le code principal du projet.

- `push_swap.c` : Fonction principale pour gérer les arguments et appeler les différentes étapes de tri.
- `instruction.c` : Définit les opérations de la pile et leur application.
- `sort.c` : Implémentation des algorithmes de tri.
- `utils.c`, `utils_2.c`, `utils_3.c` : Fonctions utilitaires pour la gestion des piles et des opérations.

Makefile : Fichier pour compiler et nettoyer le projet.
## Commandes Makefile
```bash
make : Compile les programmes.

make clean : Supprime les fichiers objets.

make fclean : Supprime les fichiers objets et les exécutables.

make re : fclean puis make.
```
## Fonctionnement

Le programme prend en entrée une liste de nombres et les trie en utilisant un algorithme de tri optimal avec des opérations de piles. Chaque opération effectuée est affichée à l'écran, et le but est de réduire au minimum le nombre d'opérations pour trier la pile.

L'algorithme est basé sur des techniques comme le tri par insertion et le tri de groupe, avec des optimisations spécifiques pour réduire le nombre d'opérations dans des cas particuliers.
