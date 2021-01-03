#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exchange(int *array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

int partition(int *array, int p, int r) {
    int pivot = array[r];
    int pivotPosition = 0;
    for (int i = 0; i < r - p + 1; i++) {
        if (array[i] < pivot) {
            exchange(array, i, pivotPosition);
            pivotPosition++;
        }
    }
    exchange(array, r, pivotPosition);
    return pivotPosition;
}

int randomizePartition(int *array, int p, int r) {
    srand(time(NULL));
    int x = rand() % (r - p + 1) + p;
    exchange(array, x, r);
    return partition(array, p, r);
}

int randomizeSelect(int *array, int p, int r, int i) {
    if (p == r) return array[r];

    // k means the position of pivot in the array
    int k = randomizePartition(array, p, r);
    // nthMin means pivot is the n-th minimum of the array[p..r]
    int nthMin = k - p + 1;
    if (nthMin == i) {
        return array[k];
    }

    if (nthMin > i) {
        return randomizeSelect(array, p, k - 1, i);
    } else {
        return randomizeSelect(array, k + 1, r, i - nthMin);
    }
}

int main(int argc, char *argv[]) {
    int array[10] = {15, 835, 83, 28, 266, 287, 86, 23, 7, 66};

    printf("3th big: %d\n", randomizeSelect(array, 0, 9, 3));

    return 0;
}