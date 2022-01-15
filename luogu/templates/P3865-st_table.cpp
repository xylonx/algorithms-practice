#include <iostream>
#include <vector>

const int log2n = 21;
const int maxn  = 2000001;

class RMQ {
private:
    int f[maxn][log2n];
    int log[maxn];

public:
    RMQ(std::vector<int> arr) {
        memset(f, 0, sizeof(f));
        memset(log, 0, sizeof(log));
        pre_process(arr);
    };

    void pre_process(std::vector<int> arr) {
        log[1] = 0;
        log[2] = 1;
        for (int i = 3; i < maxn; ++i) log[i] = log[i >> 1] + 1;

        for (int i = 0; i < arr.size(); ++i) f[arr[i]][0] = arr[i];

        // calculate f
        for (int j = 1; j <= log2n; ++j) {
            for (int i = 1; i + (1 << j) - 1 <= maxn; ++i) {
                f[i][j] = std::max(f[i][j - 1], f[i + (1 << (j - 1))][j]);
            }
        }
    }

    int query(int l, int r) {
        int s = log[r - l + 1];
        return std::max(f[l][s], f[r - (1 << s) + 1][s]);
    }
};