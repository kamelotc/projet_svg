# projet_svg

Le but du projet est de développer une interface par ligne de commande pour :

Créer, Éditer, Sauvegarder, Charger, Visualiser, des structures graphiques similaires au format SVG.
Les formes que j’ai utilisées sont :
Le Cercle.
L’Ellipse.
Le Carré.
Le Rectangle.
Ligne.

L’enchaînement de lignes, les polygones, le paths et les groupes, je n’ai pas pu les faire.
Et pour chaque forme on doit pouvoir :

- modifier la couleur de trait.

- modifier la couleur de fond.

- les déplacer en X et en Y.

- les pivoter selon un angle.

- les inverser selon l’axe X ou Y.

J’ai compilé en GCC, et utilisé C99.
Les librairies utilisées sont stdlib et stdio.
Pour commencer le projet j’ai fait un plan de tout ce que je devais effectuer en séparant les gros problèmes par des petits problèmes, le tout sur feuille.

Au début j’ai commencé par faire le main.c et le Makefile.
Puis les structures mais je me suis rendu compte que c’était plus clair de faire
un dossier par forme avec dedans un .c et un .h.

Les problèmes que j’ai rencontrés :
J’avais deux structures.
Mon do while faisait une boucle infinie.


