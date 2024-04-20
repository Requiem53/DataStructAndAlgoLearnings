#include <stdio.h>
#include <stdlib.h>

void enter(int*, int*);
void display();
void searchIndex(int*, int);
void printOdd(int*, int);
void printEven(int*, int);
void matchValue(int*, int);
void printArray(int*, int* );

int main(void) {
    int size = 10, choice;
    int* numptr = (int*) calloc(size,sizeof(int));
    enter(numptr, &size);
    do{
        display();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                searchIndex(numptr, size);
                printf("\n");
                break;
            case 2:
                matchValue(numptr, size);
                printf("\n");
                break;
            case 3:
                printEven(numptr, size);
                printf("\n");
                break;
            case 4:
                printOdd(numptr, size);
                printf("\n");
                break;
        }
    }while(choice != 5);
    printf("\n");
    printf("Program terminated.");
    return 0;
}

void enter(int* numptr, int* size){
    int temp;
    for(int i = 0;i < *size;i++){
        printf("Numptr Address: %d",numptr);
        printf("\nSize: %d\n", *size);
        printf("Enter integer #%d: ", i+1);
        scanf("%d", &temp);
        if(temp < 1){
            return;
        }else{
            printf("Index: %d\n", i);
            *size = (*size) + 1;
            numptr[i] = temp;
            printArray(numptr,size);
        }
    }
    printf("\n");
}

void printArray(int* numptr, int* size){
    printf("\n Array: ");
    for(int i = 0; i < *size; i++){
        printf("%d ", numptr[i]);
    }
    printf("\n");
}

void display(){
    printf("Choose an option:\n");
    printf("1. Search for index value\n");
    printf("2. Search for match value indexes\n");
    printf("3. Print all even numbers\n");
    printf("4. Print all odd numbers\n");
    printf("5. Exit\n");
    printf("\n");
}

void searchIndex(int* numptr, int size){
    printf("Numptr Address: %d",numptr);
    int index;
    printArray(numptr, &size);
    printf("\nEnter index to search: ");
    scanf("%d", &index);
    printf("Value at index %d: %d\n", index, numptr[index]);
}

void printOdd(int* numptr, int size){
    printf("\nOdd numbers in the array:");
    for(int i = 0;i < size-1;i++){
        if(numptr[i] % 2 != 0){
            printf(" %d", numptr[i]);
        }
    }
    printf("\n");
}

void printEven(int* numptr, int size){
    printf("\nEven numbers in the array:");
    for(int i = 0;i < size-1;i++){
        if(numptr[i] != 0){
            if(numptr[i] % 2 == 0){
                printf(" %d", numptr[i]);
            }
        }
    }
    printf("\n");
}

void matchValue(int* numptr, int size){
    int val, count = 0;
    printf("\nEnter value to search: ");
    scanf("%d", &val);
    for(int i = 0;i<size;i++){
        if(numptr[i] == val){
            count++;
        }
    }

    if(count > 1){
        printf("Value %d found in index(es):", val);
    }else{
        printf("Value %d found in index:", val);
    }

    for(int i = 0;i<size;i++){
        if(numptr[i] == val){
            printf(" %d", i);
        }
    }

}