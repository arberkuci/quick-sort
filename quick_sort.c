#include <stdio.h>

//Function declarations.
void quickSort(int size, int *elements);

void quickSortRecursion(int size, int *elements, int low, int high);

int partition(int size, int elements[size], int low, int high);

void quickSort(int size, int *elements) {
    quickSortRecursion(size, elements, 0, size - 1);
}

//Function definitions.
void quickSortRecursion(int size, int *elements, int low, int high) {
    if (low < high) {
        int pivotIdx = partition(size, elements, low, high);
        quickSortRecursion(size, elements, low, pivotIdx - 1);
        quickSortRecursion(size, elements, pivotIdx + 1, high);
    }
}

int partition(int size, int elements[size], int low, int high) {
    //The element around which the partitioning is done.
    int pivotElement = elements[high];
    // [0, smallerThanIdx] is the range of the number that
    // are smaller than the pivot elements
    int smallerThanIdx = low - 1;
    int greaterThanIdx = low;
    while (greaterThanIdx < high) {
        if (elements[greaterThanIdx] < pivotElement) {
            smallerThanIdx++;
            //swap elements in index smallerThanIdx with greaterThanIdx
            int temp = elements[smallerThanIdx];
            elements[smallerThanIdx] = elements[greaterThanIdx];
            elements[greaterThanIdx] = temp;
        }
        greaterThanIdx++;
    }
    //Swap the leftmost element of the elements that are greater than the pivot
    // with the pivot, putting so the pivot to it's position.
    int temp = elements[high];
    elements[high] = elements[smallerThanIdx + 1];
    elements[smallerThanIdx + 1] = temp;
    return smallerThanIdx + 1;
}

//Application

#define N 20

int main(void) {
    int elements[N];
    printf("Please enter %d numbers: ", N);
    for (int i = 1; i <= 20; i++) scanf("%d", &elements[i - 1]);

    quickSort(N, elements);
    for (int i = 0; i < N; i++) printf("%d ", elements[i]);
    return 0;
}
