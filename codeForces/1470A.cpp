#include <bits/stdc++.h>

using namespace std;

// for those larger k[i], it means the cost[k[i]] is also larger.
// so the best way is to give them smaller cost present.
// then give smaller k[i] cost[k[i]] money.
int main(int argc, char* argv[]) {
    int t, m, n;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int k[n];
        long long cost[m + 1];
        for (int i = 0; i < n; i++) {
            cin >> k[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> cost[i];
       }
        sort(k, k + n);

        long long totalCost = 0;
        for (int i = n - 1, j = 1; i >= 0; i--) {
            // because the cost is already ordered
            // so if k[i] > j, it means cost[k[i]] > cost[j]
            if (k[i] > j) {
                totalCost += cost[j];
                j++;
            } else {
                totalCost += cost[k[i]];
            }
        }

        cout << totalCost << endl;
    }

    return 0;
}