<<<<<<< HEAD
Bienvenue dans la documentation du Projet Dialecte Conversion du groupe 1
----

Lorsque le téléchargement est terminé, effectuez cette ligne pour installer tous les composants nécessaires au bon fonctionnement de ce projet

```
[sudo] pip install [--user] -r Projet_Dilacte_Conversion/docs/requirements.txt
```

Placez vous au même endroit que le read me et le dossier du projet et effectuez ces lignes de commande:


```
$mkdir build
$cd build
$cmake ../Projet_Dilacte_Conversion -DCMAKE_INSTALL_PREFIX=/tmp
```
ou
```
$cmake ../Projet_Dilacte_Conversion -DCMAKE_INSTALL_PREFIX=~/.local
```
Un dossier yaml devrait s'être deplacé dans le dossier de build

```
$make
```

```
$make test

$make docs
```



Vous génèrerez ainsi la documentation du projet
 
```
$make install
```

La documentation se situe dans le dossier build/docs/html

Pour accéder au convertisseur, deplacez vous dans src/code:

```
cd src/code
```
=======
#Projet_Dilacte_Conversion

Pour le moment il n'y a qu'un dossier pour le code 
On fera un point pour la répartition des taches et je ferai des branch pour chaque partie

Tout évoluera au cour du projet même le README ce n'est qu'une première ébauche
On fera un point sur l'utiliation du README aussi
>>>>>>> master
