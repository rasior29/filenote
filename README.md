FileNote - File Comment Management Tool

A simple and intuitive command-line tool for adding and managing comments for files in Linux/Unix systems.

Description

FileNote helps you keep track of your files by allowing you to add descriptive comments to them. It consists of two main commands:

filenote-add: Add comments to any file

filenote-list: List files and display their comments

Comments are stored separately from your original files, so they never modify your actual data.

Features
FileNote Add

Add descriptive comments to any file

Multiple syntax options for ease of use

Verbose mode for detailed feedback

Automatic comment storage management

File existence validation

FileNote List

List all files in a directory with their comments

Filter to show only commented files

Scan different directories

Summary statistics

Clean, readable output format

Installation
Quick Install (Recommended)
# Download and compile
git clone https://github.com/your-username/filenote.git
cd filenote
make install

Manual Compilation

Compile the programs:

gcc filenote-add.c -o filenote-add
gcc filenote-list.c -o filenote-list


Make them executable:

chmod +x filenote-add filenote-list


Optional: Install system-wide:

sudo cp filenote-add filenote-list /usr/local/bin/

Using .deb Package (Ubuntu/Debian)
wget https://github.com/your-username/filenote/releases/download/v1.0/filenote_1.0_amd64.deb
sudo dpkg -i filenote_1.0_amd64.deb

Usage
Adding Comments

Simple syntax:

filenote-add myfile.txt "This file contains configuration data"
filenote-add script.py "Python script for data analysis"


Alternative syntax with -f flag:

filenote-add -f myfile.txt "This file contains configuration data"


With verbose output:

filenote-add -v report.pdf "Annual financial report for 2024"


Available options:

-h, --help: Show help message

-v, --verbose: Enable detailed output

-f, --file: Alternative syntax for specifying file

Listing Files and Comments

Basic usage:

filenote-list                    # List all files in current directory
filenote-list /path/to/folder    # List files in specific directory


Show only commented files:

filenote-list -c
filenote-list -c /path/to/folder


Specify directory explicitly:

filenote-list -d /home/user/projects
filenote-list -cd /home/user/projects    # Combined flags


Available options:

-c: Show only files that have comments

-d <directory>: Specify directory to scan

-h: Show help message

Examples
Basic Workflow
# Create some files
echo "Hello World" > greeting.txt
echo "#!/bin/bash\necho 'Hi'" > hello.sh

# Add comments
filenote-add greeting.txt "Simple greeting text file"
filenote-add hello.sh "Bash script that prints a greeting"

# List all files
filenote-list
# Output:
# FileNote List - Scanning: .
# ----------------------------------------------------------
# greeting.txt - Simple greeting text file
# hello.sh - Bash script that prints a greeting
# ----------------------------------------------------------
# Found 2 files total, 2 with comments

# Show only commented files
filenote-list -c

Advanced Usage
# Add comments with verbose mode
filenote-add -v config.conf "Main application configuration"
# Output:
# FileNote: Comment added successfully
#   File: config.conf
#   Comment: Main application configuration
#   Stored in: filenote_comments/config.conf

# Scan a specific directory for commented files
filenote-list -c ~/Documents/projects

# Add comment to file in different directory
filenote-add /path/to/important/file.txt "Critical system file"

How It Works
Storage System

Comments are stored in a filenote_comments/ directory

Each comment is saved as a separate file with the same name as the original

Original files are never modified

Comments are plain text files

Directory Structure
your-project/
├── file1.txt
├── script.py
├── config.conf
└── filenote_comments/
    ├── file1.txt          # Contains: "Documentation file"
    ├── script.py          # Contains: "Main processing script"
    └── config.conf        # Contains: "Application settings"

File Management

Adding: Creates comment file in filenote_comments/

Listing: Searches for matching comment files

Updating: Overwrites existing comment files

No deletion: Tool focuses on adding and viewing (manual deletion from filenote_comments/ folder)

Building from Source
Prerequisites

GCC compiler

GNU Make (optional, for using Makefile)

POSIX-compliant system (Linux, Unix, macOS)

Build Commands
# Using Makefile (recommended)
make all            # Compile both programs
make install        # Compile and install system-wide
make clean          # Remove compiled files

# Manual compilation
gcc -Wall -Wextra -std=c99 -o filenote-add filenote-add.c
gcc -Wall -Wextra -std=c99 -o filenote-list filenote-list.c

Tips and Best Practices

Organize your comments: Use consistent, descriptive comments

Backup comments: The filenote_comments/ folder contains all your comments

Version control: Add filenote_comments/ to your git repository to track comment changes

Batch operations: Use shell loops for multiple files:

for file in *.py; do
    filenote-add "$file" "Python source file"
done

Troubleshooting
Common Issues

"File does not exist" error:

# Make sure the file exists before adding a comment
ls -la myfile.txt
filenote-add myfile.txt "My comment"


Permission denied:

# Ensure you have write permissions in the current directory
ls -ld .
chmod 755 .  # if needed


No comments shown:

Check if filenote_comments/ directory exists

Verify comment files are in the correct location

Use filenote-list -v for verbose output (if implemented)

Contributing

We welcome contributions! Here's how to get started:

Fork the repository

Create a feature branch: git checkout -b feature-name

Make your changes and test them

Commit your changes: git commit -am 'Add feature'

Push to the branch: git push origin feature-name

Submit a pull request

Development Ideas

 Comment editing functionality

 Comment deletion command

 Search within comments

 Export comments to different formats

 Integration with popular editors

License

This project is licensed under the MIT License - see the LICENSE file for details.

Author

Created by [Your Name]

Changelog
v1.0.0 (Current)

Initial release

Add comments to files

List files with comments

Filter commented files only

Verbose mode support

Multiple command syntax options

Cross-platform compatibility
