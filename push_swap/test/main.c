#include "sort_program.h"
#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sa(int* a, int size_a) {
    if (size_a >= 2) {
        swap(&a[0], &a[1]);
    }
}

void sb(int* b, int size_b) {
    if (size_b >= 2) {
        swap(&b[0], &b[1]);
    }
}

void ss(int* a, int size_a, int* b, int size_b) {
    sa(a, size_a);
    sb(b, size_b);
}

void pa(int* a, int* size_a, int* b, int* size_b) {
    if (*size_b > 0) {
        swap(&a[*size_a], &b[0]);
        (*size_a)++;
        (*size_b)--;
    }
}

void pb(int* a, int* size_a, int* b, int* size_b) {
    if (*size_a > 0) {
        swap(&b[*size_b], &a[0]);
        (*size_b)++;
        (*size_a)--;
    }
}

void ra(int* a, int size_a) {
    if (size_a >= 2) {
        int temp = a[0];
        for (int i = 0; i < size_a - 1; i++) {
            a[i] = a[i + 1];
        }
        a[size_a - 1] = temp;
    }
}

void rb(int* b, int size_b) {
    if (size_b >= 2) {
        int temp = b[0];
        for (int i = 0; i < size_b - 1; i++) {
            b[i] = b[i + 1];
        }
        b[size_b - 1] = temp;
    }
}

void rr(int* a, int size_a, int* b, int size_b) {
    ra(a, size_a);
    rb(b, size_b);
}

void rra(int* a, int size_a) {
    if (size_a >= 2) {
        int temp = a[size_a - 1];
        for (int i = size_a - 1; i > 0; i--) {
            a[i] = a[i - 1];
        }
        a[0] = temp;
    }
}

void rrb(int* b, int size_b) {
    if (size_b >= 2) {
        int temp = b[size_b - 1];
        for (int i = size_b - 1; i > 0; i--) {
            b[i] = b[i - 1];
        }
        b[0] = temp;
    }
}

void rrr(int* a, int size_a, int* b, int size_b) {
    rra(a, size_a);
    rrb(b, size_b);
}

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

void sortArray(int* arr, int size) {
    int* a = (int*)malloc(size * sizeof(int));
    int* b = (int*)malloc(size * sizeof(int));
    int size_a = 0;
    int size_b = 0;

    for (int i = 0; i < size; i++) {
        b[size_b] = arr[i];
        size_b++;
    }

    int actionCount = 0;

    while (size_b > 0) {
        int currentNum = b[size_b - 1];

        if (size_a > 0 && a[size_a - 1] < currentNum) {
            pa(a, &size_a, b, &size_b);
        } else {
            ra(a, size_a);
            actionCount++;

            if (actionCount > 2 * size) {
                rrr(a, size_a, b, size_b);
                actionCount = 0;
            }
        }
    }

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    free(a);
    free(b);
}
