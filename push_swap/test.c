/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsa-port <vsa-port@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 14:45:08 by vsa-port          #+#    #+#             */
/*   Updated: 2023/02/09 16:03:30 by vsa-port         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MIN(a, b) ((a) < (b) ? (a) : (b))

void insertion_sort(int *arr, int left, int right) {
    int i, j;
    for (i = left + 1; i <= right; i++) {
        int key = arr[i];
        for (j = i - 1; j >= left && arr[j] > key; j--) {
            arr[j + 1] = arr[j];
        }
        arr[j + 1] = key;
    }
}

void merge(int *arr, int l, int m, int r) {
    int len1 = m - l + 1, len2 = r - m;
    int left[len1], right[len2];
    int i, j, k;
    for (i = 0; i < len1; i++) {
        left[i] = arr[l + i];
    }
    for (j = 0; j < len2; j++) {
        right[j] = arr[m + 1 + j];
    }
    i = 0;
    j = 0;
    k = l;
    while (i < len1 && j < len2) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }
    while (i < len1) {
        arr[k] = left[i];
        i++;
        k++;
    }
    while (j < len2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void timsort(int *arr, int n) {
    int size, i;
    int stack[n];
    int top = -1;
    for (i = 0; i < n;) {
        if (top == -1 || arr[stack[top]] >= arr[i]) {
            stack[++top] = i++;
        } else {
            size = stack[top--];
            int mid = stack[top];
            merge(arr, mid, size, i - 1);
        }
    }
    while (top > 0) {
        size = stack[top--];
        int mid = stack[top];
        merge(arr, mid, size, n - 1);
    }
}

int main()
{
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    timsort(arr, n);
    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}