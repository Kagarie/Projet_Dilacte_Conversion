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


