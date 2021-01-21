#include <bits/stdc++.h>

using namespace std;

// for any sequence like `s1 s2 ... s_{p-1} sp s_{p-1} ... s2 s1
// the number of inversions of it is fixed regardless of what s_{i} are.
// for each pair(the s_{i} in left and right), thay are like x...y...y...x  or
// x...y...x for first case, either x < y or x > y, there are 2 inversions for
// second case, either x < y or x > y, there are 1 inversion so the number of
// inversions of the sequence is C_{p-1}^{2} + (p-1) = (p-1)^2
//
// for array b, there is value map below:
// b1 b2 b3 b4 ... p_{k-(n-k)} ... bk ... b_{k+(n-k)}
// p1 p2 p3 p4 ... p_{k-(n-k)} ... pk ... p_{k-(n-k)}
//
// so for array a, b, assuming m = n-k, they can be both devided into 2
// parts(for index): [1, k-m-1] and [k-m, k+m]. the second parts both in a and b
// are exactly the sequence desribed above. so the number of inversions consists
// of the number of inversions in the first part, in the second part and the
// inversions with elements from both parts.
//
// for array a, the number of inversions in the first part and the inversions
// with elements from both parts are 0
// so for array b, the number of inversions in the first part and the inversions
// with elements from both parts must be 0
// that means the array p must start from `1 2 3 ... (k-m-1)`
// to maximize lexicograpghic,
// the second part must be `k (k-1) ... (k-m) ... (k-1) k`

int main(int argc, char* argv[]) {
    int t, n, k;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        int m = n - k;
        for (int i = 1; i <= k - m - 1; i++) {
            cout << i << " ";
        }
        for (int i = k; i >= k - m; i--) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}