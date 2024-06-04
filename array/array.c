#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;
} MyArray;

// Function to initialize the array
void initArray(MyArray *arr, int size) {
    arr->array = (int *)malloc(size * sizeof(int));
    arr->size = size;
}

// Function to free the array memory
void freeArray(MyArray *arr) {
    free(arr->array);
}

// Function to set an element in the array
void setElement(MyArray *arr, int index, int value) {
    if (index >= 0 && index < arr->size) {
        arr->array[index] = value;
    }
}

// Function to get an element from the array
int getElement(MyArray *arr, int index) {
    if (index >= 0 && index < arr->size) {
        return arr->array[index];
    }
    return -1; // or handle error
}

// Function to print array elements and their memory addresses
void printElements(MyArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("(Address: %p) Element at index %d: %d \n", (void*)&arr->array[i], i, arr->array[i]);
    }
}

// Function to print the size of the array in bytes
void printSize(MyArray *arr) {
    printf("Size of MyArray in bytes: %lu bytes\n", sizeof(int) * arr->size);
}

// Function to print individual bytes of the array elements
void printBytes(MyArray *arr) {
    unsigned char *bytePtr = (unsigned char*)arr->array;
    for (int i = 0; i < sizeof(int) * arr->size; i++) {
        if (i % 4 == 0){
            printf("Bytes: ");
        }
        printf(" %d: %02x ", i, bytePtr[i]);
        if (i % 4 == 3){
            printf("\n");
        }
    }
}

int main() {
    const int size_of_numbers = 2;

    MyArray numbers;
    initArray(&numbers, size_of_numbers);
    setElement(&numbers, 0, 999999999);
    printElements(&numbers);
    printSize(&numbers);
    printBytes(&numbers);
    freeArray(&numbers);

    printf("\n");
    setElement(&numbers, 1, 1);
    printElements(&numbers);
    printSize(&numbers);
    printBytes(&numbers);



    return 0;
}
