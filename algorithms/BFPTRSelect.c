#include <stdio.h>
#include <stdlib.h>

void exchange(int *array, int i, int j);

int medianSelect5Index(int *array, int start, int end);

int getMedianOfMedianIndex(int *array, int start, int end);

int partition(int *array, int start, int end);

int BFPTRPartition(int *array, int start, int end);

int BFPTRSelectIndex(int *array, int start, int end, int k);

int BFPTRSelect(int *array, int start, int end, int k);

int main(int argc, char *argv[]) { 
    int array[10] = {15, 835, 83, 28, 266, 287, 86, 23, 7, 66};

    printf("%d\n", BFPTRSelect(array, 0 , 9 , 3));
    
    return 0; 
}

//////////////////////////////////////
/////////  Implementation  ///////////
//////////////////////////////////////

void exchange(int *array, int i, int j) {
    int tmp = array[i];
    array[i] = array[j];
    array[j] = tmp;
}

int medianSelect5Index(int *array, int start, int end) {
    if (start == end) {
        return start;
    }

    for (int i = start; i <= end; i++) {
        int minElement = array[i];
        int minIndex = i;
        for (int j = i; j <= end; j++) {
            if (array[j] < minElement) {
                minIndex = j;
                minElement = array[j];
            }
        }
        exchange(array, i, minIndex);
    }

    return (start + end) / 2;
}

int getMedianOfMedianIndex(int *array, int start, int end) {
    if (end - start < 5) {
        return medianSelect5Index(array, start, end);
    }

    // get each median of 5 number and make them together in front of the array
    for (int i = start; i <= end; i += 5) {
        int subEnd = i + 4;
        if (subEnd > end) {
            subEnd = end;
        }

        int media = medianSelect5Index(array, start, subEnd);
        exchange(array, media, start + (i / 5));
    }

    // medianNum is the upper bound of the `(end - start + 1) / 5`
    int medianNum;
    if ((end - start + 1) % 5 == 0) {
        medianNum = (end - start + 1) / 5;
    } else {
        medianNum = (end - start + 1) / 5 + 1;
    }

    int medianEnd = start + medianNum - 1;

    // by mutual recursion, get the median index of the medians
    return BFPTRSelectIndex(array, start, medianEnd, medianNum / 2);
}

int partition(int *array, int start, int end) {
    int pivot = array[end];
    int pivotPosition = 0;
    for (int i = 0; i < end - start + 1; i++) {
        if (array[i] < pivot) {
            exchange(array, i, pivotPosition);
            pivotPosition++;
        }
    }
    exchange(array, end, pivotPosition);
    return pivotPosition;
}

int BFPTRPartition(int *array, int start, int end) {
    int medianOfMedianIndex = getMedianOfMedianIndex(array, start, end);
    exchange(array, end, medianOfMedianIndex);
    return partition(array, start, end);
}

int BFPTRSelectIndex(int *array, int start, int end, int k) {
    if (start == end) {
        return start;
    }

    int pivotIndex = BFPTRPartition(array, start, end);

    int nthMin = pivotIndex - start + 1;

    if (nthMin == k) {
        return pivotIndex;
    } else if (nthMin > k) {
        return BFPTRSelectIndex(array, start, pivotIndex - 1, k);
    } else {
        return BFPTRSelectIndex(array, pivotIndex + 1, end, k - nthMin);
    }
}

int BFPTRSelect(int *array, int start, int end, int k) {
    return array[BFPTRSelectIndex(array, start, end, k)];
}