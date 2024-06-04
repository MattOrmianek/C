#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int size;
} MyArray;

// Function to initialize the array
void initArray(MyArray *arr, int size) {
    arr->array = (int *)malloc(size * sizeof(int));
    if (arr->array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    arr->size = size;
}

// Function to free the array memory
void freeArray(MyArray *arr) {
    free(arr->array);
    arr->array = NULL;  // Avoid dangling pointer
    arr->size = 0;
    printf("\n");
}

// Function to set an element in the array
void setElement(MyArray *arr, int index, int value) {
    if (index >= 0 && index < arr->size) {
        arr->array[index] = value;
    } else {
        fprintf(stderr, "Index out of bounds\n");
    }
}

// Function to get an element from the array
int getElement(MyArray *arr, int index) {
    if (index >= 0 && index < arr->size) {
        return arr->array[index];
    }
    fprintf(stderr, "Index out of bounds\n");
    return -1; // or handle error
}

// Function to print array elements and their memory addresses
void printElements(MyArray *arr) {
    for (int i = 0; i < arr->size; i++) {
        printf("(Address: %p) Element at index %d: %d\n", (void*)&arr->array[i], i, arr->array[i]);
    }
}

// Function to print the size of the array in bytes
void printSize(MyArray *arr) {
    printf("Size of MyArray in bytes: %lu bytes\n", sizeof(int) * arr->size);
}

// Function to print individual bytes of the array elements
void printBytes(MyArray *arr) {
    unsigned char *bytePtr = (unsigned char*)arr->array;
    for (int i = 0; i < arr->size; i++) {
        printf("Element %d bytes: ", i);
        for (int j = sizeof(int) - 1; j >= 0; j--) {
            printf("%02x ", bytePtr[i * sizeof(int) + j]);
        }
        printf("\n");
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


    initArray(&numbers, size_of_numbers);
    setElement(&numbers, 1, 1);
    printElements(&numbers);
    printSize(&numbers);
    printBytes(&numbers);
    freeArray(&numbers);


    MyArray numbers_but_with_more_values;
    initArray(&numbers_but_with_more_values, 5);
    setElement(&numbers_but_with_more_values, 0, 0);
    setElement(&numbers_but_with_more_values, 1, 1);
    setElement(&numbers_but_with_more_values, 2, 2);
    setElement(&numbers_but_with_more_values, 3, 3);
    setElement(&numbers_but_with_more_values, 4, 4);
    printElements(&numbers_but_with_more_values);
    printSize(&numbers_but_with_more_values);
    printBytes(&numbers_but_with_more_values);
    freeArray(&numbers_but_with_more_values);

    return 0;
}
