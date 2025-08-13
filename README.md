# FileNote

Un outil en ligne de commande simple pour gérer les commentaires de fichiers sur les systèmes Linux/Unix.

FileNote vous permet d'attacher des commentaires descriptifs à vos fichiers sans modifier les originaux.

## Installation

```bash
git clone https://github.com/rasior29/filenote.git
cd filenote
make install
```

Ou compilation manuelle :
```bash
gcc filenote-add.c -o filenote-add
gcc filenote-list.c -o filenote-list
sudo cp filenote-add filenote-list /usr/local/bin/
```

## Utilisation

### Ajouter un commentaire
```bash
filenote-add myfile.txt "Description du fichier"
```

### Lister les fichiers
```bash
filenote-list              # Tous les fichiers
filenote-list -c           # Seulement les fichiers commentés
filenote-list -d /chemin   # Répertoire spécifique
```

## Options principales

- `-c` : Afficher uniquement les fichiers commentés
- `-d <dir>` : Spécifier un répertoire
- `-v` : Mode verbose

## Structure interne

Les commentaires sont stockés dans le répertoire `filenote_comments/` sous forme de fichiers texte.

## Licence

MIT License

## Auteur

Créé par rasior29
