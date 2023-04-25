# But du projet :

## Base du projet :
Créer un TUI en C, sans *Curses* :
* Contrôler un tableau de char pour chaque "fenêtre" (struct)
* Pouvoir récupérer les inputs de l'utilisateur
* Pouvoir afficher une image (pixel art) avec les couleurs disponibles
* Pouvoir tracer des formes géométriques et graphiques a l'aide d'équation mathématique (simple et complexe)

## Utilisatation partie 1 : Dashboard
Créer un dashboard pour visualiser :
* L'évolution du cour Kama-Ogrine (valeurs entrées manuelement)
* Faire des projections statistiques sur ces valeurs
* Afficher le nombre de Kama et Ogrine posséder, par serveur (valeurs entrées manuelement)
* Afficher courbe d'évolution du prix de certaine ressources (par serveur, valeurs entrées manuelement)
* Avoir un moyen de sauvegarder toutes les données

*Note : toute la partie mathématiques seras surment réaliser avec un langage de script comme Lua ou Python.*

## Utilisation partie 2 : Automatisation
Automatiser l'entrée des valeurs :
* Exécution sur la Raspberry qui feras office de serveur
* Récupérer les information sur les Kamas et Ogrines en ligne sur le site, avec soit une API (si existe) ou bien avec un bot Python + Open-CV.
* Récupérer les information sur le prix des ressources avec un bot (Python + Open-CV) directement en jeu (**Pas très légal**)

## Partie 3 : Bonus
Amélioration matériel :
* Ajouter un ventilateur à la Raspeberry
* Créer un boitier custom pour la Raspberry
* Utiliser la Raspberry comme bot pour un serveur Discord
