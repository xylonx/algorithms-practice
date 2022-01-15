#include <iostream>
#include <string>

class QuickSort {
public:
    void Sort(int *a, int n) {
        if (!a || n <= 1) return;
        return quickSort(a, 0, n - 1);
    }

private:
    int threshold = 10;
    // asc
    void insertSort(int *a, int left, int right) {
        for (int i = left; i <= right; ++i) {
            int min = a[i], min_idx = i;
            for (int j = i + 1; j <= right; ++j) {
                if (a[j] < min) min = a[j], min_idx = j;
            }
            std::swap(a[i], a[min_idx]);
        }
    }

    void quickSort(int *a, int left, int right) {
        if (left >= right) return;

        if (right - left + 1 < threshold) return insertSort(a, left, right);

        int i = left, j = right, p = rand() % (right - left + 1) + left;
        std::swap(a[p], a[j]);
        while (i < j) {
            while (i < j && a[i] <= a[right]) i++;
            while (i < j && a[j] >= a[right]) j--;
            if (i == j) {
                std::swap(a[i], a[right]);
            } else {
                std::swap(a[i], a[j]);
            }
        }

        quickSort(a, left, i - 1);
        quickSort(a, i + 1, right);
    }
};

int main(int argc, char **argv) {
    std::ios::sync_with_stdio(false);

    int       a[] = {4, 2, 4, 5, 1};
    QuickSort q;
    q.Sort(a, 5);
    for (auto x : a) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
}