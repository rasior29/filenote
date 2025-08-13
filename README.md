# FileNote - File Comment Management Tool

A simple command-line tool to add and manage file comments on Linux/Unix systems.

## Description
FileNote lets you attach descriptive comments to your files without altering the originals.  
Main commands:  
- **`filenote-add`**: Add a comment to a file  
- **`filenote-list`**: List files with their comments  

## Installation
```bash
# Clone and install
git clone https://github.com/your-username/filenote.git
cd filenote
make install
Or compile manually:

bash
Copier
Modifier
gcc filenote-add.c -o filenote-add
gcc filenote-list.c -o filenote-list
sudo cp filenote-add filenote-list /usr/local/bin/
Usage
Add a comment:

bash
Copier
Modifier
filenote-add myfile.txt "File description"
List files:

bash
Copier
Modifier
filenote-list              # All files
filenote-list -c           # Only commented files
filenote-list -d /path     # Another directory
Key options:

-c: Only show commented files

-d <dir>: Specify directory

-v: Verbose mode

Internal Structure
Comments are stored in the filenote_comments/ directory as plain text files.

License
MIT License – see the LICENSE file.

Author
Created by rasior29.
