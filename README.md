Bienvenue dans la documentation du Projet Dialecte Conversion du groupe 1
----
Télécharger le projet
```
git clone https://github.com/Kagarie/Projet_Dilacte_Conversion.git
```

Pour installer tous les composants nécessaires au bon fonctionnement de ce projet

```
cd Projet_Dilacte_Conversion/
[sudo] pip install [--user] -r Projet_Dilacte_Conversion/docs/requirements.txt
```

Puis,


```
$mkdir build ; cd build/
$cmake ../Projet_Dilacte_Conversion -DCMAKE_INSTALL_PREFIX=/tmp
```
ou
```
$cmake ../Projet_Dilacte_Conversion -DCMAKE_INSTALL_PREFIX=~PATH

```

```
($make test)

$make docs
```

Vous génèrerez ainsi la documentation du projet
 
Installer le projet
```
($make install)
```

La documentation se situe dans le dossier build/docs/html

