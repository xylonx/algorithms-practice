#include <bits/stdc++.h>

using namespace std;

// start from 1-color, each time add 1 another color for a single edge until to
// n-1-color. each time adding an edge,
// it means there is a weight of vertix added twice.
// so for each vectices whose degree is larger equal than 2,
// adding max of them once until its degree is smaller than 2
int main(int argc, char *argv[]) {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        long long weight[n + 1];
        map<int, int> vertixDegree;
        int u, v;
        for (int i = 1; i <= n; i++) {
            cin >> weight[i];
        }
        for (int i = 0; i < n - 1; i++) {
            cin >> u >> v;
            vertixDegree[u] += 1;
            vertixDegree[v] += 1;
        }

        priority_queue<long long> weightWithMultiDegree;
        map<int, int>::iterator it = vertixDegree.begin();
        while (it != vertixDegree.end()) {
            for (int i = 1; i < it->second; i++) {
                weightWithMultiDegree.push(weight[it->first]);
            }
            it++;
        }

        long long maxValue = 0;
        for (int i = 1; i <= n; i++) {
            maxValue += weight[i];
        }

        cout << maxValue << " ";
        for (int i = 1; i < n - 1; i++) {
            maxValue += weightWithMultiDegree.top();
            weightWithMultiDegree.pop();
            cout << maxValue << " ";
        }
        cout << endl;
    }

    return 0;
}