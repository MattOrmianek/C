#include <stdio.h>

int main() {
    const int size_of_array = 5;
    int my_array[size_of_array] = {1, 2, 3, 4, 5};

    for (int i = 0; i < size_of_array; i++) {
        printf("(Address: %p) Element at index %d: %d\n", (void*)&my_array[i], i, my_array[i]);
    }

    int *weird_element = &my_array[1];
    printf("Weird element value: %d\n", *weird_element);
    printf("Weird element pointer address: %p, value at this address: %d\n", (void*)weird_element, *weird_element);

    int *another_weird_element = &my_array[1];
    printf("Another weird element value: %d\n", *another_weird_element);
    printf("Another weird element pointer address: %p, value at this address: %d\n", (void*)another_weird_element, *another_weird_element);
    return 0;
}
