# FileNote

A simple command-line tool for managing file comments on Linux/Unix systems.

FileNote lets you attach descriptive comments to your files without altering the originals.

## Installation

```bash
git clone https://github.com/rasior29/filenote.git
cd filenote
make install
```

Or compile manually:
```bash
gcc filenote-add.c -o filenote-add
gcc filenote-list.c -o filenote-list
sudo cp filenote-add filenote-list /usr/local/bin/
```

## Usage

### Add a comment
```bash
filenote-add myfile.txt "File description"
```

### List files
```bash
filenote-list              # All files
filenote-list -c           # Only commented files
filenote-list -d /path     # Specific directory
```

## Key Options

- `-c`: Only show commented files
- `-d <dir>`: Specify directory
- `-v`: Verbose mode

## Internal Structure

Comments are stored in the `filenote_comments/` directory as plain text files.

## License

MIT License

## Author

Created by rasior29
