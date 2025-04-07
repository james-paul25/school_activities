#include <stdio.h>
#include <stdlib.h>


void addValue(int array[5]){
    int value;

    printf("Enter value to insert: ");
    scanf("%d", &value);

    if(array[5-1] != 0){
        printf("Array is already full! Cannot insert.\n");
        return 1;
    }
    for (int i = 5-1; i > 0; i--) {
        array[i] = array[i - 1];
    }
    array[0] = value;

    printf("======================================\n");

    printf("Array value after insertion\n");
    for (int i = 0; i < 5; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
    printf("======================================\n");


}
void application(){
    int array[5] = {78,98,100};
    printf("I N S E R T I O N\n");

    int choice =0;
    do{
        printf("======================================\n");
        printf("Array value before insertion\n");
        for (int i = 0; i < 5; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
        printf("======================================\n");

        printf("[1] Add value\n");
        printf("[2] Exit\n");
        scanf("%d", &choice);

        switch(choice){
        case 1:
            addValue(array);
            break;
        case 2:
            printf("Exiting program.\n");
            break;
        default:
            printf("Invalid choice.\n");
        }

    } while(choice != 2);

}

int main(){
    application();
    return 0;
}
