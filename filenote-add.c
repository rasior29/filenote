#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>     
#include <dirent.h>    
#include <sys/stat.h> 
#include <string.h> 
#include <unistd.h>

int main(int argc, char *argv[]) {
    bool verbose = false;
    char *file = NULL;
    char *comment = NULL;
    
    // Define long options
    static struct option long_options[] = {
        {"help",    no_argument,       NULL, 'h'},
        {"verbose", no_argument,       NULL, 'v'},
        {"file",    required_argument, NULL, 'f'},
        {0, 0, 0, 0}
    };
    
    int opt;
    while ((opt = getopt_long(argc, argv, "hvf:", long_options, NULL)) != -1) {
        switch (opt) {
            case 'h':
                printf("FileNote Add - Add comments to files\n\n");
                printf("Usage: %s [options] <file> <comment>\n", argv[0]);
                printf("       %s -f <file> <comment>\n\n", argv[0]);
                printf("Available options:\n");
                printf("  -h, --help                 Show this help\n");
                printf("  -v, --verbose              Enable verbose mode\n");
                printf("  -f, --file <file>          Specify file (alternative syntax)\n");
                printf("\nExamples:\n");
                printf("  %s myfile.txt \"This is my comment\"\n", argv[0]);
                printf("  %s -v script.py \"Python script for data processing\"\n", argv[0]);
                printf("  %s -f config.conf \"Main configuration file\"\n", argv[0]);
                exit(0);
                break;
            case 'v':
                verbose = true;
                break;
            case 'f':
                file = optarg;
                // Check if comment argument exists
                if (optind < argc) {
                    comment = argv[optind];
                    optind++;
                } else {
                    fprintf(stderr, "Error: Comment required after filename\n");
                    return 1;
                }
                break;
            default:
                fprintf(stderr, "Unknown option. Use -h or --help for help.\n");
                return 1;
        }
    }
    
    // Handle direct arguments (file comment) without -f flag
    if (file == NULL && optind < argc) {
        file = argv[optind++];
        if (optind < argc) {
            comment = argv[optind++];
        } else {
            fprintf(stderr, "Error: Both file and comment arguments are required\n");
            fprintf(stderr, "Usage: %s <file> <comment>\n", argv[0]);
            return 1;
        }
    }
    
    // Check if we have both file and comment
    if (file == NULL || comment == NULL) {
        fprintf(stderr, "Error: Both file and comment arguments are required\n");
        fprintf(stderr, "Use -h for help\n");
        return 1;
    }
    
    // Check if file exists
    if (access(file, F_OK) == -1) {
        printf("Error: File '%s' does not exist\n", file);
        return 1;
    }
    
    // Create comment storage
    char path[512];
    char folder[] = "filenote_comments";
    DIR *dir = opendir(folder);
    
    if (dir == NULL) {
        // Create directory if it doesn't exist
        if (mkdir(folder, 0755) != 0) {
            perror("Error creating comments directory");
            return 1;
        }
        if (verbose) {
            printf("Created comments directory: %s/\n", folder);
        }
    } else {
        closedir(dir);
    }
    
    // Create comment file path
    snprintf(path, sizeof(path), "%s/%s", folder, file);
    
    // Write comment to file
    FILE *fp = fopen(path, "w");
    if (fp == NULL) {
        perror("Error creating comment file");
        return 1;
    }
    
    fprintf(fp, "%s\n", comment);
    fclose(fp);
    
    // Success message
    if (verbose) {
        printf("FileNote: Comment added successfully\n");
        printf("  File: %s\n", file);
        printf("  Comment: %s\n", comment);
        printf("  Stored in: %s\n", path);
    } else {
        printf("Comment added for '%s'\n", file);
    }
    
    return 0;
}