#include <stdio.h>
#include <stdlib.h>

struct Record{
    int id;
    char name[50];
    int age;
    float gwa;
    char course[50];
};

struct Record records[10] = {
    {1, "Jessa Ugpo", 20, 2.1, "Computer Science"},
    {2, "Angel June Terec", 20, 1.9, "Computer Science"},
    {3, "Cherry Mae Inguito", 21, 1.8, "Computer Science"},
    {4, "James Walter Dacaldacal", 20, 3.0, "Civil Engineering"},
    {5, "Jaylloyd Bayud", 22, 3.5, "Civil Engineering"},
    {6, "Rolan Galvadores", 20, 1.7, "Drafting Technology"},
    {7, "Gian Pilongo", 20, 3.0, "Electrical Engineering"},
    {8, "Niel Angelo Rico Doyugan", 20, 2.0, "Computer Science"},
    {9, "Kenneth Tangcawan", 20, 1.3, "Drafting Technology"},
    {10, "Jonn Hotz Silva", 20, 2.0, "Mechanical Technology"}
};

void sortByGwa(int size){
    struct Record temp;

    for(int i=0; i<size-1;i++){
        for(int j=0; j<size-i-1;j++){
            if(records[j].gwa > records[j+1].gwa){
                temp = records[j];
                records[j] = records[j+1];
                records[j+1] = temp;
            }
        }
    }

    printf("- Sorted records by their GWA -\n");
}


void displayStudents(int size){
    printf("- Display students -\n");

    for(int i=0;i<size;i++){
        char *status = (records[i].gwa <= 3.0 && records[i].gwa >= 1.0) ? "PASSED" : "FAILED";

        printf("ID: %d\n", records[i].id);
        printf("Name: %s\n", records[i].name);
        printf("Age: %d\n", records[i].age);
        printf("GWA: %.1f\tStatus: %s\n", records[i].gwa, status);
        printf("Course: %s\n", records[i].course);
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
        char *status = (records[i].gwa <= 3.0 && records[i].gwa >= 1.0) ? "PASSED" : "FAILED";
        if(strcmp(records[i].name, searchName) == 0){
            found = 1;
            printf("Student found.\n");
            printf("ID: %d\n", records[i].id);
            printf("Name: %s\n", records[i].name);
            printf("GWA: %d\n", records[i].age);
            printf("Grade: %.1f\tStatus: %s\n", records[i].gwa,status);
            printf("Course: %s\n", records[i].course);
            printf("\n");
            break;
        }
    }

    if(found == 0){
        printf("No information for the student.\n\n");
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
        printf("Student with the name of %s not found.\n\n", deleteName);
        return;
    }

    for (int i = index; i < *size - 1; i++) {
        records[i] = records[i + 1];
    }

    (*size)--;

    printf("Student with the name of %s deleted successfully.\n\n", deleteName);

}

void displayStudentChoice(int size){
    int choice;

    printf("- Display choice -\n");
    printf("[1] Sorted By GWA\n");
    printf("[2] Display By ID\n");
    printf("> Enter choice: ");
    scanf("%d", &choice);

    switch(choice){
        case 1:
            sortByGwa(size);
            displayStudents(size);
            break;
        case 2:
            displayStudents(size);
            break;
        default:
            printf("Invalid choice. Select (1-2) choices only\n\n");

    }

}

void program(){
    int choice = 0;
    struct Record record;
    int size = sizeof(records)/sizeof(records[0]);

    do{
        printf("- Menu -\n");
        printf("[1] Show students\n");
        printf("[2] Search student\n");
        printf("[3] Delete student\n");
        printf("[4] Exit program\n");
        printf("> Enter choice(1-4): ");
        scanf("%d", &choice);
        printf("\n");

        switch(choice){
            case 1:
                displayStudentChoice(size);
                break;
            case 2:
                searchStudent(size);
                break;
            case 3:
                deleteStudent(&size);
                break;
            case 4:
                printf("At your service sir D.\n");
                exit(0);
                break;
            default:
                printf("Invalid choice. Select (1-4) choices only.\n\n");
        }

    } while (choice != 4);
}

int main(){

    printf("- - - Students Record - - -\n\n");

    program();

    return 0;
}
