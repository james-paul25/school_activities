#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_PATH "C:\\Users\\ricar\\Documents\\SirD\\"

int checkFile(const char *basePath){
    char checkingFile[255];
    strcpy(checkingFile, basePath);

    FILE *file = fopen(checkingFile, "r");
    if(file){
        fclose(file);
        return 1;
    }

    return -1;
}

void writingTextToFile(const char *basePath, char *mode){
    char filePath[100];
    strcpy(filePath, basePath);

    FILE *file = fopen(filePath, mode);
    if(file){
        printf("\nWrite a text for your file: ");
        char text[255];
        getchar();
        fgets(text, sizeof(text), stdin);

        fprintf(file, "%s", text);
        fclose(file);
        printf("File written to text\n");
    } else {
        printf("\nError writing to a file.\n");
    }
}

void createFile(const char *basePath){
    char filePath[255];
    strcpy(filePath, basePath);

    char fileName[100];
    printf("Enter file name to create: ");
    scanf("%s", fileName);

    strcat(filePath, fileName);

    if(checkFile(filePath) == 1){
        printf("\nFile already exists.");
        return;
    }

    FILE *file = fopen(filePath, "w");
    if(file){
        printf("\nFile created successfully");
        fclose(file);
    } else {
        printf("Error: Unable to create the file");
    }
}

void writeFile(const char *basePath) {
    char filePath[255];
    strcpy(filePath, basePath);

    char fileName[100];
    printf("\nEnter the file name you want to write to: ");
    scanf("%s", fileName);

    strcat(filePath, fileName);

    if (checkFile(filePath) == -1) {
        printf("\nFile not found.\n");
        return;
    }

    FILE *file = fopen(filePath, "r");
    char firstChar = fgetc(file);
    fclose(file);

    if (firstChar != EOF) {
        char choice;
        printf("\nThe file already contains text. Do you want to (O)Overwrite or (A)Append? ");
        scanf(" %c", &choice);

        if (choice == 'O' || choice == 'o') {
            writingTextToFile(filePath, "w");
        } else if (choice == 'A' || choice == 'a') {
            writingTextToFile(filePath, "a");
        } else {
            printf("\nInvalid choice. No changes made.\n");
        }
    } else {
        writingTextToFile(filePath, "w");
    }
}

int main(){
    int key;
    char filePath[255] = FILE_PATH;

    printf("- - - FILE HANDLING - - -");

    do{
        printf("\n\n[1] Create File\n[2] Write to a file\n[3] Exit program \n> ");
        scanf("%d", &key);

        switch(key){
            case 1:
                createFile(filePath);
                break;
            case 2:
                writeFile(filePath);
                break;
            case 3:
                printf("At your service sir.");
                exit(0);
                break;
            default:
                printf("Please choose valid choice.");
        }

    } while(key != 3);

    return 0;
}
