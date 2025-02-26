#include <stdio.h>
#include <stdlib.h>
#define MAX_RECORD 10

struct Record{
    int id;
    char name[50];
    int age;
    char course[50];
    float dsa;
    float oop;
    float fundamentals;
};

int recordSize = 0;
struct Record records[MAX_RECORD] = {0};

void addStudentRecord(int *size){

    int numToAdd;

    printf("Enter the number of student to add: ");
    scanf("%d", &numToAdd);

    if (*size + numToAdd > MAX_RECORD) {
        printf("===============================================================================\n");
        printf("Not enough space! You can only add %d more students.\n", MAX_RECORD - *size);
        printf("===============================================================================\n");
        return;
    }

    for (int i = 0; i < numToAdd; i++) {
        printf("===============================================================================\n");
        printf("- Adding Student %d -\n", *size + 1);
        records[*size].id = *size + 1;

        getchar();

        printf("Enter Student Name: ");
        scanf(" %[^\n]", records[*size].name);
        printf("Enter Student Age: ");
        scanf("%d", &records[*size].age);

        getchar();
        strcpy(records[*size].course, "BSCS");

        printf("Enter grade for Data Structure and Algorithms: ");
        scanf("%f", &records[*size].dsa);
        printf("Enter grade for Object Oriented Programming: ");
        scanf("%f", &records[*size].oop);
        printf("Enter grade for Fundamentals of Programming: ");
        scanf("%f", &records[*size].fundamentals);
        
        (*size)++;
        printf("===============================================================================\n");
        printf("Student record added successfully!\n");
        printf("===============================================================================\n\n");
    }
}


void displayStudents(int size){

    if(size == 0){
        printf("===============================================================================\n");
        printf("No student records found.\n");
        printf("===============================================================================\n\n");
        return;
    }

    printf("- Display students -\n");

    printf("===============================================================================\n");
    for(int i=0;i<size;i++){
        char *statusDSA = (records[i].dsa <= 3.0 && records[i].dsa >= 1.0) ? "PASSED" : "FAILED";
        char *statusOOP = (records[i].oop <= 3.0 && records[i].oop >= 1.0) ? "PASSED" : "FAILED";
        char *statusFundamentals = (records[i].fundamentals <= 3.0 && records[i].fundamentals >= 1.0) ? "PASSED" : "FAILED";

        printf("ID: %d\n", records[i].id);
        printf("Name: %s\n", records[i].name);
        printf("Age: %d\n", records[i].age);
        printf("Course: %s\n", records[i].course);
        printf("- - Grades - -\n");
        printf("Data Structure and Algorithms: %.1f\tStatus: %s\n", records[i].dsa, statusDSA);
        printf("Object Oriented Programming:   %.1f\tStatus: %s\n", records[i].oop, statusOOP);
        printf("Fundamentals of Programming:   %.1f\tStatus: %s\n", records[i].fundamentals, statusFundamentals);
        printf("===============================================================================\n");
        printf("\n");
    }
}

void searchStudent(size){
    char searchName[50];
    int found = 0;

    printf("- Search -\n");
    printf("> Enter students name to search: ");
    scanf(" %[^\n]", searchName);
    printf("\n");

    for(int i=0; i<size;i++){
        char *statusDSA = (records[i].dsa <= 3.0 && records[i].dsa >= 1.0) ? "PASSED" : "FAILED";
        char *statusOOP = (records[i].oop <= 3.0 && records[i].oop >= 1.0) ? "PASSED" : "FAILED";
        char *statusFundamentals = (records[i].fundamentals <= 3.0 && records[i].fundamentals >= 1.0) ? "PASSED" : "FAILED";

        if(strcmp(records[i].name, searchName) == 0){
            found = 1;
            printf("===============================================================================\n");
            printf("Student found.\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("Age: %d\n", records[i].age);
            printf("Course: %s\n", records[i].course);
            printf("- - Grades - -\n");
            printf("Data Structure and Algorithms: %.1f\tStatus: %s\n", records[i].dsa, statusDSA);
            printf("Object Oriented Programming:   %.1f\tStatus: %s\n", records[i].oop, statusOOP);
            printf("Fundamentals of Programming:   %.1f\tStatus: %s\n", records[i].fundamentals, statusFundamentals);
            printf("===============================================================================\n");
            printf("\n");
            break;
        }
    }

    if(found == 0){
        printf("===============================================================================\n");
        printf("No information for the student.\n");
        printf("===============================================================================\n\n");
        return;
    }
}

void deleteStudent(int *size){
    char deleteName[50];
    int index = -1;

    printf("- Delete -\n");
    printf("> Enter student name to delete: ");
    scanf(" %[^\n]", deleteName);

    for(int i=0; i< *size; i++){
        if(strcmp(records[i].name, deleteName) == 0){
            index = i;
            break;
        }
    }

    if(index == -1){
        printf("===============================================================================\n");
        printf("Student with the name of %s not found.\n\n", deleteName);
        printf("===============================================================================\n");
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        records[i] = records[i + 1];
    }

    (*size)--;
    printf("===============================================================================\n");
    printf("Student with the name of %s deleted successfully.\n\n", deleteName);
    printf("===============================================================================\n");

}

void program(){
    int choice = 0;
    struct Record record;
    int size = 0;

    do{
        printf("- Menu -\n");
        printf("[1] Add student records\n");
        printf("[2] Show student records\n");
        printf("[3] Search student record\n");
        printf("[4] Delete student record\n");
        printf("[5] Exit program\n");
        printf("> Enter choice(1-5): ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:
                addStudentRecord(&size);
                break;
            case 2:
                displayStudents(size);
                break;
            case 3:
                searchStudent(size);
                break;
            case 4:
                deleteStudent(&size);
                break;
            case 5:
                printf("At your service sir D.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Select (1-5) choices only.\n\n");
        }

    } while (choice != 5);
}

int main(){

    printf("- - - Record of BSCS Students- - -\n\n");

    program();

    return 0;
}
