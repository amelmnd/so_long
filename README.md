<h1 align="center">So long</h1> 
<p align="center">
	<img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" />
</p>
<div align="center">
	<img src="./so_long.gif" width="450" height="150" />
</div>

- [Description](#description)
- [Structure du projet](#structure-du-projet)
- [Utilisation de push\_swap](#utilisation-de-push_swap)
	- [Pre-requis](#pre-requis)
	- [Compilation du projet](#compilation-du-projet)
	- [Exécution du projet](#exécution-du-projet)


## Description

Le but de ce projet est de développer un programme permettant de trier des données entrées par l'utilisateur et de trier ces entiers (positifs et négatifs) dans une pile passée en paramètre par ordre croissant.

Il n'est autorisé de n'utiliser que deux piles avec un ensemble d’instructions limité, et de réaliser le moins de coups possibles.

Ce projet est le premier algorithme de tri que j'ai codé, et pour le faire j'ai utilisé l'algorithme Bubble Sort pour indexer les chiffres et je les ai ensuite triés à l'aide de l'algorithme Radix.

## Structure du projet
```tree
├── assets
├── game
├── include
├── map
├── mlx
├── parsing
└── utils
```
  
- assets : images rendu sur la map
- include et utils : fonctions necessaire au projet
- mlx : librairie de rendu 3d
- parsing : fonction de traitement des cartes jeux
- gqame : fonction de gestion de jeux
- sort : les fonstions de trie

## Utilisation de push_swap

### Pre-requis

* **compilateur `gcc`**
  
### Compilation du projet 
```shell
make
```
### Exécution du projet 

```shell
./so_long map/*/*
```
_valeur max gerer 500 nombres aléatoires, en maximum 5500 opérations_
