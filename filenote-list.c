#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <getopt.h>
#include <stdbool.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {
    int opt;
    char *path = ".";          // Default directory
    bool show_comments_only = false;
    char *comments_folder = "filenote_comments";  // Folder containing comments
    
    // Parse command line options
    while ((opt = getopt(argc, argv, "chd:")) != -1) {
        switch(opt) {
            case 'd': 
                path = optarg; 
                break;
            case 'c': 
                show_comments_only = true; 
                break;
            case 'h': 
                printf("FileNote List - List files and their comments\n\n");
                printf("Usage: %s [options] [directory]\n\n", argv[0]);
                printf("Options:\n");
                printf("  -c              Show only files with comments\n");
                printf("  -d <directory>  Specify directory to scan (default: current)\n");
                printf("  -h              Show this help\n");
                printf("\nExamples:\n");
                printf("  %s                    # List all files in current directory\n", argv[0]);
                printf("  %s -c                 # Show only files with comments\n", argv[0]);
                printf("  %s -d /path/to/dir    # Scan specific directory\n", argv[0]);
                printf("  %s -cd ~/projects     # Scan ~/projects, show only commented files\n", argv[0]);
                printf("\nOutput format:\n");
                printf("  filename - comment content\n");
                printf("  filename              (if no comment)\n");
                return 0;
        }
    }
    
    // Handle positional argument for directory
    if (optind < argc) {
        path = argv[optind];
    }
    
    DIR *d = opendir(path);
    if (!d) { 
        fprintf(stderr, "Error: Cannot open directory '%s'\n", path);
        perror("Details");
        return 1; 
    }
    
    struct dirent *entry;
    int file_count = 0;
    int commented_count = 0;
    
    printf("FileNote List - Scanning: %s\n", path);
    if (show_comments_only) {
        printf("Showing only files with comments:\n");
    }
    printf("─────────────────────────────────────────────────────\n");
    
    while ((entry = readdir(d)) != NULL) {
        // Ignore "." and ".."
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
            continue;
        
        // Check if it's a file and not a directory
        char fullpath[512];
        snprintf(fullpath, sizeof(fullpath), "%s/%s", path, entry->d_name);
        struct stat st;
        if (stat(fullpath, &st) != 0 || !S_ISREG(st.st_mode))
            continue;
        
        file_count++;
        
        // Path to associated comment file
        char comment_path[512];
        snprintf(comment_path, sizeof(comment_path), "%s/%s", comments_folder, entry->d_name);
        FILE *f = fopen(comment_path, "r");
        
        if (f) {
            // File has a comment
            commented_count++;
            printf("📄 %s - ", entry->d_name);
            char line[1024];
            while (fgets(line, sizeof(line), f) != NULL) {
                // Remove trailing newline for clean output
                size_t len = strlen(line);
                if (len > 0 && line[len-1] == '\n') {
                    line[len-1] = '\0';
                }
                printf("%s", line);
            }
            printf("\n");
            fclose(f);
        } else if (!show_comments_only) {
            // Display file only if -c option is not used
            printf("📄 %s\n", entry->d_name);
        }
    }
    
    closedir(d);
    
    // Summary
    printf("─────────────────────────────────────────────────────\n");
    if (show_comments_only) {
        printf("Found %d files with comments\n", commented_count);
    } else {
        printf("Found %d files total, %d with comments\n", file_count, commented_count);
    }
    
    return 0;
}