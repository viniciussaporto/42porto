#include "sort_program.h"
#include <stdio.h>
#include <stdlib.h>

// Function to swap two integers
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform "sa" action
void sa(int* a, int size_a) {
    if (size_a >= 2) {
        swap(&a[0], &a[1]);
    }
}

// Function to perform "sb" action
void sb(int* b, int size_b) {
    if (size_b >= 2) {
        swap(&b[0], &b[1]);
    }
}

// Function to perform "ss" action
void ss(int* a, int size_a, int* b, int size_b) {
    sa(a, size_a);
    sb(b, size_b);
}

// Function to perform "pa" action
void pa(int* a, int* size_a, int* b, int* size_b) {
    if (*size_b > 0) {
        swap(&a[*size_a], &b[0]);
        (*size_a)++;
        (*size_b)--;
    }
}

// Function to perform "pb" action
void pb(int* a, int* size_a, int* b, int* size_b) {
    if (*size_a > 0) {
        swap(&b[*size_b], &a[0]);
        (*size_b)++;
        (*size_a)--;
    }
}

// Function to perform "ra" action
void ra(int* a, int size_a) {
    if (size_a >= 2) {
        int temp = a[0];
        for (int i = 0; i < size_a - 1; i++) {
            a[i] = a[i + 1];
        }
        a[size_a - 1] = temp;
    }
}

// Function to perform "rb" action
void rb(int* b, int size_b) {
    if (size_b >= 2) {
        int temp = b[0];
        for (int i = 0; i < size_b - 1; i++) {
            b[i] = b[i + 1];
        }
        b[size_b - 1] = temp;
    }
}

// Function to perform "rr" action
void rr(int* a, int size_a, int* b, int size_b) {
    ra(a, size_a);
    rb(b, size_b);
}

// Function to perform "rra" action
void rra(int* a, int size_a) {
    if (size_a >= 2) {
        int temp = a[size_a - 1];
        for (int i = size_a - 1; i > 0; i--) {
            a[i] = a[i - 1];
        }
        a[0] = temp;
    }
}

// Function to perform "rrb" action
void rrb(int* b, int size_b) {
    if (size_b >= 2) {
        int temp = b[size_b - 1];
        for (int i = size_b - 1; i > 0; i--) {
            b[i] = b[i - 1];
        }
        b[0] = temp;
    }
}

// Function to perform "rrr" action
void rrr(int* a, int size_a, int* b, int size_b) {
    rra(a, size_a);
    rrb(b, size_b);
}

// Function to print the containers
void printContainers(int* a, int size_a, int* b, int size_b) {
    printf("Container A: ");
    for (int i = 0; i < size_a; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    printf("Container B: ");
    for (int i = 0; i < size_b; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");
}

// Function to sort the array using the provided actions
void sortArray(int* arr, int size) {
    int* a = (int*)malloc(size * sizeof(int));
    int* b = (int*)malloc(size * sizeof(int));
    int size_a = 0;
    int size_b = 0;

    // Copy the array to container a
    for (int i = 0; i < size; i++) {
        a[i] = arr[i];
        size_a++;
    }

    // Sort the array using insertion sort algorithm
    for (int i = 1; i < size; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
    }

    // Perform the required actions to sort the array
    int actionCount = 0;
    while (size_b < size) {
        if (size_a > 0 && a[0] == arr[size_b]) {
            pa(a, &size_a, b, &size_b);
        } else if (size_a > 1 && a[1] == arr[size_b]) {
            sa(a, size_a);
            pa(a, &size_a, b, &size_b);
        } else {
            ra(a, size_a);
        }

        actionCount++;

        if (actionCount > 2 * size) {
            // If the actions exceed 2 times the size, use the rr action
            rrr(a, size_a, b, size_b);
            actionCount = 0;
        }
    }

    // Print the sorted array
    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", b[i]);
    }
    printf("\n");

    // Free the dynamically allocated memory
    free(a);
    free(b);
}

int main(int argc, char* argv[]) {
    if (argc <= 1) {
        printf("Usage: ./sort_program <element1> <element2> ... <elementN>\n");
        return 0;
    }

    int size = argc - 1;
    int* arr = (int*)malloc(size * sizeof(int));

    for (int i = 1; i < argc; i++) {
        arr[i - 1] = atoi(argv[i]);
    }

    sortArray(arr, size);

    free(arr);
    return 0;
}
