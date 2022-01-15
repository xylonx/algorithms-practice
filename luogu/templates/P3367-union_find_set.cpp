#include <cstring>
#include <iostream>

class UnionFindSet {
private:
    int f[1001], rank[1002];

public:
    int find(int x) {
        while (x != f[x]) {
            x    = f[x];
            f[x] = f[f[x]];
        };
        return x;
    }

    void merge(int x, int y) {
        int xf = find(x), yf = find(y);
        if (rank[x] > rank[y]) {
            f[yf] = xf;
            rank[xf] += rank[yf];
        } else {
            f[xf] = yf;
            rank[yf] += rank[xf];
        }
    }

    UnionFindSet() {
        for (int i = 0; i < 1002; ++i) {
            f[i]    = i;
            rank[i] = 1;
        }
    }
};

int main(int argc, char** argv) { return 0; }