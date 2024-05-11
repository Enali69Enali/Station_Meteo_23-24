# Station_Meteo_23-24
## Description du projet
Pour le cours de projet d'électronique lors de la 4e année du cycle d'ingénieur en alternance, celui ci réalise une girouette pour la station météo d'une ruche connectée. 
Une girouette est un objet de mesure pour nous donner la direction du vent. Ce projet reprend le projet Github 2022-2023 : [Station_Meteo_2022-2023](https://github.com/Solene49000/Station_Meteo_2022-2023). 
Dans ce projet, leur systeme de girouette n'était pas fonctionnelle, du à des differences de tensions trop faible par rapport au différente position de la fleche de la girouette. Nous proposons donc une solution alternative à ce probleme avec notre projet. 

Ce projet de station météo comporte plusieurs composants tels que:
- La quantité de pluie tombée 
- La vitesse du vent 
- La luminosité
- La température 
- L'humidité
Mais nous nous concentrons surtout sur la direction du vent avec la girouette. 

Pour voir la présentation du projet en cours, cliquez [ici](https://github.com/Enali69Enali/Station_Meteo_23-24/blob/master/rapport_de_s%C3%A9ance/Premier%20pr%C3%A9sentation%20%C3%A9lectronique.pdf).

## Fonctionnement
La première question à laquelle nous avons du repondre est : **Comment connaitre la direction de vent sans utilisé la premiere méthode ?** 
Le difference de tension est une bonne méthode mais devait etre plus importante pour faire fonctionner le projet. 
Nous sommes donc partis sur une idée de CODE GRAY (1 bit se change à la fois) avec 4 entrée. Pour avoir une seule sortie nous avons utilisé un réseau R2R.
### Le projet physique
Pour simuler le CODE GRAY, nous avons pensé à une idée de LED émettrices et photo-transitors récepteurs séparer par un tourniquet fait en impression 3D. Quand il y aura le passage d'un trou (pas de matiere), les photo-transitor recevront la lumière infrarouge. Sinon rien ne sera perçu.
Voici les principales impressions 3D nécessaire pour le projet :
* [Boite maintenant le PCB](https://github.com/Enali69Enali/Station_Meteo_23-24/blob/master/modelisation_3D/boite.stl) (Attention dans le fichier .stl il manque un trou pour faire passer les câbles que nous avons rajoutés en en faisant un dans le fond de la boite avec un fer à souder. Pour les autres modifications regarder [ici](#petits-défaut-à-améliorer-pour-le-bon-fonctionnement-du-projet))
* [Couvercle](https://github.com/Enali69Enali/Station_Meteo_23-24/blob/master/modelisation_3D/cylindre%20led-couvercle.stl) (Attention le PCB a un sens sinon celui ci ne passera pas avec le couvercle)
* [Réajusteur pour le roulement](https://github.com/Enali69Enali/Station_Meteo_23-24/blob/master/modelisation_3D/calle%20roulement.stl)
* Fleche de la girouette nous avait été déja fournis

Pour le montage, il suffit de collé le réajusteur pour le roulement sur la tige de la boite, puis de placé un roulement adapté pour emboité le couvecle et la boite. Les impressions sont fait pour des roulements aux dimensions de : diamètre extérieur 22mm, diamètre intérieur 8mm et diamètre de hauteur 7mm.

En plus a été designé un cache pour séparer LEDs/ photo-transistors les uns des autres (voir [le rapport du jour 13/03 de PELLETIER](https://github.com/Enali69Enali/Station_Meteo_23-24/blob/master/rapport_de_s%C3%A9ance/Rapport13_03_2024PELLETIER.pdf)). Ceux ci n'ont pas encore été testé.

### Le projet électronique
#### Hardware
Le [PCB](https://github.com/Enali69Enali/Station_Meteo_23-24/blob/master/BoardsEAGLE/R2R_v2.1.brd) contenant le réseau R2R doit être imprimés (si vous ne l'avez pas déjà) et ajouté avec chaque composant.
Pour les LEDs et photo-transistors il faut que ceux ci soit soudé au dos de la carte avec la tete reposant sur le plastique du PCB pour être à la même hauteur tous, pour le passage dans le tourniquet soit synchronisé. 
Les LED et phototransistors travaillent sur la même longueur d'onde, cad 940 nm (infrarouge). Les phototransistors sont utilisés en emmeteur commun avec un inverseur MOS à sa sortie afin d'avoir réellement 0 ou 3.3V et pas de valeurs entre pour le bon fonctionnement du réseau R2R. L'angle de réception des phototransistors a été choisi le plus petit possible (et disponible), cad 28º, afin de limiter le plus possible les parasites des autre leds.

#### Software
Un fois téléversé, le programme rentre en light sleep et se réveille toute les 15 secondes (ou si reception d'une goutte de pluie), ce
qui permet d'obtenir la position de la girouette
Il y a 16 position differentes, Ouest etant la plus petite, tous les phototransistors recevant tous de la lumière et Nord etant la plus grande, tous les transistors etant cachés.
Actuellement, le valeurs sont complètement à refaire: la courbe n'étant pas linéaire et les valeurs ayant été déterminées avec le PCB de test, les écarts entre les valeurs sont trop grand et les résultats étaient au final mieux que prévu.
Le code de la girouette reste extrêmement simple, etant juste un else-if

## Installation
Préparer le modèle de la girouette physique avec le PCB à l'intérieur.
Il faut brancher le cable micro USB à l'ordinateur pour pouvoir téléverser le code mais voir aussi les informations envoyées par la girouette
Ensuite il faut alimenter la girouette en 3.3V: le fil rouge doit être branché au 3.3V et le fil noir au GND.
Pour vérifier que le montage fonctionne bien, environs 170 mA sont "consommés" par notre montage et sont donc visible sur le générateur
de tension

## Utilisation
Nous avons decidé pour nos tests que le N serait pointé à la position 0 0 0 0 (tous les phototransistors ne recoivent pas de rayonnement des LEDs).
Lors du lancement du programme, celui ci retournera toutes les 15 secondes la direction de la girouette. Le projet n'a pas encore été testé en rajoutant l'anémomètre.

## Petits défaut à améliorer pour le bon fonctionnement du projet
- Les calles du PCB dans la boite ne sont pas exactement aligné, il faut la bloqué avec du scotch en exemple et la surélever pour que les LEDs/photo-transistors soient au niveau des trous pour laisser le passage des rayons. Conseil : si vous voulez résoudre ce soucis avant l'impression de la boite, vous devez surélever le fond de la boite de 2-3 mm;
- Les valeurs theoriques recues par la carte sont différentes de la réalité, il faut donc réajuster les valeurs pour la bonne gestion de la direction de la girouette;
- Les séparateurs peuvent être imprimés si ils y a trop d'interférence.

## Auteurs et remerciments
Projet réalisé par DUEE-MOREAU Arwen et PELLETIER Ilane en classe ELSE4 cursus Polytech FISA 4 année sur le semestre 7 et 8 avec l'aide du professeur PETER Christian.

