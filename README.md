Bienvenue dans la documentation du Projet Dialecte Conversion du groupe 1
----

Lorsque le téléchargement est terminé, effectuez cette ligne pour installer tous les composants nécessaires au bon fonctionnement de ce projet

```
[sudo] pip install [--user] -r Projet_Dilacte_Conversion/docs/requirements.txt
```

Puis, effectuez ces lignes de commande au même endroit où se trouve ce READ.me


```
$mkdir build
$cd build
$cmake ../Projet_Dilacte_Conversion -DCMAKE_INSTALL_PREFIX=/tmp
```
ou
```
$cmake ../Projet_Dilacte_Conversion -DCMAKE_INSTALL_PREFIX=~/.local
```

```
($make test)

$make docs
```

Vous génèrerez ainsi la documentation du projet
 
```
($make install)
```

La documentation se situe dans le dossier build/docs/html


=======
# Projet_Dilacte_Conversion

Pour le moment il n'y a qu'un dossier pour le code 
On fera un point pour la répartition des taches et je ferai des branches pour chaque parties

Tout évoluera au cour du projet même le README ce n'est qu'une première ébauche
On fera un point sur l'utiliation du README aussi
